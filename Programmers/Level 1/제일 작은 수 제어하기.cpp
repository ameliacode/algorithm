#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() == 1){
        answer.push_back(-1); 
        return answer;
    }
    
    int min_num = *min_element(arr.begin(), arr.end());
    
    for(int i = 0;i<arr.size();i++){
        if(min_num == arr[i]) continue;
        answer.push_back(arr[i]);
    }
    
    return answer;
}