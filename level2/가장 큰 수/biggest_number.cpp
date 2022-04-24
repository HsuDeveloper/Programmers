#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string &a,string &b){
    if(a[0] != b[0] || a.size()==b.size()) return a>b;

    return stoi(a+b) > stoi(b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;

    for(int i=0;i<numbers.size();i++){
        num.push_back(to_string(numbers[i]));
    }

    sort(num.begin(),num.end(),comp);
    

    for(int i=0;i<num.size();i++){
        answer += num[i];
    }

    if(answer[0] == '0') return "0";
    return answer;
}

int main(){
    vector<int> numbers={0,0,0,0,0};
    cout<< solution(numbers);
}