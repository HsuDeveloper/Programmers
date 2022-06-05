#include <iostream>
#include <vector>

using namespace std;

bool check(string p){
    int open=0;
    int close=0;
    for(int i=0;i<p.size();i++){
        if(p[i]=='(') open++;
        else if(p[i]==')') close++;
    }
    return open==close;
}

bool per_check(string p){
    if(p[0]!='(')return 0;
    int c=0;
    for(int i=0;i<p.size();i++){
        if(c<0) return 0;
        if(p[i]=='(') c++;
        else if(p[i] == ')') c--;
    }
    return 1;
}

string change(string p){
    p = p.substr(1,p.size()-2);
    for(int i=0;i<p.size();i++){
        if(p[i]=='(') p[i] = ')';
        else if(p[i]==')') p[i] = '(';
    }
    return p;
}

string solution(string p) { 
    string answer = "";
    string u,v;
    if(p == "") return answer;
    if(per_check(p))return p;


    for(int i=1;i<p.size()+1;i++){
        if(check(p.substr(0,i))){
            u = p.substr(0,i);
            v = p.substr(i);
            break;
        }
    }
    if(per_check(u)) answer = u + solution(v);
    else {
        u = change(u);
        answer = '('+ solution(v) + ')' + u;
    }


    return answer;
}

int main(){


    string p = "()))((()";
    cout<<solution(p);
}