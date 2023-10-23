#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int location = 0;
    for(int i = 0;i<seoul.size();i++){
        if(seoul[i] == "Kim"){
            location = i;
            answer = "김서방은 ";
            answer += to_string(i);
            answer += "에 있다";
            break;
        }
    }
    return answer;
}