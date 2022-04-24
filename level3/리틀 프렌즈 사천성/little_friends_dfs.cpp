#include<iostream>
#include<vector>
#include<map>

using namespace std;



// m == board.size()
bool dfs(int m,int n,vector<string> &board ,int row,int col,char c,int d,int cnt,bool v[][100]){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    bool flag = 0;
    
    v[row][col] = 1;

    if(d!=-1 && board[row][col] == c){
        board[row][col] = '.';
        return 1;
    }

    for(int i=0;i<4;i++){
        int nextRow = row+dy[i];
        int nextCol = col+dx[i];
        int nextCnt = cnt;
        if(nextRow<0 || nextRow>=m || nextCol<0 || nextCol>=n || v[nextRow][nextCol]) continue;
        if(board[nextRow][nextCol]!=c && board[nextRow][nextCol]!='.') continue;
        
        if(d!=-1 && d!=i) nextCnt++;
        if(nextCnt>1) continue;

        if(dfs(m,n,board,nextRow,nextCol,c,i,nextCnt,v)) flag = 1;
        v[nextRow][nextCol] = 0;

    }
    return flag;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";

    map<char,pair<int,int>> m_char;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char c = board[i][j];
            if(c>='A' && c<='Z'){
                m_char[c] = make_pair(i,j);
            }
        }
    }
    
    while(1){
        bool isFinish = 1;
        for(auto iter = m_char.begin();iter!=m_char.end();iter++){
            int row = iter->second.first;
            int col = iter->second.second;
            char c = iter->first;
            bool v[100][100] = {0,};
            
            if(dfs(m,n,board,row,col,c,-1,0,v)){
                board[row][col] = '.';
                answer += c;
                m_char.erase(c);
                isFinish = 0;
                break;
            }
    
        }
        if(m_char.size() == 0) break;
        if(isFinish) return "IMPOSSIBLE";
    }
    
    return answer;
}

int main(){
    int m = 2;
    int n = 3;
    vector<string> board={"ABA","CBC"};
    // vector<string> board={"DBA", "C*A", "CDB"};
    // vector<string> board = {".ZI.", "M.**", "MZU.", ".IU."};
    // vector<string> board={"DBBD", "CB.A", "CDBA"};
    cout<<solution(m,n,board);
}