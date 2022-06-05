#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(vector<vector<int>> &coordinate, vector<vector<bool>> d, int row, int col, int itemX,int itemY, int cnt){
    if((row==itemY) && (col==itemX)) {
        if(coordinate[row][col] > cnt) coordinate[row][col] = cnt;
        return;    
    }

    for(int i=0;i<4;i++){
        int nextRow = row + dy[i];
        int nextCol = col + dx[i];

        if(nextRow<0||nextRow>100||nextCol<0||nextCol>100||d[nextRow][nextCol]||coordinate[nextRow][nextCol]==-1||!coordinate[nextRow][nextCol]) continue;
        d[nextRow][nextCol] = 1;
        dfs(coordinate,d,nextRow,nextCol,itemX,itemY,cnt+1);
        d[nextRow][nextCol] = 0;
        
    }

}

void draw(vector<int> &rec, vector<vector<int>> &coordinate){
    for(int i= rec[0]; i<=rec[2];i++){
        if(coordinate[rec[1]][i] != -1) coordinate[rec[1]][i] = 1;
        if(coordinate[rec[3]][i] != -1) coordinate[rec[3]][i] = 1;
    }
    for(int i = rec[1]; i<=rec[3]; i++){
        if(coordinate[i][rec[0]] != -1) coordinate[i][rec[0]] = 1;
        if(coordinate[i][rec[2]] != -1) coordinate[i][rec[2]] = 1;
    }

    for(int i = rec[0]+1; i<rec[2]; i++){
        for(int j = rec[1]+1; j<rec[3]; j++){
            coordinate[j][i] = -1;
        }
    }

}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> coordinate(101,vector<int>(101,0));
    vector<vector<bool>> d(101,vector<bool>(101,0));

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    for(int i=0;i<rectangle.size();i++){
        rectangle[i][0] *= 2;
        rectangle[i][1] *= 2;
        rectangle[i][2] *= 2;
        rectangle[i][3] *= 2;
        draw(rectangle[i],coordinate);
    }

    coordinate[itemY][itemX] = 10001;
    dfs(coordinate,d,characterY,characterX,itemX,itemY,0);

    answer = coordinate[itemY][itemX]/2;

    return answer;
}

int main(){
    vector<vector<int>> rectangle={{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}};
    int characterX=1;
    int characterY=3;
    int itemX=7;
    int itemY=8;

    cout<<solution(rectangle,characterX,characterY,itemX,itemY);
}