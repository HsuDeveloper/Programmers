#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class user{
    public:
    string name;
    string id;

    user(string id, string name){
        this->id = id;
        this->name = name;
    }
};
class log{
    public:
    string id;
    string state;

    log(string id,string state){
        this->id = id;
        this->state = state;
    }
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<user> users;
    vector<log> logs;

    for(int i=0;i<record.size();i++){
        istringstream ss(record[i]);
        string buf;
        vector<string> v;
        while(getline(ss,buf,' ')){
            v.push_back(buf);
        }

        if(v[0] == "Change"){
            for(int j=0;j<users.size();j++){
                if(users[j].id == v[1]){
                    users[j].name = v[2];
                }
            }
        }
        else if(v[0] == "Leave"){
            logs.push_back(log(v[1],v[0]));
        }
        else if(v[0] == "Enter"){
            bool check = 0;
            for(int j=0;j<users.size();j++){
                if(users[j].id == v[1]){
                    check = 1;
                    users[j].name = v[2];
                }
            }
            if(!check){
                users.push_back(user(v[1],v[2]));
            }
            logs.push_back(log(v[1],v[0]));
        }
    }
    for(int i=0;i<logs.size();i++){
        string res="",name="";
        for(int j=0;j<users.size();j++){
            if(logs[i].id == users[j].id){
                name = users[j].name;
            }
        }
        if(logs[i].state == "Enter"){
            res = name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else{
            res = name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
        answer.push_back(res);
    }
    

    return answer;
}

int main(){
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> answer;
    answer = solution(record);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<'\n';
    }
}