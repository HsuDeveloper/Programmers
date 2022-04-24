#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compP(pair<string,int> &a,pair<string,int> &b){
    return a.second > b.second;
}

bool comp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    else{
        if(a.second.first > b.second.first) return true;
        else if(a.second.first < b.second.first) return false;
        else{
            if(a.second.second<b.second.second) return true;
            else return false;
        }
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    map<string,int> fre;
    map<string,int> pri_m;
    vector<pair<int,pair<int,int>>> album;

    for(int i=0;i<size;i++){
        fre[genres[i]] += plays[i];
    }

    vector<pair<string,int>> pri;

    for(auto iter = fre.begin(); iter!=fre.end();iter++){
        pri.push_back({iter->first,iter->second});
    }

    sort(pri.begin(),pri.end(),compP);

    for(int i=0;i<pri.size();i++){
        pri_m[pri[i].first] = i;
    }

    for(int i=0;i<size;i++){
        album.push_back({pri_m[genres[i]],{plays[i],i}});
    }

    sort(album.begin(),album.end(),comp);

    vector<vector<int>> album_genre(fre.size());

    for(int i=0;i<album.size();i++){
        album_genre[album[i].first].push_back(album[i].second.second);
    }

    for(int i=0; i<album_genre.size();i++){
        int cnt=0;
        for(int j=0;j<album_genre[i].size();j++){
            answer.push_back(album_genre[i][j]);
            cnt++;
            if(cnt>1) break;
        }
    }
    return answer;
}

int main(){
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays={500, 600, 150, 800, 2500};

    vector<int> answer = solution(genres,plays);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<' ';
    }
}