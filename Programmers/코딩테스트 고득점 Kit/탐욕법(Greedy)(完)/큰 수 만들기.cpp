#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//구글 찬스..
string solution(string number, int k) {
    string answer = "";
    vector<int> nums;
    
    for(int i = 0;i<number.length();i++)
    {
        nums.push_back(number[i]);
    }
    
    int start = 0;
   
    for(int i = 0;i<number.length() - k;i++)
    {
        int max = nums[start];
        int maxIdx = start;
        for(int j = start; j <= k+i;j++)
        {
            if(max < nums[j])
            {
                max = nums[j];
                maxIdx = j;
            }
        }
        start = maxIdx +1;
        answer += max;
    }
    
    return answer;
}