#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
    vector<char> op_level;

    vector<string> exp_v;
    string s="";
    for(int i=0;i<expression.size();i++){
        char c = expression[i];

        if(c=='+'||c=='-'||c=='*'){
            num.push_back(stoi(s));
            op.push_back(c);
            s="";
            if(find(op_level.begin(),op_level.end(),c) == op_level.end()) op_level.push_back(c);
        }
        else{
            s += c;
        }
    }
    num.push_back(stoi(s));

    sort(op_level.begin(),op_level.end());

    do{
        vector<long long>temp_num = num;
        vector<char> temp_op = op;

        for(int i=0;i<op_level.size();i++){
            for(int j=0;j<temp_op.size();j++){

                if(op_level[i] == temp_op[j]){
                    switch (temp_op[j])
                    {
                    case '*':
                        temp_num[j] *= temp_num[j+1];
                        break;
                    case '+':
                        temp_num[j] += temp_num[j+1];
                        break;
                    case '-':
                        temp_num[j] -= temp_num[j+1];
                        break;
                    
                    default:
                        break;
                    }

                    temp_num.erase(temp_num.begin()+j+1);
                    temp_op.erase(temp_op.begin() + j);
                    j--;
                }
            }
        }

        if(temp_num[0] < 0) temp_num[0] = -temp_num[0];
        if(answer < temp_num[0]) answer = temp_num[0];
    }
    while(next_permutation(op_level.begin(),op_level.end()));

    return answer;
}

int main(){
    string expression = "100-200*300-500+20";
    cout<<solution(expression);
}