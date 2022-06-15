#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> land, int height, int size, int row, int col, vector<vector<int>> &land_sec, int num){
    land_sec[row][col] = num;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i=0;i<4;i++){
        int nextRow = row + dy[i];
        int nextCol = col + dx[i];

        if(nextRow<0 || nextRow>=size || nextCol<0 || nextCol>=size || land_sec[nextRow][nextCol]) continue;
        if(abs(land[row][col] - land[nextRow][nextCol]) > 3) continue;
        dfs(land,height,size,nextRow,nextCol,land_sec,num);
    }
}

void split_sec(vector<vector<int>> land, int height,int size, vector<vector<int>> &land_sec){
    int num = 1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(land_sec[i][j]) continue;
            dfs(land,height,size,i,j,land_sec,num);
            num++;
        }
    }
    cout<<num<<'\n';
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int size = land.size();
    vector<vector<int>> land_sec(size,vector<int>(size,0));

    split_sec(land,height,size,land_sec);

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<land_sec[i][j]<<' ';
        }
        cout<<'\n';
    }
    return answer;
}

int main(){
    vector<vector<int>> land = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
    int height = 3;

    cout<<solution(land,height);
}