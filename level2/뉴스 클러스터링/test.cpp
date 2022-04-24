#include<iostream>

using namespace std;

int main(){
    string str = "";
    cout<<str.size();
    int n = str.size();
    for(int i=0; i<n-1;i++){
        cout<<"why\n";
    }
    //str.size() : unsigned int, str.size() > unsigned int
    //str.size() - 1 == big int
    // like loop
    // for(int i=0; i< str.size()-1;i++){
    //     cout<<"why\n";
    // }
}