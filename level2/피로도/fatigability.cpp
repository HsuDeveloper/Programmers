#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt(int k,vector<int> v,int size,vector<vector<int>> dungeons){
    int need,use,c=0;
    for(int i=0;i<size;i++){
        need = dungeons[v[i]][0];
        use = dungeons[v[i]][1];

        if(k < need) break;
        k -= use;
        c++;
    }
    return c;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int size = dungeons.size();
    vector<int> v;
    for(int i=0;i<size;i++){
        v.push_back(i);
    }

    do{
        int t = cnt(k,v,size,dungeons);
        if(answer < t) answer = t;
    }while(next_permutation(v.begin(),v.end()));

    return answer;
}

int main(){
    int k=80;
    vector<vector<int>> dungeons = {{80,20},{50,40},{30,10}};
    
    cout<<solution(k,dungeons);
}