#include <iostream>
#include <vector>

using namespace std;

int dp[1000001];
int dp2[1000001];
 
int solution(vector<int> money)
{
    int answer = 0;
    int n = money.size();
    

    dp[0] = money[0];
    dp[1] = money[0];
    
    for (int i = 2; i < n-1; i++)
    {
        dp[i] = max(dp[i-2] + money[i],dp[i-1]);
    }
    
    answer = dp[n-2];

    dp2[1] = money[1];

    for (int i = 2; i < n; i++)
    {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    if(dp2[n-1] > answer) answer = dp2[n-1];
    return answer;
}

int main(){
    vector<int> v(1000001,0);
    cout<<solution({1000,1,1,1000,1,1,1,1});
}