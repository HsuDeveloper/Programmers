#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> &a,vector<int> &b){
    return a.size()<b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    vector<int> num;
    string n="";
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='{'){
            num={};
        }
        else if(s[i]=='}'){
            num.push_back(stoi(n));
            n="";
            v.push_back(num);
        }
        else if(s[i] == ',' && s[i-1]!='}'){
            num.push_back(stoi(n));
            n="";
        }
        else if(s[i] !=','){
            n += s[i];
        }
        
    }

    sort(v.begin(),v.end(),comp);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(find(answer.begin(),answer.end(),v[i][j])==answer.end()) answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}

int main(){
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    vector<int> answer = solution(s);
    for(int i=0;i<answer.size();i++){
        cout<< answer[i]<< ' ';
    }
}