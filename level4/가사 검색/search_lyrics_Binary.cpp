#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a,const string &b){
    int sizeA = a.size();
    int sizeB = b.size();

    if(sizeA!=sizeB) return sizeA<sizeB;
    return a<b;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    vector<string> rwords(words);
    for(int i=0;i<rwords.size();i++){
        reverse(rwords[i].begin(),rwords[i].end());
    }

    sort(words.begin(),words.end(),comp);
    sort(rwords.begin(),rwords.end(),comp);

    for(string query : queries){
        
        string start = query;
        string end = query;
        int size = query.size();

        if(query[0] != '?'){
            for(int i=0;i<size;i++){
                if(start[i]=='?') start[i] = 'a';
            }

            auto start_n = lower_bound(words.begin(),words.end(),start,comp);

            for(int i=0;i<size;i++){
                if(end[i]=='?') end[i] = 'z';
            }

            auto end_n = upper_bound(words.begin(),words.end(),end,comp);

            answer.push_back(end_n - start_n);
        }

        else{
            reverse(start.begin(),start.end());
            reverse(end.begin(),end.end());
            for(int i=0;i<size;i++){
                if(start[i]=='?') start[i] = 'a';
            }

            auto start_n = lower_bound(rwords.begin(),rwords.end(),start,comp);

            for(int i=0;i<size;i++){
                if(end[i]=='?') end[i] = 'z';
            }

            auto end_n = upper_bound(rwords.begin(),rwords.end(),end,comp);

            answer.push_back(end_n - start_n);
        }
    }

    return answer;
}

int main(){
    vector<string> words={"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries={"fro??", "????o", "fr???", "fro???", "pro?"};
    
    vector<int> answer = solution(words,queries);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}