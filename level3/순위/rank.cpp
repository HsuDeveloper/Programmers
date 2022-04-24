#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool p[100][100] = {0,};

    for(int i=0;i<results.size();i++){
       p[results[i][0]-1][results[i][1]-1] = 1;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!p[i][j]){
                    if(p[i][k]&&p[k][j]) p[i][j]=1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(p[i][j]) cnt++;
            if(p[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }

    return answer;
}

int main(){
    int n = 5;
    vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};

    cout<< solution(n,results);
}