#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int size = enroll.size();
    vector<int> answer(size);
    
    // string -> numbering
    map<string,int> m;

    int d[10000];

    for(int i=0;i<size;i++){
        m[enroll[i]] = i;
        answer[i] = 0;
    }

    for(int i=0;i<size;i++){
        if(referral[i]=="-") {
            d[i] = -1;
            continue;
            }
        d[i] = m[referral[i]];
    }

    for(int i=0;i<seller.size();i++){
        int money = amount[i] * 100;
        int curr = m[seller[i]];

        while(d[curr]!=-1){
            answer[ curr ] += money - money/10;
            money = money / 10;


            curr = d[curr];

        }
        
        answer[ curr ] += money - money/10;

    }
    

    return answer;
}

int main(){
    vector<string> enroll= {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount {12, 4, 2, 5, 10};

    vector<int> answer = solution(enroll,referral,seller,amount);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}