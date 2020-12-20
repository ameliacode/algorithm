#include <string>
#include <vector>

using namespace std;
// 해당 문제는 규칙을 찾는 것이 포인트!
string solution(int n) {
    string answer = "";
    int numbers[3]={4,1,2};
    
    while (n > 0)
    {
        answer = to_string(numbers[n % 3]) + answer;
        if (n % 3 == 0) n = n/3 - 1; //나머지가 0일 때 발생하는 예외 처리
        else n /= 3;
    }
    
    return answer;
}