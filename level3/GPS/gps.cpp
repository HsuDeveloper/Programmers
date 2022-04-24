#include <iostream>
#include <vector>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int INF = 987654321;
    int answer = INF;
    vector<vector<int>> node(n+1);
    vector<vector<int>> dp(k,vector<int>(n+1,INF));

    for(int i=0;i<m;i++){
        int a=edge_list[i][0],b=edge_list[i][1];
        node[a].push_back(b);
        node[b].push_back(a);
    }

    dp[0][gps_log[0]] = 0;
    for(int i=1;i<k;i++){
        for(int j=1;j<n+1;j++){
            int add = (gps_log[i] == j ? 0: 1);

             //���ڸ� ���� �� ���
            dp[i][j] = min(dp[i][j],dp[i-1][j]);

            //�ǳ� �� ���
            for(int p =0;p<node[j].size();p++){
                dp[i][j] = min(dp[i][j],dp[i-1][node[j][p]]);
            }

            //����� �߰�
            dp[i][j] += add;

        }
    }

    answer = dp[k-1][gps_log[k-1]];

    if(answer>=INF) return -1;
    return answer;
}

int main(){
    int n=7;
    int m=10;
    vector<vector<int>> edge_list = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    int k=6;
    vector<int> gps_log={1, 2, 3, 3, 6, 7};

    cout<<solution(n,m,edge_list,k,gps_log);
}