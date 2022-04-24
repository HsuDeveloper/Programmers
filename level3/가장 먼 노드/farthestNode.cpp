#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    queue<pair<int,int>> q;

    int d[n+1] = {0,};

    bool c[n+1] = {0,};

    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    c[1] = 1;
    for(int i=0;i<graph[1].size();i++){
        q.push(make_pair(graph[1][i],1));
        c[graph[1][i]] = 1;
    }

    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        d[cnt]++;
        cout<<x<<' '<<cnt<<'\n';

        q.pop();

        for(int i=0;i<graph[x].size();i++){
            if(!c[graph[x][i]]){
                q.push(make_pair(graph[x][i],cnt+1));
                c[graph[x][i]] = 1;
            }
        }
    }
    for(int i=0;i<n+1;i++){
        if(d[n-i] != 0){
            answer = d[n-i];
            break;
        }
    }

    
    return answer;
}

int main(){
    int n = 6;
    vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };

    cout << solution(n,edge);
}