#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'O');
    vector<int> table;
    stack<pair<int,int>> s;

    for(int i=0;i<n;i++){
        table.push_back(i);
    }

    for(int i=0;i<cmd.size();i++){

        if(cmd[i][0] == 'U'){
            k -= stoi(cmd[i].substr(2));
        }
        
        else if(cmd[i][0] == 'D'){
            k += stoi(cmd[i].substr(2));
        }

        else if(cmd[i][0] == 'C'){
            s.push(make_pair(k,table[k]));
            table.erase(table.begin()+k);
    
            if(k == table.size()) k--;
        }

        else if(cmd[i][0] == 'Z'){
            int restore_pos = s.top().first;
            int restore_val = s.top().second;
            s.pop();
            if(restore_val < table[k])k++;
            table.insert(table.begin() + restore_pos , restore_val);
            
        }
    }


    while(!s.empty()){
        answer[s.top().second] = 'X';
        s.pop();
    }
    return answer;
}

int main(){
    int n = 8;
    int k = 2;
    //vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};


    cout<<solution(n,k,cmd);
}