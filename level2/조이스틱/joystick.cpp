#include <iostream>
#include <vector>

using namespace std;

int change_cnt(char c){
    int a = c-'A';
    int b = 'Z'-c+1;
    if(a < b) return a;
    return b; 
}

int solution(string name) {
    int answer = 0;
    int size = name.size();

    vector<int> notA;
    for(int i=0;i<size;i++){
        if(name[i] != 'A'){
            notA.push_back(i);
            answer +=change_cnt(name[i]);
            continue;
        }
    }
    int notA_size = notA.size();
    if(notA_size==0) return 0;

    int left = size - notA[0];
    if(left == size){
        if(notA_size == 1) left = 0;
        else left = size - notA[1];
    }
    
    int tmp = min(notA[notA_size-1],left);

    for(int i=0;i<notA_size-1;i++){
        int move = min(2*notA[i] + size - notA[i+1], notA[i] + 2*size - 2*notA[i+1]);
        tmp = min(tmp,move);
    }

    answer += tmp;

    
    return answer;
}

int main(){
    string name = "ZAAAAAA";
    cout<<solution(name);
}