#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//시간 초과 → 결국에는 이분탐색으로 풀어야 한다!
//이분 탐색을 까먹어서 결국에는 다시 공부하고 구글 찬스 사용..

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long minTime = 1;
    long long maxTime = *max_element(times.begin(), times.end()) * (long long) n; //최대 시간 선정
    long long avgTime = 0;
     
    while(minTime <= maxTime)
    {
        long long total = 0;
        avgTime = (minTime + maxTime) / 2;
        for(auto t: times) total += avgTime / t; //평균 시간 동안 몇 명 심사 가능?
        if (n > total) 
            minTime = avgTime + 1;
        else {
            maxTime = avgTime - 1;
            answer = avgTime;
        }
    }
    return answer;
}