#include <iostream>
#include <vector>

using namespace std;

// time out

int dx[2] = {1,0};
int dy[2] = {0,1};

long long cnt=0;
void dfs(int m,int n,int col,int row,vector<vector<bool>> board){

    if(col == m-1 && row == n-1){
        cnt++;
        return;
    }

    int nextC,nextR;
    for(int i=0;i<2;i++){
        nextC = col + dx[i];
        nextR = row + dy[i];
        if(nextC < m && nextR < n && board[nextR][nextC]){
            dfs(m,n,nextC,nextR,board);
        }
    }

    return;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<bool>> board;
    vector<bool> board_c;
    for(int i=0;i<m;i++){
        board_c.push_back(1);
    }
    for(int i=0;i<n;i++){
        board.push_back(board_c);
    }

    for(int i=0;i<puddles.size();i++){
        board[puddles[i][1]-1][puddles[i][0]-1] = 0;
    }

    dfs(m,n,0,0,board);
    answer = cnt % 1000000007;
    return answer;
}

int main(){
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2,2}};
    cout<<solution(m,n,puddles);
}