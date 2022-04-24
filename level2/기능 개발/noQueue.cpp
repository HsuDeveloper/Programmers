#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int n;
    int main_n = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        n = ceil((100-progresses[i])/(double)speeds[i]);

        if (answer.empty() || main_n < n)
            answer.push_back(1);
        else
            ++answer.back();

        if (main_n < n)
            main_n = n;
    }

    return answer;
}

int main(){
    vector<int> progresses = {55,60,65};
    vector<int> speeds = {5,10,7};
    vector<int> answer = solution(progresses,speeds);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}