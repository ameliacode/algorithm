#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(int count, int sum, int target, vector<int> numbers)
{
    if(count == numbers.size())
    {
        if(sum == target)
        {
            answer++;
        }
        return;
    }
    dfs(count + 1, sum + numbers[count], target, numbers);
    dfs(count + 1, sum - numbers[count], target, numbers);
}

int solution(vector<int> numbers, int target) {

    dfs(0,0,target, numbers);
    
    return answer;
}