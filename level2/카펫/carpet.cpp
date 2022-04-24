#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int btm,hgt;
    if (yellow == 1) return {3,3};

    for(int i=1;i<yellow;i++){
        if(yellow % i == 0){
            btm = yellow/i;
            hgt = i;
            if(brown == 2*btm + 2*hgt + 4){
                answer.push_back(btm+2);
                answer.push_back(hgt+2);
                cout<<btm+2<<' '<<hgt+2<<'\n';
                break;
            }
        }
    }
    
    return answer;
}

int main(){
    int brown = 8;
    int yellow = 1;

    vector<int> answer = solution(brown,yellow);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

}