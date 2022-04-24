#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[101][101];
    int c_arr[101][101];
    queue<int> q;

    for(int i=1;i<rows+1;i++){
        for(int j=1;j<columns+1;j++){
            arr[i][j] = (i-1) * columns + j;
            c_arr[i][j] = arr[i][j];
        }
    }

    for(int i=0;i<queries.size();i++){
        priority_queue<int> pq;

        int x = queries[i][0];
        int y = queries[i][1];
        int x_ = queries[i][2];
        int y_ = queries[i][3];

        for(int j=y;j<y_+1;j++){
            q.push(arr[x][j]);
            pq.push(-arr[x][j]);
        }
        for(int j = x+1; j<x_+1;j++){
            q.push(arr[j][y_]);
            pq.push(-arr[j][y_]);
        }
        for(int j = y_-1; j >y-1;j--){
            q.push(arr[x_][j]);
            pq.push(-arr[x_][j]);
        }
        for(int j = x_-1; j > x;j--){
            q.push(arr[j][y]);
            pq.push(-arr[j][y]);
        }


        for(int j=y+1;j<y_+1;j++){
            arr[x][j] = q.front();
            q.pop();
        }
        for(int j = x+1; j<x_+1;j++){
            arr[j][y_] = q.front();
            q.pop();
        }
        for(int j = y_-1; j >y-1;j--){
            arr[x_][j] = q.front();
            q.pop();
        }
        for(int j = x_-1; j > x-1;j--){
            arr[j][y] = q.front();
            q.pop();
        }

        answer.push_back(-pq.top());
        
    }
    for(int i=1;i<rows+1;i++){
        for(int j=1;j<columns+1;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }


    return answer;
}

int main(){
    int rows=6;
    int columns=6;

    // vector<vector<int>> queries={{2,2,5,4},{3,3,6,6},{5,1,6,3}};
    vector<vector<int>> queries={{1,1,2,2}};

    vector<int> answer = solution(rows,columns,queries);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}