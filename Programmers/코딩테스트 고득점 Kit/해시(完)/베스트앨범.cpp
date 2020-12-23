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
    map<string, int> genres_cnt;                //사전처럼 접근 가능: map
    vector<pair<string, int>> genre_cnt;        //장르명, 총 장르재생 횟수을 sort하기 위해 선언
    vector<pair<string, pair<int, int>>> song_info; //장르명, 고유번호, 재생횟수

    for (int i = 0; i < genres.size(); i++) {
        genres_cnt[genres[i]] += plays[i];      //장르별 재생된 횟수
    }

    map<string, int> ::iterator iter = genres_cnt.begin();
    
    for (iter = genres_cnt.begin(); iter != genres_cnt.end(); iter++) {
        genre_cnt.push_back(make_pair(iter->first, iter->second));
    }

    sort(genre_cnt.begin(), genre_cnt.end(),compare);
   
    for (int i = 0; i < genres.size(); i++) {  // 노래 정보 넣기
        song_info.push_back(make_pair(genres[i], make_pair(i, plays[i])));
    }

    sort(song_info.begin(), song_info.end(), compare2); // 재생횟수 기준으로 정렬

    for (int i = 0; i < genre_cnt.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < song_info.size(); j++) {
            if (song_info[j].first == genre_cnt[i].first) {  //최대 재생된 장르 == 이미 재생횟수로 어느정도 정렬된 노래 정보
                temp.push_back(song_info[j].second.first);    // 고유번호 저장
            }
        }
        if (temp.size() >= 2) {     //2개 이상은 2개만큼 앨범에 넣기
            answer.push_back(temp[0]);
            answer.push_back(temp[1]);
        }
        else {                      // 그외 하나 넣는다
            answer.push_back(temp[0]);
        }
    }
    
    return answer;
}