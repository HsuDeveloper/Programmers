#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int time_toInt(string t){
    int h = stoi(t.substr(0,2)) * 60;
    int m = stoi(t.substr(3,2));

    return h + m;
}

string int_toTime(int i){
    string h = to_string( i / 60);
    string m = to_string( i % 60);
    if(h.size() == 1) h = '0' + h;
    if(m.size() == 1) m = '0' + m;
    return h+':'+m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> timetable_int;
    int size = timetable.size();

    for(int i=0;i<size;i++){
        timetable_int.push_back(time_toInt(timetable[i]));
    }

    sort(timetable_int.begin(),timetable_int.end());

    int start = 540-t;
    vector<int> crew;
    
    int p=0;
    for(int i=0;i<n;i++){
        start += t;
        int pass=0;

        while(p < size && timetable_int[p] <= start && pass < m ){
            if(i == n-1) crew.push_back(timetable_int[p]);
            pass++;
            p++;
        }
    }
    
    if(crew.size() < m) answer = int_toTime(start);
    else answer = int_toTime(crew[m-1] - 1);
    
    return answer;
}

int main(){
    int n = 2;
    int t = 10;
    int m = 2;
    vector<string> timetable = {"09:10", "09:09", "08:00"};
    // vector<string> timetable = {"08:00", "08:01", "08:02", "08:03"};

    cout<<solution(n,t,m,timetable);
}