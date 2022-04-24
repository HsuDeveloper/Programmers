#include<iostream>
#include <vector>
#include <stack>

using namespace std;

int make_num(int n){
    switch(n%3){
            case 0:
            return 4;
            case 1:
            return 1;
            case 2:
            return 2;
        }
    return -1;
}

string solution(int n) {
    string answer = "";
    stack<int> s;
    while(n>=3){
        if(n%3 == 0){
            s.push(4);
            n--;
        }
        else {s.push(make_num(n));}
        n = n/3;
    }
    if(n!=0) s.push(make_num(n));

    while(!s.empty()){
        answer += to_string(s.top());
        s.pop();
    }

    return answer;
}

int main(){
    cout<<solution(10);
}