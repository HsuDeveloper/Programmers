#include <iostream>
#include <stack>

using namespace std;

bool check(char a,char b){
    if(a =='(' && b==')') return 1;
    if(a =='{' && b=='}') return 1;
    if(a =='[' && b==']') return 1;
    return 0;
}

int solution(string s) {
    int answer = 0;
    int size = s.size();

    for(int i=0;i<size;i++){
        s = s.substr(1,size-1) + s[0];
        
        stack<char> st;
        char c;
        for(int i=0;i<size;i++){
            if(!st.empty()) {
                c=st.top();
                if(check(c,s[i])) st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        if(st.empty())answer++;
    }
    return answer;
}

int main(){
    string s = "[](){}";
    cout<<solution(s);
}