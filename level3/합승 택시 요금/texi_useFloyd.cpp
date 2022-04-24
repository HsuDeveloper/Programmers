#include <iostream>
#include <vector>

using namespace std;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2e9;
    int f[201][201];

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            f[i][j] = 1e9;
        }
        f[i][i]=0;
    }

    for(int i=0;i<fares.size();i++){
        int from=fares[i][0],to=fares[i][1],fare=fares[i][2];
        f[from][to] = fare;
        f[to][from] = fare;
    }

    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                int r = f[i][k] + f[k][j];
                if(f[i][j] > r) f[i][j] = r;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        if(f[s][i]==1e9||f[i][a]==1e9||f[i][b]==1e9) continue;
        int res = f[s][i] + f[i][a] + f[i][b];
        if(answer > res) answer = res;
    }


    return answer;
}

int main(){
    int n=6;
    int s=4;
    int a=6;
    int b=2;
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};

    cout<<solution(n,s,a,b,fares);
}