#include <iostream>
using namespace std;

//문제 풀이 팁: 문제 그대로 해석해서 적용하는 문제!

int solution(int n)
{
    int ans = 0;
    
    while(n > 1)
    {
        if(n % 2 == 0)
            n = n / 2;    
        else
        {
            n = n - 1;
            ans++;
            n = n / 2;
        }
    }

    return ans + 1;
}