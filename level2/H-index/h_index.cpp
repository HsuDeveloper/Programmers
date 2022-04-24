#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    
    int size = citations.size();
    for(int i=0;i<size;i++){
        int temp = min(citations[i],size-i);
        if(answer < temp) answer = temp;
    }

    return answer;
}

int main(){
    vector<int> citations = {3, 0, 6, 1, 5};
    cout<<solution(citations);
}