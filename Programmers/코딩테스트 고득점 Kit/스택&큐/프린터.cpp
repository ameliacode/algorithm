#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
 
bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> print;                    // 순위, priority 저장하는 벡터 선언
    queue<pair<int,int>> wait_q;                    // 큐를 pair로 둚으로써 location도 같이 움직이게끔 선언
    vector<int> find_max;                           // 미리 priority를 내림차순으로 정렬하여 최댓값 구하려고 선언

    //init
    for (int i = 0; i < priorities.size(); i++) {
        print.push_back(make_pair(0, priorities[i]));
        wait_q.push(make_pair(i,priorities[i]));
        find_max.push_back(priorities[i]);
    }

    sort(find_max.begin(), find_max.end(), compare);
    int find_idx = 0;
    int position = 0;

    while (!wait_q.empty())                                   //대기 큐가 더 이상 print할 것이 없어질 때까지 loop
    {
        if (find_max[find_idx] == wait_q.front().second) {    //최댓값이 같으면   
            print[wait_q.front().first].first = ++position;   //대기 큐에 저장된 location에 다가 순위 저장
            wait_q.pop();                                     //대기 큐에서 프린트
            find_idx++;                                       //다음 최댓값으로 이동
        }
        else {
            wait_q.push(make_pair(wait_q.front().first, wait_q.front().second));    //문제대로 뒤로 순위 push
            wait_q.pop();                                                           //앞은 pop
        }
    }

    answer = print[location].first;

    return answer;
}
