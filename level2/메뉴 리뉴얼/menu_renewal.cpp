#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> m;


void dfs(string order,int course,int len,int index,string s){
    if(len == course){
        m[s]++;
        return;
    }

    for(int i = index;i<order.size();i++){
        dfs(order,course,len+1,i+1,s + order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int alp[26]={0,};
    vector<int> max_values;

    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(),orders[i].end());
        for(int j=0;j<course.size();j++){
            dfs(orders[i],course[j],0,0,"");
        }
    }

    for(int i=0;i<course.size();i++){
        int max=2;
        for(auto& order : m){
            if(order.first.size() == course[i]){
                if(order.second > max) max = order.second;
            }
        }
        max_values.push_back(max);
    }

    for(int i=0;i<course.size();i++){

        for(auto& order : m){
            if(order.first.size() == course[i] && order.second == max_values[i]){
                answer.push_back(order.first);
            }
        }
    }

    sort(answer.begin(),answer.end());
    return answer;
}

int main(){
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2,3,4};

    vector<string> answer = solution(orders,course);
    for(int i=0;i<answer.size();i++){
        cout<< answer[i]<<' ';
    }
}