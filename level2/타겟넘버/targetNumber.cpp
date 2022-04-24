#include<iostream>
#include<vector>

using namespace std;


int cnt = 0;
void dfs(int n,vector<int> numbers,int size,int res,int target){
    if(n == size){
        if(res == target){
            cnt++;
        }
        
        return;
    }

    dfs(n+1,numbers,size,res+numbers[n],target);
    dfs(n+1,numbers,size,res-numbers[n],target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = numbers.size();
    dfs(0,numbers,size,0,target);
    answer = cnt;
    return answer;
}

int main(){
    cout<<solution({1,1,1,1,1},3);
}