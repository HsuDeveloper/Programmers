#include<iostream>
#include<vector>

using namespace std;

pair<int,int> pad[] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

int reach(pair<int,int>a,pair<int,int>b){
    int res = abs(a.first - b.first) + abs(a.second - b.second);
    return res;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> left = make_pair(3,0);
    pair<int,int> right = make_pair(3,2);

    for(int i=0;i<numbers.size();i++){
        int num = numbers[i];
        if(num == 1 || num == 4 || num == 7 ){
            //left hand
            left = pad[num];
            answer += "L";
        }

        else if(num == 3 || num == 6 || num == 9){
            //right hand
            right = pad[num];
            answer += "R";
        }
        else{
            if(reach(left,pad[num]) > reach(right,pad[num])){
                right = pad[num];
                answer += "R";
            }
            else if(reach(left,pad[num]) < reach(right,pad[num])){
                left = pad[num];
                answer += "L";
            }
            else if(reach(left,pad[num]) == reach(right,pad[num]) && hand == "right"){
                right = pad[num];
                answer += "R";
            }
            else{
                left = pad[num];
                answer +="L";
            }
        }
    }

    return answer;
}

int main(){
    vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = "left";
    cout<<solution(numbers,hand);
}