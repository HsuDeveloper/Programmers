#include<iostream>
#include <stack>

using namespace std;

int num[] = {4,1,2};

string solution(int n) {
    string answer = "";
    stack<int> s;
    while(n>=3){
        if(n%3 == 0){
            s.push(4);
            n--;
        }
        else {s.push(num[n%3]);}
        n = n/3;
    }
    if(n!=0) s.push(num[n%3]);

    while(!s.empty()){
        answer += to_string(s.top());
        s.pop();
    }

    return answer;
}

int main(){
    cout<<solution(10);
}