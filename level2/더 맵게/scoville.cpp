#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> sq;
    for(int i=0;i<scoville.size();i++){
        sq.push(-scoville[i]);
    }

    while(-sq.top() < K && sq.size()!=1){
        int s = -sq.top();
        sq.pop();
        int s2 = -sq.top();
        sq.pop();

        int s3 = s + 2*s2;
        sq.push(-s3);
        answer++;
    }

    if(sq.size()==1 && -sq.top() < K) return -1;
    
    return answer;
}

int main(){
    vector<int> scoville={10};
    int K = 7;
    cout<<solution(scoville,K);
}
