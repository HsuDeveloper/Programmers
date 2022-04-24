#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool d[100][100]={0,};

    int answer = 0;
    int n = maps.size()-1;
    int m = maps[0].size()-1;

    queue<pair<int,pair<int,int>>> q;
    
    q.push(make_pair(1,make_pair(n,m)));

    bool goal = 0;

    while(!q.empty()){
        int cnt = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        if(row == 0 && col == 0){
            goal = 1;
            answer = cnt;
            break;
        }

        for(int i=0;i<4;i++){
            int next_cnt = cnt + 1;
            int next_r = row + dx[i];
            int next_c = col + dy[i];

            if(next_r < 0 || next_r > n || next_c < 0 || next_c > m || d[next_r][next_c] || !maps[next_r][next_c]) continue;

            q.push(make_pair(next_cnt,make_pair(next_r,next_c)));
            d[next_r][next_c] = 1;
        }

    }

    if(!goal) return -1;

    return answer;
}

int main(){
    vector<vector<int>> maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
    // vector<vector<int>> maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}};
    cout<<solution(maps);
}