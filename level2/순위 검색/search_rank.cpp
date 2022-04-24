#include<iostream>
#include <vector>
#include <sstream>

using namespace std;

// 효율성 0점

bool find(vector<string> &info,vector<string> &query){

    for(int i=0;i<4;i++){
        if(query[i] != "-" && info[i] != query[i]) return 0;
    }

    if(stoi(query[4]) > stoi(info[4])) return 0;

    return 1;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> split_i;
    vector<vector<string>> split_q;

    string buff;
    for(int i=0;i<info.size();i++){
        istringstream ss(info[i]);
        vector<string> v;
        
        while(getline(ss,buff,' ')){
            v.push_back(buff);
        }

        split_i.push_back(v);
    }

    for(int i=0;i<query.size();i++){
        istringstream ss(query[i]);
        vector<string> v;

        while(getline(ss,buff,' ')){
            if(buff != "and") v.push_back(buff);
        }

        split_q.push_back(v);
    }

    for(int i=0;i<split_q.size();i++){
        int cnt = 0;
        for(int j=0;j<split_i.size();j++){
            if(find(split_i[j],split_q[i])) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}

int main(){
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<int> answer = solution(info,query);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}