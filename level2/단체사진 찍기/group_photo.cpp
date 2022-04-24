#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_n(char a, vector<char> c){
    for(int i=0;i<c.size();i++){
        if(a == c[i]) return i;
    }
    return -1;
}

bool fun1(int a,int b,int n){
    if(abs(a-b) == n+1) return 1;
    return 0;
}

bool fun2(int a,int b,int n){
    if(abs(a-b) > n+1) return 1;
    return 0;
}

bool fun3(int a,int b,int n){
    if(abs(a-b) < n+1) return 1;
    return 0;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    bool check = 1;
    vector<char> c = {'A','C', 'F', 'J', 'M', 'N', 'R', 'T'};
    do{

        for(int i=0;i<n;i++){
            int a = find_n(data[i][0],c);
            int b = find_n(data[i][2],c);
            int num = data[i][4] - '0';

            if(data[i][3] == '='){
                if(!fun1(a,b,num)) {
                    check = 0;
                    break;
                }
            }
            else if(data[i][3] == '>'){
                if(!fun2(a,b,num)) {
                    check = 0;
                    break;
                }
            }
            else if(data[i][3] == '<'){
                if(!fun3(a,b,num)){
                    check = 0;
                    break;
                } 
            } 
        }
        
        if(check) answer++;
        
        check = 1;
    }while(next_permutation(c.begin(),c.end()));
    return answer;
}

int main(){
    cout<<solution(2,{"M~C<2", "C~M>1"});
}