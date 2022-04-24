#include <iostream>
#include <vector>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> board;
    vector<int> board_c;

    for(int i=0;i<m+1;i++){
        board_c.push_back(0);
    }
    for(int i=0;i<n+1;i++){
        board.push_back(board_c);
    }

    for(int i=0;i<puddles.size();i++){
        board[puddles[i][1]][puddles[i][0]] = -1;
    }

    board[1][1] = 1;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(board[i][j] == -1) continue;
            if(i==1 && j==1) continue;
            int a = board[i-1][j];
            int b = board[i][j-1];
            if(a == -1) a = 0;
            if(b == -1) b = 0;
            board[i][j] = a + b;
        }
    }

    answer = board[n][m] % 1000000007;
    return answer;
}

int main(){
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2,2}};
    cout<<solution(m,n,puddles);
}