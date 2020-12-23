#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 간단해 보이지만 어떻게 효율적으로 짜야하는지 고민해야 하는 문제
int fibonacci(int n)
{
    if( n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int solution(int n) {
    int answer = 0;
    
    int a = 0,b = 1,tmp;
    //answer = fibonacci(n);        시간 초과 문제로 보류
    for(int i = 0; i < n ; i++){    //선형 방법으로 사용했더니 해결!
        tmp = b;
        b = (a + b) % 1234567;
        a = tmp;
    }
    
    answer = a;
    
    return answer;
}