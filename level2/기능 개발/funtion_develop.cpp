#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> answer;
    queue<int> succeds;
    int size = progresses.size();

    for(int i=0;i<size;i++){
        int t = ceil((100-progresses[i])/(double)speeds[i]);    
        succeds.push(t);
    }

    while(!succeds.empty()){
        int c=1;
        int n = succeds.front();
        succeds.pop();
        while(!succeds.empty() && n>=succeds.front()){
            succeds.pop();
            c++;
        }
        
        answer.push_back(c);
    }

    return answer;
}

int main(){
    vector<int> progresses = {55,60,65};
    vector<int> speeds = {5,10,7};
    vector<int> answer = solution(progresses,speeds);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}