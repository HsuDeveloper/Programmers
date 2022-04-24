#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string,int> h;

    for(int i=0;i<phone_book.size();i++){
        h[phone_book[i]] = i+1;
    }

    for(int i=0;i<phone_book.size();i++){
        string num="";
        for(int j=0;j<phone_book[i].size();j++){
            num += phone_book[i][j];

            if(h[num] && num != phone_book[i]) return 0;
        }
    }
    
    return answer;
}

int main(){
    vector<string> phone_book= {"11", "117"};
    cout<< solution(phone_book);
}