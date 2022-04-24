#include<iostream>
#include<set>
#include<vector>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<set<int>> setNum;

    set<int> z;
    int num = N;
    z.insert(num);
    setNum.push_back(z);

    for(int i=1;i<8;i++){
        set<int> s;

        num = 10*num + N;
        s.insert(num);
        
        for(int j=0;j<(i+1)/2;j++){
            for(set<int>::iterator itr=setNum[j].begin();itr!=setNum[j].end();++itr){
                for(set<int>::iterator itr_2=setNum[i-1-j].begin();itr_2!=setNum[i-1-j].end();++itr_2){
                    int a = *itr;
                    int b = *itr_2;
                    s.insert(a+b);
                    s.insert(a-b);
                    s.insert(b-a);
                    s.insert(a*b);
                    if(b!=0)s.insert(a/b);
                    if(a!=0)s.insert(b/a);
                }
            }
    }
        setNum.push_back(s);
    }

    for(int i=0;i<8;i++){
        for(set<int>::iterator itr=setNum[i].begin(); itr!=setNum[i].end();++itr){
            if(number == *itr) return i+1;
        }
    }
    return answer;
}

int main(){
    cout<<solution(2,11);
}