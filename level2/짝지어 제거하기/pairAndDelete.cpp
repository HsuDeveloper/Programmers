#include <iostream>
#include <stack>
#include<string>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    if(s=="")return 1;

    st.push(s[0]);

    for(int i=1;i<s.size();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            char c = st.top();
            if(c == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }

    return st.empty();  

}

int main(){
    string s = "aabbcc";
    cout<<solution(s);
}