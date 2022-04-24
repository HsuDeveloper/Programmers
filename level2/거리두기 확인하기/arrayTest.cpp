#include<iostream>

using namespace std;

int arrTest(int arr[][5]){
    arr[0][0] = 7;
    return arr[0][0];
}

int main(){
    int arr[5][5]={0,};
    int n = arrTest(arr);

    cout<<arr[0][0]<<' '<<n;
}