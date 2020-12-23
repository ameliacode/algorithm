#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) { //우선순위 큐(오름차순) 이용
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> foods;
    
    vector<int> :: iterator iter;
    for(iter = scoville.begin(); iter != scoville.end();iter++)
    {
        if(*iter < K) foods.push(*iter);
    }
     
    while(foods.top() < K && !foods.empty())        //여기서부터는 문제에서 하라는대로..
    {
        //cout << foods.top()<<endl;
        int min_sco = foods.top();
        foods.pop();
        if (foods.empty()) return -1;
        int next_sco = foods.top();
        foods.pop();
        int mixed = min_sco + next_sco * 2;
        foods.push(mixed);
        answer++;
    }
    
    
    return answer;
}