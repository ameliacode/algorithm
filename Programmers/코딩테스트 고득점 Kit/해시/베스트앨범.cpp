#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool compare2(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
    if (a.second.second == b.second.second) {
        return a.second.first < b.second.first;
    }
    return a.second.second > b.second.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_cnt;                    //장르 총 재생 횟수 저장
    vector<pair<string, int>> genre_cnt;            //장르 총 재생 횟수 정렬용
    vector<pair<string, pair<int, int>>> song_info; // 장르, 고유번호, 재생횟수 

    for (int i = 0; i < genres.size(); i++) {
        genres_cnt[genres[i]] += plays[i];      //장르별 재생된 횟수
    }

    map<string, int> ::iterator iter = genres_cnt.begin();
    
    for (iter = genres_cnt.begin(); iter != genres_cnt.end(); iter++) {
        genre_cnt.push_back(make_pair(iter->first, iter->second));
    }

    sort(genre_cnt.begin(), genre_cnt.end(),compare);   //장르 총 재생 횟수 정렬
   
    for (int i = 0; i < genres.size(); i++) {
        song_info.push_back(make_pair(genres[i], make_pair(i, plays[i])));
    }

    sort(song_info.begin(), song_info.end(), compare2); //미리 재생횟수에 따라 곡 정보들 정렬

    for (int i = 0; i < genre_cnt.size(); i++) {    //장르 재생 횟수
        vector<int> temp;
        for (int j = 0; j < song_info.size(); j++) {    //총 곡 중에서
            if (song_info[j].first == genre_cnt[i].first) {    // 해당 장르와 같으면
                temp.push_back(song_info[j].second.first);     // 일단 넣는다(미리 정렬되어 있으므로)
            }   
        }
        if (temp.size() >= 2) { // 2개 이상이면 상위 2개만 저장
            answer.push_back(temp[0]);
            answer.push_back(temp[1]);
        }
        else {  // 1개만 저장
            answer.push_back(temp[0]);
        }
    }
    
    return answer;
}

int main() {

    vector<string> genres{
        "classic","pop", "classic", "classic", "pop"
    };

    vector<int> plays{
        500,600,150,800,2500
    };

    vector<int> answer = solution(genres, plays);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}