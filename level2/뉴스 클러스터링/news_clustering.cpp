#include <iostream>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<pair<string,bool>> str1_v;
    vector<pair<string,bool>> str2_v;
    vector<string> same;

    int str1_size = str1.size();
    int str2_size = str2.size();

    for(int i=0;i<str1_size;i++){
        if(str1[i] >='A' && str1[i] <= 'Z'){
            str1[i] += 32;
        }
    }
    
    for(int i=0;i<str2_size;i++){
        if(str2[i] >='A' && str2[i] <= 'Z'){
            str2[i] += 32;
        }
    }

    string s="";
    for(int i=0;i<str1_size-1;i++){
        if(str1[i] >='a' && str1[i] <='z'&&str1[i+1] >='a' && str1[i+1] <='z'){
            s += str1[i];
            s += str1[i+1];
            str1_v.push_back(make_pair(s,0));
            s = "";
        }
    }

    s="";
    for(int i=0;i<str2_size-1;i++){
        if(str2[i] >='a' && str2[i] <='z'&&str2[i+1] >='a' && str2[i+1] <='z'){
            s += str2[i];
            s += str2[i+1];
            str2_v.push_back(make_pair(s,0));
            s = "";
        }
    }

    for(int i=0;i<str1_v.size();i++){
        cout<<str1_v[i].first<<' ';    
    }
    cout<<'\n';

    for(int i=0;i<str2_v.size();i++){
        cout<<str2_v[i].first<<' ';    
    }
    cout<<'\n';

    for(int i=0;i<str1_v.size();i++){
        for(int j=0;j<str2_v.size();j++){
            if(str1_v[i].first == str2_v[j].first &&!str1_v[i].second &&!str2_v[j].second){
                same.push_back(str1_v[i].first);
                str1_v[i].second = 1;
                str2_v[j].second = 1;
            }
        }
    }
    if(str1_v.size()==0 && str2_v.size()==0)return 65536;

    answer = 65536*(double)same.size()/(str1_v.size() + str2_v.size() - same.size());
    return answer;
}

int main(){
    string str1 = "";
    string str2 = "shake hands";
    cout<<solution(str1,str2);
}