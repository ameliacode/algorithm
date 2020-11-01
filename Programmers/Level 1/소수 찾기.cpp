#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 2;i <= n;i++){
        bool isPrime = true;
        for(int j = 2;j < i;j++){
            if (i % j == 0)
            {
                isPrime= false;
            }
        }
        if(isPrime) answer++;
        
    }
    return answer;
}