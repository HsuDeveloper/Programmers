#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Trie{
    Trie* ch[26];
    int cnt;
    
    public:
    Trie():ch(),cnt(0){}

    void insert_trie(string str){
        Trie* curr = this;
        for(char c : str){
            curr->cnt++;
            if(curr->ch[c-'a'] == nullptr) curr->ch[c-'a'] = new Trie();
            
            curr = curr->ch[c-'a'];
        }
    }

    int search_trie(string str){
        Trie* curr = this;

        for(char c : str){
            if(c == '?') return curr->cnt;
            if(curr->ch[c-'a'] == nullptr) return 0;

            curr = curr->ch[c-'a'];
        }

        return curr->cnt;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    Trie nT[10000];
    Trie rT[10000];

    for(string s : words){
        nT[s.size()-1].insert_trie(s);
        reverse(s.begin(),s.end());
        rT[s.size()-1].insert_trie(s);
    }

    for(string s : queries){

        if(s[0]!='?') answer.push_back(nT[s.size()-1].search_trie(s));
        else {
            reverse(s.begin(),s.end());
            answer.push_back(rT[s.size()-1].search_trie(s));
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