#include<iostream>
#include<vector>

using namespace std;

long long solution(int w, int h){
    long long answer = 0;
    int x = 1;
    int y;
    
    while(x!=w){
        double n = (long long)h*x/(double)w;
        y = h - n;
        answer += y;
        cout<<n<<'\n';
        x++;
    }

    return 2*answer;
}

int main(){
    int w = 8;
    int h = 12;

    cout<<solution(w,h);
}