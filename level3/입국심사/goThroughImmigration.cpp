#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int size = times.size();
    
    sort(times.begin(),times.end());

    long long start = 1;
    long long end = (long long)times[size-1] * n;
    long long mid; 

    while(start <= end){
        int cnt=0;
        mid = (start+end)/2;

        for(int i=0;i<size;i++){
            cnt += mid/times[i];
        }

        if(cnt<n){
            start = mid+1;
        }
        else{
            end = mid-1;
            if(answer==0){
                answer = mid;
            }
            else{
                if(answer > mid) answer = mid;
            }
        }
    }

    return answer;
}

int main(){
    int n = 6;
    vector<int> times = {7,10};

    cout<<solution(n,times);
}