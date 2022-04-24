#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,int>> num;
    int arr[100001]={};
    string tmp="";

    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            tmp += s[i];
        }
        else if(tmp.size()){
            arr[stoi(tmp)]++;
            tmp="";
        }
    }
    for(int i=0;i<100001;i++){
        if(arr[i]) num.push_back(make_pair(arr[i],i));
    }
    
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());

    for(int i=0;i<num.size();i++){
        answer.push_back(num[i].second);
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