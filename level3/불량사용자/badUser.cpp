#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> s;

bool check(string &user,string &banned){
    int size = user.size();
    if(size != banned.size()) return 0;
    for(int i=0;i<size;i++){
        if(user[i]!=banned[i] && banned[i]!='*') return 0;
    }
    return 1;
}

void dfs(vector<string> &user_id,vector<string> &banned_id,vector<bool> &d,int b){
    if(b == banned_id.size()){
        string str = "";
        for(int i=0;i<user_id.size();i++){
            str += to_string(d[i]);
        }
        s.emplace(str);
        return;
    }

    for(int i=0;i<user_id.size();i++){
        if(!d[i] && check(user_id[i],banned_id[b])) {
            d[i] = 1;
            dfs(user_id,banned_id,d,b+1);
            d[i] = 0;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int size = user_id.size();
    int size_ban = banned_id.size();

    vector<bool> d(size,0);

    dfs(user_id,banned_id,d,0);
    
    answer = s.size();

    return answer;
}

int main(){
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "*rodo", "******", "******"};
    //vector<string> banned_id = {"*rodo", "*rodo", "******"};

    cout<<solution(user_id,banned_id);
}