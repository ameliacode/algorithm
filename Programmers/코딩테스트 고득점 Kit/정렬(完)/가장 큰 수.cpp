#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare (string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    
    for(auto num : numbers){                    // 이번 문제는 string으로 접근, 항상 숫자 나온다고 해서 정수로 접근하지 말것
        nums.push_back(to_string(num));
    }
    
    sort(nums.begin(), nums.end(), compare);
    
    for(int i = 0; i < nums.size() ;i++){
        answer += nums[i];
    }
    if(answer[0] == '0') answer = '0';      //앞자리가 0인 수도 고려
        
    return answer;
}