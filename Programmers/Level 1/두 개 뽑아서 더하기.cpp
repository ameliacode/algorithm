#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> nums = numbers;
    set<int> s;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0;i < nums.size() - 1; i++){
        for(int j = i + 1 ; j < nums.size() ; j++){
            int number = numbers[i] + numbers[j];
            s.insert(number);
        }
    }
    
    set<int> :: iterator iter;
    for(iter = s.begin(); iter != s.end();iter++){
        answer.push_back(*iter);
    }
    
    sort(answer.begin(),answer.end());    
    
    return answer;
}