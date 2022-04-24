#include <iostream>
#include <vector>

using namespace std;

bool check(int row,int col,int m,int n,vector<string> board){
    if(row > m-2 || col > n-2 || board[row][col] == '-') return 0;

    char c = board[row][col];
    if( board[row][col+1] == c && board[row+1][col] == c && board[row+1][col+1] == c) return 1;

    return 0;
}

void change(int row,int col,vector<string> &board){
    board[row][col] = '-';
    board[row+1][col] = '-';
    board[row][col+1] = '-';
    board[row+1][col+1] = '-';
}

void arrange(int m,int n, vector<string> &board){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[m-i-1][j]!='-') continue;

            int cnt = 0;
            bool flag = 1;
            while(board[m-i-1-cnt][j] == '-'){
                cnt++;
                if(m-i-1-cnt <0) {
                    flag=0;
                    break;
                }
            }
            if(flag){
                board[m-i-1][j] = board[m-i-1-cnt][j];
                board[m-i-1-cnt][j] = '-';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while(1){
        int cnt=0;
        vector<pair<int,int>> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(check(i,j,m,n,board)) {
                    v.push_back({i,j});
                    cnt++;
                }
            }
        }

        for(int i=0;i<v.size();i++){
            change(v[i].first,v[i].second,board);
        }

        arrange(m,n,board);

        if(!cnt) break;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == '-') answer++;
        }
    }

    return answer;
}

int main(){
    int m=6;
    int n=6;
    vector<string> board={"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};

    cout<<solution(m,n,board);
}