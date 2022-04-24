#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool check(vector<string> places,int col, int row,bool d[][5],int distance){
    
    d[row][col]=1;

    if(distance>2){
        return 1;
    }
    if(distance!=0&&places[row][col] == 'P'){
        return 0;
    }

    int nextCol;
    int nextRow;
    for(int i=0;i<4;i++){
        nextCol = col + dx[i];
        nextRow = row + dy[i];
        if(nextCol>=0 && nextRow>=0 &&nextCol<5 &&nextRow<5 &&!d[nextRow][nextCol]&&places[nextRow][nextCol]!='X'){
            if(!check(places,nextCol,nextRow,d,distance+1)) return 0;
            d[nextRow][nextCol] = 0;
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i=0;i<places.size();i++){
        bool flag = 1;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k]=='P'){
                    bool d[5][5]={0,};
                    if(!check(places[i],k,j,d,0)) flag = 0;
                }
            }
        }
        answer.push_back(flag);
    }
    return answer;
}

int main(){
    vector<vector<string>> places;
    places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> answer = solution(places);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}