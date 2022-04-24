#include<iostream>
#include <vector>

using namespace std;

// Time out

int MOD = 20170805;

void dfs(int row,int col,int m,int n,vector<vector<int>> city_map,int &answer,int d){
    if(row==m-1 && col==n-1) {
        answer = (answer + 1)%MOD;
        return;
    }

    int dx[2]={1,0};
    int dy[2]={0,1};
    
    int nextCol;
    int nextRow;
    
    if(city_map[row][col] == 2){
        nextCol = col + dx[d];
        nextRow = row + dy[d];

        if(nextCol<0 || nextRow<0 || nextCol>=n || nextRow >=m || city_map[nextRow][nextCol]==1) return;
        
        dfs(nextRow,nextCol,m,n,city_map,answer,d);
        
        return;
    }

    for(int i=0;i<2;i++){
        nextCol = col + dx[i];
        nextRow = row + dy[i];
        
        if(nextCol<0 || nextRow<0 || nextCol>=n || nextRow >=m || city_map[nextRow][nextCol]==1) continue;
        dfs(nextRow,nextCol,m,n,city_map,answer,i);

    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    dfs(0,0,m,n,city_map,answer,-1);

    return answer;
}

int main(){
    // int m=3;
    // int n=6;
    // vector<vector<int>> city_map={{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};

    int m=3;
    int n=3;
    vector<vector<int>> city_map = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    cout<<solution(m,n,city_map);
}