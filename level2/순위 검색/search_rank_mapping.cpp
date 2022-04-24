#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string,vector<int>> m;
    string buff;
    string info_s;

    vector<vector<vector<string>>> avail;

    for(int i=0;i<info.size();i++){
        istringstream ss(info[i]);
        vector<vector<string>> v;
        
        for(int j=0;j<4;j++){
            vector<string> v_item;

            getline(ss,buff,' ');
            v_item.push_back(buff);
            v_item.push_back("-");
            v.push_back(v_item);
        }

        getline(ss,buff,' ');
        v.push_back({buff});
        avail.push_back(v);
    }

    for(int a=0;a<avail.size();a++){
        for(int b=0;b<2;b++){
            for(int c=0;c<2;c++){
                for(int d=0;d<2;d++){
                    for(int e=0;e<2;e++){
                        info_s = avail[a][0][b] + avail[a][1][c] + avail[a][2][d] + avail[a][3][e];
                        m[info_s].push_back(stoi(avail[a][4][0]));
                    }
                }
            }
        }
    }

    for( auto iter = m.begin(); iter != m.end();iter++){
        sort(iter->second.begin(),iter->second.end());
    }

    for(int i=0;i<query.size();i++){
        istringstream ss(query[i]);
        string query_s="";

        for(int j=0;j<7;j++){
            getline(ss,buff,' ');
            if(buff != "and") query_s += buff;
        }

        getline(ss,buff,' ');
        int num = stoi(buff);
        int cnt = 0;

        cnt = m[query_s].end() - lower_bound(m[query_s].begin(),m[query_s].end(),num);
        
        answer.push_back(cnt);
    }

    return answer;
}

int main(){
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<int> answer = solution(info,query);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}