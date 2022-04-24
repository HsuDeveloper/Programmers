#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500];
    int height = triangle.size();

    dp[0][0] = triangle[0][0];
    
    for(int i=1;i<height;i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0) dp[i][j] = dp[i-1][0] + triangle[i][0];
            else if(j==triangle[i].size()-1) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else {
                int numL = dp[i-1][j-1];
                int numR = dp[i-1][j];
                if(numL > numR ) dp[i][j] = triangle[i][j] + numL;
                else dp[i][j] = triangle[i][j] + numR;
            }
        }
    }

    for(int i=0;i<triangle[height-1].size();i++){
        if(answer < dp[height-1][i]) answer = dp[height-1][i];
    }

    return answer;
}

int main(){
    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout<<solution(triangle);
}