#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool check(string a,string b,int start,int end){

    for(int i=start;i<end;i++){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<string,bool> m;
    vector<pair<int,int>> check_round;

    for(int i=0;i<queries.size();i++){
        int a=-1;
        int b;
        for(int j=0;j<queries[i].size();j++){
            if(a == -1 && queries[i][j]=='?') a=j;
            if(queries[i][j]=='?') b=j;
        }
        
        if(a!=0){
            b=a;
            a=0;
        }
        else{
            a=b+1;
            b=queries[i].size();
        }

        check_round.push_back({a,b});
    }

    for(int i=0;i<words.size();i++){
        m[words[i]] = 1;
    }

    for(int i=0;i<queries.size();i++){
        int size = queries[i].size();
        int cnt = 0;
        for(auto iter = m.begin();iter != m.end();iter++){
            if(iter->first.size() != size) continue;
            if(check(queries[i],iter->first,check_round[i].first,check_round[i].second)) cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}

int main(){
    vector<string> words={"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries={"fro??", "????o", "fr???", "fro???", "pro?"};

    vector<int> answer = solution(words,queries);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}