#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> s_picture;
int M,N;
vector<vector<bool>> d;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int num,int posR,int posC){
    int res = 1;
    d[posR][posC] = 1;

    for(int i=0;i<4;i++){
        int next_posR = posR + dx[i];
        int next_posC = posC + dy[i];

        if(next_posR >=0 && next_posR<M && next_posC>=0 &&next_posC < N && !d[next_posR][next_posC] && s_picture[next_posR][next_posC] == num){
            res += dfs(num,next_posR,next_posC);
        }
        
    }
    return res;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<bool> c;
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    s_picture = picture;

    for(int i=0;i<n;i++){
        c.push_back(0);
    }

    for(int i=0;i<m;i++){
        d.push_back(c);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!d[i][j] && s_picture[i][j]!=0){
                number_of_area++;
                max_size_of_one_area = max(dfs(s_picture[i][j],i,j),max_size_of_one_area);
            }
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    // vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};
    vector<vector<int>> picture = {{1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3}};
    // vector<vector<int>> picture = {{0,0},{0,0}};
    cin >> M >> N;
    vector<int> answer = solution(M,N,picture);

    for(int i=0;i<answer.size();i++){
        cout<< answer[i] <<' ';
    }
}