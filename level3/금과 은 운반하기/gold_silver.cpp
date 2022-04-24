#include <iostream>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 1e9 * 1e5 * 4;
    int size = g.size();

    long long start = 0;
    long long end = 1e9 * 1e5 * 4;
    long long mid;

    while(start <= end){
        mid = (start+end)/2;

        long long gold_store=0;
        long long silver_store=0;
        long long total_store=0;

        for(int i=0;i<size;i++){
            int gold = g[i];
            int silver = s[i];
            int weight = w[i];
            int time = t[i];

            long long cnt = mid / (2*time);
            if(mid % (2*time) >= time ) cnt++;

            if(gold < cnt * weight) gold_store += gold;
            else gold_store += weight * cnt;
            if(silver < cnt * weight) silver_store += silver;
            else silver_store += weight * cnt;
            if(gold + silver < cnt*weight) total_store += gold+silver;
            else total_store += weight * cnt;
        }

        if(gold_store >=a && silver_store >= b && total_store >= a+b){
            end = mid-1;
            answer = min(mid,answer);
        }
        else start = mid+1;
    }

    return answer;
}

int main(){
    int a=90;
    int b=500;
    vector<int> g={70,70,0};
    vector<int> s={0,0,500};
    vector<int> w={100,100,2};
    vector<int> t={4,8,1};

    cout<< solution(a,b,g,s,w,t);
}