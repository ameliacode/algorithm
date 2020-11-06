#include <string>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int temp = 0;
    stack<int> s;

    for (int i = 0; i < dartResult.length(); i++) {
    
        if ('0' <= dartResult[i] && dartResult[i] <= '9') {
            if (dartResult[i + 1] == '0'){
                temp = 10;
                i++;
                continue;
            }
            temp = int(dartResult[i]-'0');
            continue;
        }
        else
        {
            if (dartResult[i] == 'S') {
                s.push(temp);
            }
            else if (dartResult[i] == 'D') {
                temp =  pow(temp,2);
                s.push(temp);
            }
            else if (dartResult[i] == 'T')
            {
                temp = pow(temp, 3);
                s.push(temp);
            }

            else if (dartResult[i] == '#')
            {
                int top = s.top();
                s.pop();
                s.push(-top);
            }
            else if (dartResult[i] == '*') {
                int top = s.top() * 2;
                s.pop();
                if (!s.empty()) {
                    int next_top = s.top () * 2;
                    s.pop();
                    s.push(next_top);
                }
                s.push(top);
            }
        }      
    }
    
    while(!s.empty())
    {
        answer += s.top();
        s.pop();
    }

    return answer;
}

int main() {

    cout << solution("1T2D3D#");

    return 0;
}