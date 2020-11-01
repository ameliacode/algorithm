#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int temp = x;
    
    int hashad = 0;
    while (temp > 0){
        hashad += temp % 10;
        temp = temp / 10;
    }
    
    if (x % hashad == 0) answer = true;
    else answer = false;
    
    return answer;
}