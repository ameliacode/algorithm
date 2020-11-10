#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    bool answer = true;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else 
            {
                answer = false;
                break;
            }
        }
    }
    if(!st.empty()) answer = false;

    return answer;
}