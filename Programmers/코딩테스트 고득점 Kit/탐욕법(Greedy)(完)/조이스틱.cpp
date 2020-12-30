#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

//구글 찬스..
int up_down(char c)
{
    int c_num = int(c);
    int count = 0;
    if(c_num - int('A') < int('Z') - c_num)
        count = c_num - int('A');
    else 
        count = int('Z') - c_num + 1;
    return count;
}

int solution(string name) {
    int answer = 0;
    string temp(name.length(), 'A');
    int cur = 0, left, right;
    
    while(name != temp)
    {
        answer += up_down(name[cur]);
        temp[cur] = name[cur];
        if(name == temp) break;
        
        left = cur;
        int leftcnt = 0;
        while (temp[left] == name[left])
        {
            left--;
            leftcnt++;
            
            if(left == -1) left = name.size() - 1;
        }
        
        right = cur;
        int rightcnt = 0;
        while (temp[right] == name[right])
        {
            right++;
            rightcnt++;
            
            if(rightcnt == name.size()) right = 0;
        }  
        
        if(leftcnt < rightcnt)
        {
            answer += leftcnt;
            cur = left;
        }
        else
        {
            answer += rightcnt;
            cur = right;
        }
    }

    return answer;
}