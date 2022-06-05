#include<iostream>

using namespace std;

int MIN = 9;
int n,num;

void n_operation(int cur,int cnt){
    if(num==0){
        MIN = 2;
        return;
    }
    if(cnt > 8 )return;
    if(cur == num){
        if(MIN > cnt){
            MIN = cnt;
        }
        return;
    }

    int oper_n=0;

    for(int i=1;i<9;i++){
        oper_n = oper_n*10 + n;
        n_operation(cur + oper_n,cnt+i);
        n_operation(cur - oper_n,cnt+i);
        n_operation(cur * oper_n,cnt+i);
        n_operation(cur / oper_n,cnt+i);
    }
    return;
}

int solution(int N,int number){
    int answer=0;
    n = N;
    num = number;
    n_operation(0,0);
    answer = MIN;
    if(MIN > 8) return -1;
    return answer;
}
int main(){
    cout<<solution(5,0);
}