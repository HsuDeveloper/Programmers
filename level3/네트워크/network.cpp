#include <iostream>
#include <vector>

using namespace std;

bool dfs(int n,int size, vector<vector<int>> &computers){
    if(!computers[n][n]) return 0;

    computers[n][n] = 0;

    for(int i=0;i<size;i++){
        if(computers[n][i]) dfs(i,size,computers);
    }

    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0;i<n;i++){
        if(dfs(i,n,computers)) answer++;
    }

    return answer;
}

int main(){
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout<< solution(n,computers);
}