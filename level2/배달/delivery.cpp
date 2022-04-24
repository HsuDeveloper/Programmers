#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> d(N+1,-1);
    vector<vector<pair<int,int>>> v(N+1);

    
    for(int i=0;i<road.size();i++){
        int a=road[i][0],b=road[i][1],c=road[i][2];
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    int curr=1,cnt=0;
    priority_queue<pair<int,int>> q;
    d[1] = 0;
    q.push({cnt,curr});

    while(!q.empty()){
        curr = q.top().second;
        cnt = -q.top().first;
        q.pop();
        for(int i=0;i<v[curr].size();i++){
            int next = v[curr][i].second;
            int dis = v[curr][i].first;

            if(d[next]!=-1 && d[next] < d[curr] + dis) continue;
            d[next] = d[curr] + dis;
            q.push({- dis,next});
            
        }
    }
    for(int i=1;i<N+1;i++){
        if(d[i]!=-1&&d[i] <= K) answer++;
    }

    return answer;
}

int main(){
    int N=6;
    vector<vector<int>> road = {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};
    int K=4;

    cout<< solution(N,road,K);
}