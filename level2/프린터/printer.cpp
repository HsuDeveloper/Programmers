#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int,int>> q;

    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(priorities[i],i));
    }

    sort(priorities.begin(),priorities.end());
    reverse(priorities.begin(),priorities.end());
    
    int print=-1;
    int i=0;
    while(print != location){
        int pri = q.front().first;
        int seq = q.front().second;
        
        if(priorities[i] != pri){
            q.pop();
            q.push(make_pair(pri,seq));
            continue;
        }

        print = seq;
        q.pop();
        i++;
        answer++;
    }
    return answer;
}

int main(){
    vector<int> priorities {1, 1, 9, 1, 1, 1};
    int location = 0;

    cout<< solution(priorities,location);
}