#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int supo1[5] = {1, 2, 3, 4, 5};
    int supo2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int supo3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> cnt{0,0,0};
    for(int i =0;i<answers.size();i++){
        if (answers[i] == supo1[i%5]) cnt[0]++;
        if (answers[i] == supo2[i%8]) cnt[1]++;
        if (answers[i] == supo3[i%10]) cnt[2]++;
    }
    
    int max_num = *max_element(cnt.begin(),cnt.end());
    
    for(int i =0;i<3;i++){
        if(cnt[i] == max_num){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}