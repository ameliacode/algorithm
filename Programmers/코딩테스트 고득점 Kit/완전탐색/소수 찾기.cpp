#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool chk(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<int> nums;
    
    for(int i = 0;i<numbers.length();i++) {
        nums.push_back(int(numbers[i] - '0'));
    }
    sort(nums.begin(), nums.end());
    vector<int> temp;
    
    do{
        for(int i = 0;i<= nums.size();i++)    
        {
            int tmp = 0;
            for(int j = 0; j < i ;j++)  //0에서 i까지 조합 
            {
                tmp = tmp * 10 + nums[j];
                temp.push_back(tmp);
            }
        }
    }while(next_permutation(nums.begin(), nums.end()));
    
    sort(temp.begin(),temp.end());                                  //오름차순 정렬
    temp.erase(unique(temp.begin(), temp.end()), temp.end());       //중복 제거
    
    for(int i = 0;i<temp.size();i++)
    {
        if(chk(temp[i])) answer++;
    }
    
    return answer;
}