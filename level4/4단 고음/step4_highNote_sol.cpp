#include<iostream>
#include<cmath>

using namespace std;

int find_highNote(int n,int plus){

    int res = 0;

    if(2 * log(n) / log(3) < plus) return 0;
    
    if(n==1 && plus == 0) return 1;
    if(n==1 && plus != 0) return 0;

    if(n%3 == 0 && plus >= 2) res += find_highNote(n/3,plus-2);
    res += find_highNote(n-1,plus+1);

    return res;
}

int solution(int n){
    int answer = find_highNote(n-2,2);

    return answer;
}

int main(){
    int n = 15;
    cout<<solution(n);
}