#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> a{1,2,3,4};
    
    do{
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }while(next_permutation(a.begin(),a.end()));
}