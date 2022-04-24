#include <iostream>

using namespace std;

void match(int &a){
    if(a%2 == 0) a = a/2;
    else a = a/2 + 1;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(a != b){
        match(a);
        match(b);

        answer++;
    }

    return answer;
}

int main(){
    int n = 8;
    int a = 7;
    int b = 3;

    cout<<solution(n,a,b);
}