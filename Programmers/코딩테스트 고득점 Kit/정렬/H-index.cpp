#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> H_index;
    
    sort(citations.begin(), citations.end(), greater<int>());

    int size = citations.size();
    for(int i = 0;i < size;i++)
    {
        if(citations[i] > i) answer++;
        else break;
    }
     
    return answer;
}