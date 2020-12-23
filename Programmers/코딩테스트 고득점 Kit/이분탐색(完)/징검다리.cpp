#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//구글 찬스.. 너무 어려움 ㅠㅠ
//거리를 줄여가면서 돌의 갯수를 구한다!
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = distance;

    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
        
    while(left<=right)
    {
        int removeRocks = 0;
        int prevRock = 0;
        int temp = distance + 1;
        int minDistance = (left + right)/2;
        
        for(int i = 0; i < rocks.size();i++)
        {
            if (minDistance > rocks[i] - prevRock)
            {
                removeRocks += 1;
            }
            else
            {
                temp = min(temp, rocks[i] - prevRock);
                prevRock = rocks[i];
            }
        }
        if(removeRocks <= n)
        {
            left = minDistance + 1;
            answer = temp;
        }
        else
        {
            right = minDistance - 1;
        }
    }
    
    return answer;
}