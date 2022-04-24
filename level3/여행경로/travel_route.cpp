#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(string curr,vector<string> &answer,vector<vector<string>> tickets,bool d[10000],int cnt,int size){
    answer.push_back(curr);
    

    for(int i=0;i<size;i++){
        if(!d[i] && tickets[i][0]==curr){
            d[i] = 1;
            if(dfs(tickets[i][1],answer,tickets,d,cnt+1,size) != size) answer.pop_back();
            else return size;
            d[i] = 0;
        }
    }

    return cnt;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int size = tickets.size();
    bool d[10000]={0,};

    sort(tickets.begin(),tickets.end());

    dfs("ICN",answer,tickets,d,0,size);
    
    return answer;
}

int main(){
    vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    vector<string> answer = solution(tickets);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}