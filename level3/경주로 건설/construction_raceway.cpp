#include <iostream>
#include <vector>

using namespace std;

// DFS time out

void dfs(int row,int col,int d,int cnt,int dCnt,vector<vector<int>> board,int m,int cost[25][25][4]){

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i=0;i<4;i++){
        int nextCol = col + dx[i];
        int nextRow = row + dy[i];
        int next_dCnt = dCnt;
        int nextCnt = cnt;
        
        if(d != i && d != -1) next_dCnt++;
        nextCnt++;

        int r = 100*nextCnt + 500*next_dCnt;

        if(nextCol < 0 || nextRow < 0 || nextCol >= m || nextRow >= m || board[nextRow][nextCol]==1 || r > cost[nextRow][nextCol][i]) continue;
        cost[nextRow][nextCol][i] = r;
        dfs(nextRow,nextCol,i,nextCnt,next_dCnt,board,m,cost);

    }
    return;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    int MIN = 25*25*500;
    
    int cost[25][25][4];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<4;k++){
                cost[i][j][k] = MIN;
            }
        }
    }

    cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    cost[0][0][2] = 0;
    cost[0][0][3] = 0;

    dfs(0,0,-1,0,0,board,size,cost);
    answer = MIN;
    for(int i=0;i<4;i++){
        if(answer > cost[size-1][size-1][i]) answer = cost[size-1][size-1][i];
    }
    return answer;
}

int main(){
    vector<vector<int>> board={{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
    // vector<vector<int>> board = {{0,1},{0,0}};
    cout<<solution(board);
}