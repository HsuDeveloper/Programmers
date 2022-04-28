#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// time out

bool check(string highNote){
    int start = 0;
    int load = 0;

    for(char c : highNote){
        if(c=='*') start++;
        else load++;

        if(start *2 < load) return 0;
    }

    return 1;
}

void find_step(int n,vector<int> &steps){
    int step = 0;
    int high = 1;
    int low;
    while(1){
        step++;
        low = pow(3,step)+2*step;
        high = high*3+2;
        if(n < low) break;
        if(low <= n && n <= high) steps.push_back(step);
    }
}

int transform(string highNote){
    int res = 1;
    for(char c : highNote){
        if(c=='*') res *= 3;
        else res++;
    }
    return res;
}

int find_highNote(int n,int step){
    int res=0;
    string highNote = "";
    for(int i=0;i<step;i++){
        highNote += "*";
    }
    for(int i=0;i<2*step;i++){
        highNote += "+";
    }

    do{
        if(!check(highNote)) continue;
        if(transform(highNote) == n) res++;
    }while(next_permutation(highNote.begin(),highNote.end()));

    return res;
}

int solution(int n) {
    int answer = 0;
    vector<int> steps;
    find_step(n,steps);

    int size = steps.size();
    if(size==0) return 0;

    for(int i=0;i<size;i++){
        answer+=find_highNote(n,steps[i]);
    }

    return answer;
}

int main(){
    int n = 41;
    cout<<solution(n);
}