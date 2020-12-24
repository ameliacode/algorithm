#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

//문제 풀이 팁: 문제 그대로 해석하면 된다!

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.length();i++)
    {
        if(i == 0 || s[i-1] == ' ')
        {
            if('a' <= s[i] && s[i] <= 'z')
            {
                s[i] = s[i] - ('a'-'A');
            }
        }
        else
        {
            if('A'<= s[i]&&s[i]<= 'Z')
            {
                s[i] = s[i] + ('a'-'A');
            }

        }
        answer += s[i];
    }
    
    return answer;
}