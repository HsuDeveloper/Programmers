#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// double compare

int solution(vector<string> lines) {
    int answer = 0;
    vector<string> v;
    vector<pair<int,int>> logs;

    for(int i=0;i<lines.size();i++){
        string buf;
        istringstream ss(lines[i]);
        while(getline(ss,buf,' ')){
            v.push_back(buf);
        }
    }
    for(int i=0;i<v.size();i++){
        if(i%3 == 1){
            double end = stod(v[i].substr(0,2))*3600000 + stod(v[i].substr(3,2))*60000 + stod(v[i].substr(6))*1000;
            double time = stod(v[i+1].substr(0,v[i+1].length()-1))*1000;
            double start = end - time + 1;
            //double to int
            logs.push_back(make_pair(start,end));
        }
    }

    for(int i=0;i<logs.size();i++){
        int cnt = 1;
        for(int j=i+1;j<logs.size();j++){
            if(logs[i].second >= logs[j].first - 1000 + 1){
                cnt++;
            }
        
        }
        
        answer = max(answer,cnt);
    }
    

    return answer;
}

int main(){
    vector<string> lines = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};
   
    cout<<solution(lines);
}