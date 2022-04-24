#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class linkList{
    public:
    int num;
    linkList* prev;
    linkList* next;

    linkList(int num) : num(num),prev(NULL),next(NULL){};
    
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    stack<int> s;
    vector<linkList*> v(n);

    for(int i=0;i<n;i++) v[i] = new linkList(i);
    
    for(int i=0;i<n-1;i++){
        v[i]->next = v[i+1];
        v[i+1]->prev = v[i];
    }

    int cnt = 0;
    for(int i=0;i<cmd.size();i++){

        if(cmd[i][0] == 'U'){
            cnt = stoi(cmd[i].substr(2));
            while(cnt--) k = v[k]->prev->num;
        }
        
        else if(cmd[i][0] == 'D'){
            cnt = stoi(cmd[i].substr(2));
            while(cnt--) k = v[k]->next->num;
        }

        else if(cmd[i][0] == 'C'){
            s.push(k);
            if(v[k]->prev !=NULL){
                v[k]->prev->next = v[k]->next;
            }
            if(v[k]->next != NULL){
                v[k]->next->prev = v[k]->prev;
                k=v[k]->next->num;
            }
            else k=v[k]->prev->num;
        }

        else if(cmd[i][0] == 'Z'){
            int restore = s.top();
            s.pop();
            if(v[restore]->prev!=NULL) v[restore]->prev->next = v[restore];
            if(v[restore]->next!=NULL) v[restore]->next->prev = v[restore];
        }
    }

    answer[k] = 'O';

    int p = k;
    while(v[p]->prev != NULL){
        p = v[p]->prev->num;
        answer[v[p]->num] = 'O';
    }
    p=k;
    while(v[p]->next != NULL){
        p = v[p]->next->num;
        answer[v[p]->num] = 'O';
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