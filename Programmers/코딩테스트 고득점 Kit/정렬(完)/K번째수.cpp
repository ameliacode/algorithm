#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i =0;i<commands.size();i++){
        vector<int> arr;
        int start = commands[i][0]-1;
        int end = commands[i][1] - 1;
        
        for(int j =start;j<=end;j++){
            arr.push_back(array[j]);
        }
        
        sort(arr.begin(), arr.end());
        int index = commands[i][2] - 1;
        answer.push_back(arr[index]);
    }
    
    return answer;
}