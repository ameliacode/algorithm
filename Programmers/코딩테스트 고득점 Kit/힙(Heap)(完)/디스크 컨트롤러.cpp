#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second > b.second;
	}
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int end_time = 0;
    int i = 0;   
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> schedule; //우선순위 큐 생성, 가장 작은 길이 부터 정렬
    sort(jobs.begin(), jobs.end()); // 시작점 기준으로 오름차순 정렬

    while(i < jobs.size() || !schedule.empty()) // 인덱스가 jobs 사이즈보다 작거나 스케쥴이 안 비어있을 경우
    {
        if(i < jobs.size() && end_time >= jobs[i][0])   // 다른 테스크가 끝났을 때 이미 도착한 테스크들(테스트 2 참고)
        {         
            schedule.push(make_pair(jobs[i][0], jobs[i][1]));   안에 넣어준다
            i++;
            continue;
        }
        
        if(!schedule.empty())   // 위 대기 테스크들이 존재할 경우
        {     
            end_time += schedule.top().second;  // 끝시간 계산
            answer += end_time - schedule.top().first;        // 끝시간 - 앞에 대기한 시간 
            schedule.pop();                                   // 태스크가 처리되었으므로 pop
        }
        else end_time = jobs[i][0];                           // 존재하지 않으면 이전 end_time 저장
    }
    
    return answer / jobs.size();
}