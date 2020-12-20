#include <string>
#include <vector>

using namespace std;

//규칙 찾는 문제! 1부터 100까지 더하는 유명한 가우스법칙으로 접근하면 된다.

int solution(int n) {
    int answer = 0;
    
    for(int i = 1;i <= n; i+=2) //짝수 배수일 경우 1 3 5 7와 같이 연속된 자연수로 나올 수가 없다.
    {
        if(n % i == 0) answer++;
    }
    
    return answer;
}