#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct raceway{
    int row;
    int col;
    int d;

    raceway(int row,int col, int d) : row(row),col(col),d(d){}
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    int MIN = 25*25*500;

    int cnt[25][25][4];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<4;k++){
                cnt[i][j][k] = MIN;
            }
        }
    }

    cnt[0][0][0] = 0;
    cnt[0][0][1] = 0;
    cnt[0][0][2] = 0;
    cnt[0][0][3] = 0;
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    queue<raceway> q;
    q.push(raceway(0,0,0));
    q.push(raceway(0,0,1));
    q.push(raceway(0,0,2));
    q.push(raceway(0,0,3));

    while(!q.empty()){
        raceway curr = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nextCol = curr.col + dx[i];
            int nextRow = curr.row + dy[i];
            
            int nextCnt = cnt[curr.row][curr.col][curr.d] + 100;
            if(curr.d != i) nextCnt += 500;

            if(nextCol<0 || nextRow<0 || nextCol >= size || nextRow >= size || board[nextRow][nextCol] == 1 ||cnt[nextRow][nextCol][i] < nextCnt ) continue;
            cnt[nextRow][nextCol][i] = nextCnt;
            q.push(raceway(nextRow,nextCol,i));

        }
    }

    answer = MIN;
    for(int i=0;i<4;i++){
        if(answer>cnt[size-1][size-1][i]) answer = cnt[size-1][size-1][i];
    }
    
    return answer;
}

int main(){
    vector<vector<int>> board={{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
    // vector<vector<int>> board = {{0,1},{0,0}};
    cout<<solution(board);
}