#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> top;
    priority_queue<int> bottom;

    int cnt = 0;

    for(string op : operations){
        if(op[0] == 'I'){
            top.push(stoi(op.substr(2)));
            bottom.push(-stoi(op.substr(2)));
            cnt++;
        }

        else if(op == "D 1"){
            if(!cnt) continue;
            top.pop();
            cnt--;   
        }
        else if(op == "D -1"){
           if(!cnt) continue;
           bottom.pop();
           cnt--;
        }

        if(!cnt){
            while(!top.empty()) top.pop();
            while(!bottom.empty()) bottom.pop();
        }
    }
    cout<<cnt<<'\n';
    if(!cnt) return {0,0};
    answer = {top.top(),-bottom.top()};
    return answer;
}

int main(){
    vector<string> operations={"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    vector<int> answer = solution(operations);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }

}
