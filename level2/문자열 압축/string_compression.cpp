#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v;
int compression(string s){
    if(s.size() == 1) return 1;
    int res=1000;
    for(int i=1;i<=s.size()/2;i++){
        string temp,text="";
        temp=s.substr(0,i);
        int c=1;

        for(int j=i;j<s.size();j+=i){
            if(temp != s.substr(j,i)){
                if(c>1)text += to_string(c);
                text += temp;
                c = 1;
                temp = s.substr(j,i);       
            }
            else{
                c++;
            }
        }
        if(c>1)text += to_string(c);
        text += temp;
        if(res > text.size()) res = text.size();
    }
    return res;
}



int solution(string s){
    int answer = 0;
    answer = compression(s);
    return answer;
}

int main(){
    string s = "a";
    string s2 = "aabbaccc";

    cout<<solution(s);

}