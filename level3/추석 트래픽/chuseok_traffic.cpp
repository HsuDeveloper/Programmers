#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<string> v;
    vector<pair<double,double>> logs;

    for(int i=0;i<lines.size();i++){
        string buf;
        istringstream ss(lines[i]);
        while(getline(ss,buf,' ')){
            v.push_back(buf);
        }
    }
    for(int i=0;i<v.size();i++){
        if(i%3 == 1){
            double end = stod(v[i].substr(0,2))*3600 + stod(v[i].substr(3,2))*60 + stod(v[i].substr(6));
            double time = stod(v[i+1].substr(0,v[i+1].length()-1));
            double start = end - time + 0.001;
            logs.push_back(make_pair(start,end));
        }
    }

    for(int i=0;i<logs.size();i++){
        int cnt = 1;
        for(int j=i+1;j<logs.size();j++){
        
            if(logs[i].second + 1 >= logs[j].first){
                cnt++;
            }
        
        }
        
        answer = max(answer,cnt);
    }
    

    return answer;
}

int main(){
    vector<string> lines = {"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"};

cout<<solution(lines);
}