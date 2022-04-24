#include<iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool check(string &a,string &b){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) cnt++;
    }
    if(cnt != 1) return 0;
    return 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> q;
    map<string,int> m;
    
    for(int i=0;i<words.size();i++){
        if(check(begin, words[i])) q.push(make_pair(words[i],1));
    }
    m[begin] = 0;

    while(!q.empty()){
        string s = q.front().first;
        int n = q.front().second;
        m[s] = n;
        q.pop();
        if(s == target){
            answer = n;
            break;
        }

        for(int i=0;i<words.size();i++){
            if((!m[words[i]] || m[words[i]] >= n) && check(s,words[i])) q.push(make_pair(words[i],n+1));
        }

    }

    

    return answer;
}

int main(){
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log"};

    cout<<solution(begin,target,words);
}