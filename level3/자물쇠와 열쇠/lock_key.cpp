#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &key){
    vector<vector<int>> temp;
    int size = key.size();
    temp = key;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            temp[j][size-i-1] = key[i][j];
        }
    }
    
    key = temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int key_size = key.size();
    int lock_size = lock.size();
    int d = key_size * 2 + lock_size - 2;

    vector<vector<int>> board(d,vector<int>(d));

    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            board[key_size-1+i][key_size-1+j] = lock[i][j];
        }
    }

    for(int i=0;i<4;i++){
        rotate(key);
        vector<vector<int>> temp_board;
        

        for(int j=0;j<key_size + lock_size - 1;j++){
            for(int k=0;k<key_size + lock_size - 1; k++){
                temp_board = board;
                bool flag = 1;
                
                for(int a=0;a<key_size;a++){
                    for(int b=0;b<key_size;b++){
                        temp_board[j + a][k + b] += key[a][b];
                    }
                }
                
                for(int a=0;a<lock_size;a++){
                    for(int b=0;b<lock_size;b++){
                        if(temp_board[key_size-1+a][key_size-1+b]!=1){
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                
                if(flag) return 1;


            }
        }

    }
   
    return answer;
}

int main(){
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    cout<<solution(key,lock);
}