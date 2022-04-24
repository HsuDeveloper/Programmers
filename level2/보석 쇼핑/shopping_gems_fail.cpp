#include<iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2,0);
    map<string,bool> m;
    int size = gems.size();
    int gems_cnt;
    int cnt;
    int MIN = size+1;

    for(int i=0;i<size;i++){
        m[gems[i]] = 0;
    }

    gems_cnt = m.size();

    for(int i=0;i<size - gems_cnt+1;i++){
        cnt = 0;
        for(int j=i;j<size;j++){

            if(!m[gems[j]]){
                cnt++;
                m[gems[j]] = 1;
            }

            if(cnt == gems_cnt){
                if(j-i <MIN) {
                    answer = {i+1,j+1};
                    MIN = j-i;
                }
                break;
            }

        }

        for(auto iter = m.begin(); iter != m.end();iter++){
            iter->second = 0;
        }
    }


    return answer;
}

int main(){
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> answer = solution(gems);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}