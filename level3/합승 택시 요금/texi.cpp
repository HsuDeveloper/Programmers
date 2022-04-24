#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//Dijkstra time over

int find_route(int start,int end,int f[][201],int n,vector<vector<int>> poss){
    if(start == end) return 0;
    vector<int> d(n+1,-1);
    priority_queue<pair<int,int>> q;

    d[start] = 0;
    q.push({0,start});

    while(!q.empty()){

        int curr = q.top().second;
        int dis = -q.top().first;
        q.pop();
        if(d[end]!=-1 && d[end] <dis) continue;

        for(int i=0;i<poss[curr].size();i++){
            int next = poss[curr][i];
            int add = f[curr][next];

            if(d[end]!=-1 && d[end] <dis + add) continue;
            if(d[next]!=-1 && d[next] < dis + add) continue;
            d[next] = dis + add;
            q.push({-dis-add,next});
        }
    }

    return d[end];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2e9;
    int f[201][201];
    vector<vector<int>> poss(n+1);
    

    for(int i=0;i<fares.size();i++){
        int from=fares[i][0],to=fares[i][1],fare=fares[i][2];
        f[from][to] = fare;
        f[to][from] = fare;
        poss[from].push_back(to);
        poss[to].push_back(from);
    }

    for(int i=1;i<n+1;i++){
        int x=find_route(s,i,f,n,poss),y=find_route(i,a,f,n,poss),z=find_route(i,b,f,n,poss);
        int res = x+y+z;
        if(res>=0&&answer > res) answer = res;
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