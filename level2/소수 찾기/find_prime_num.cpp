#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool find(int n){
    if(n<=1) return 0;
    if(n==2) return 1;

    for(int i=2;i<sqrt(n) + 1;i++){
        if(n%i == 0)return 0;
    }
    return 1;
}

int solution(string numbers) {
    int answer = 0;
    int MAX,MIN,size = numbers.size();
    vector<char> v;
    vector<string> prime;
    int n[10]={0,};

    for(int i=0;i<size;i++){
        v.push_back(numbers[i]);
        n[numbers[i]-'0']++;
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    MIN = v[size-1] - '0';
    
    string s_MAX="";
    for(int i=0;i<size;i++){
        s_MAX += v[i];
    }

    MAX = stoi(s_MAX);

    for(int i=MIN;i<=MAX;i++){
        if(find(i)) prime.push_back(to_string(i));
    }

    if(prime.size()==0) return 0;
    
    int nc[10] = {0,};
    for(int i=0;i<prime.size();i++){
        bool flag = 1;
        
        for(int j=0;j<prime[i].size();j++){
            nc[prime[i][j]-'0'] ++;
        }

        for(int k=0;k<10;k++){
            if(n[k]<nc[k]){
                flag = 0;
                break;
            }
        }

        if(flag) answer++;
        fill_n(nc,10,0);
    }
    return answer;  
}


int main(){
    string numbers = "17";
    cout<<solution(numbers);
}