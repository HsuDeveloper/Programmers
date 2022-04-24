#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int size = jobs.size();
    int t = 0;
    while(jobs.size()>0){

        vector<int> poss;

        for(int i=0;i<jobs.size();i++){
            if(t >= jobs[i][0]) {
                poss.push_back(i);
            }
        }

        if(poss.size()==0){
            t++;
            continue;
        }

        int del = poss[0];
        for(int i=1;i<poss.size();i++){
            if(jobs[del][1] > jobs[poss[i]][1]) del = poss[i];
        }

        t += jobs[del][1];
        answer += t - jobs[del][0];
        jobs.erase(jobs.begin() + del);

    }

    answer /= size;
    return answer;
}

int main(){
    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
    cout<<solution(jobs);
}