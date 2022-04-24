#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int size = rocks.size();
    
    sort(rocks.begin(),rocks.end());
    
    int left = 0;
    int right = distance;
    int mid,pre,cnt;

    while(left <= right){
        mid= (left+right)/2;
        pre = 0;
        cnt = 0;

        for(int i=0;i<size;i++){
            if(rocks[i] - pre < mid) cnt++;
            else pre = rocks[i];
        }
        if( distance - pre < mid) cnt++;

        if(cnt > n) right = mid -1;
        else{
            answer = max(mid,answer);
            left = mid+1;
        }
    }
    

    return answer;
}

int main(){
    int distance = 25;
    vector<int> rocks = {2, 14, 11, 21, 17};
    int n = 2;

    cout<<solution(distance,rocks,n);
}