#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = n;
    vector<int> tern_num;
    
    //3진법
    while(num > 0){
        tern_num.push_back(num%3);
        num = num / 3;
    }
    
    for(int i = 0; i < tern_num.size();i++){
        answer += tern_num[tern_num.size() - i - 1] % 10 * pow(3, i);        
    }
    
    return answer;
}