#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;

    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }

    for(auto iter = m.begin(); iter != m.end(); iter++){
        answer *= iter->second + 1;
    }

    answer--;

    return answer;
}

int main(){
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout<<solution(clothes);
}