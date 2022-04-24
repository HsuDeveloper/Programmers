#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool v[500][500][4];

int maxR,maxC;

vector<string> grid_c;
vector<int> cycle;

int changeL(int d){
    switch(d){
        case 0:
        return 2;
        case 1:
        return 3;
        case 2:
        return 1;
        case 3:
        return 0;
    }
}

int changeR(int d){
    switch(d){
        case 0:
        return 3;
        case 1:
        return 2;
        case 2:
        return 0;
        case 3:
        return 1;
    }
}

void dfs(int row,int col,int d,int distance){
    if(v[row][col][d]){
        if(distance != 0){
            cycle.push_back(distance);
            return;
        }
        return;
    }

    v[row][col][d] = 1;

    int nextRow,nextCol,nowD;

    char c = grid_c[row][col];
    
    if(c == 'L') nowD = changeL(d);
    else if(c == 'R') nowD = changeR(d);
    else nowD = d;
    
    nextRow = row + dy[nowD];
    nextCol = col + dx[nowD];

    if(nextRow < 0) nextRow = maxR - 1;
    else if(nextRow >= maxR) nextRow = 0;
    else if(nextCol < 0) nextCol = maxC - 1;
    else if(nextCol >= maxC) nextCol = 0;

    dfs(nextRow, nextCol, nowD, distance+1);

}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    grid_c = grid;
    maxR = grid.size();
    maxC = grid[0].size();
    
    for(int i=0;i<maxR;i++){
        for(int j=0;j<maxC;j++){
            for(int d=0;d<4;d++){
                dfs(i,j,d,0);
            }
        }
    }

    sort(cycle.begin(),cycle.end());
    answer = cycle;

    return answer;
}

int main(){
    vector<string> grid = {"R","R"};
    vector<int> answer = solution(grid);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}