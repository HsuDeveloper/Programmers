#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp (string &a,string &b){
    int a_size = a.size();
    int b_size = b.size();
    if(a_size == b_size) return a < b;
    return a_size < b_size;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int categorys = relation[0].size();
    int members = relation.size();

    vector<string> candidateKey;
    vector<bool> comb(categorys,0);

    for(int i=0;i<categorys;i++){
        comb[categorys-1-i] = 1;
        
        do{
            string temp="";
            for(int k=0;k<categorys;k++){
                if(comb[k]) temp += to_string(k);
            }
            candidateKey.push_back(temp);
        }while(next_permutation(comb.begin(),comb.end()));
    }

    sort(candidateKey.begin(),candidateKey.end(),cmp);

    map<string,int> m;
    for(int i=0;i<candidateKey.size();i++){
        
        bool flag = 1;
        for(int j=0;j<members;j++){
            string temp = "";
            for(int k=0;k<candidateKey[i].size();k++){
                temp += to_string(candidateKey[i][k]-'0') + relation[j][candidateKey[i][k]-'0'];
            }
            if(m[temp]){
                flag = 0;
                break;
            }
            m[temp]++;
        }

        if(flag){
            answer++;
            string key = candidateKey[i];
            cout<<"key value : "<<key<<'\n';

            for(int j=i;j<candidateKey.size();j++){
                bool check;
                for(int k=0;k<key.size();k++){
                    check = 0;
                    for(int a =0;a<candidateKey[j].size();a++){
                        if(key[k] == candidateKey[j][a]) {check = 1; break;}
                    }
                    if(!check) break;
                }
                if(check) {
                    candidateKey.erase(candidateKey.begin()+j);
                    j--;
                }

            }
            i--;
        }
        
    } 
    return answer;
}

int main(){
    // vector<vector<string>> relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    vector<vector<string>> relation = {{"100","100","ryan","music","2"}, {"200","200","apeach","math","2"}, {"300","300","tube","computer","3"}, {"400","400","con","computer","4"}, {"500","500","muzi","music","3"}, {"600","600","apeach","music","2"}};
    cout<<solution(relation);
}