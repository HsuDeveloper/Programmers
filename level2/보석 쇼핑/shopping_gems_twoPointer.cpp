#include<iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2,0);
    map<string,bool> m;
    map<string,int> check;

    int size = gems.size();
    int MIN = size+1;

    for(int i=0;i<size;i++){
        m[gems[i]] = 0;
    }

    int gems_cnt = m.size();
    int start=0;
    int end=0;

    check[gems[0]]++;
    while(true){
        if(check.size() == gems_cnt){
            if(end-start < MIN){
                MIN = end-start;
                answer = {start+1,end+1};
            }
            check[gems[start]]--;
            if(!check[gems[start]]) check.erase(gems[start]);
            start++;
        }

        else{
            end++;
            if(end == size) break;
            check[gems[end]]++;
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