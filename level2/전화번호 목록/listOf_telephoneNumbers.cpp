#include<iostream>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    vector<vector<string>> v(21);
    for(int i=0;i<phone_book.size();i++){
            v[phone_book[i].size()].push_back(phone_book[i]);
    }

    for(int i=19;i>1;i--){
        if(v[i].size()==0) continue;
        for(int j=1;j<i;j++){
            if(v[j].size()==0) continue;
            for(int k=0;k<v[i].size();k++){
                string s = v[i][k].substr(0,j);
                for(int r=0;r<v[j].size();r++){
                    if(v[j][r] == s) return 0;
                }
            }
        }
    }
    
    return answer;
}

int main(){
    vector<string> phone_book= {"119", "97674223", "1195524421"};
    cout<< solution(phone_book);
}