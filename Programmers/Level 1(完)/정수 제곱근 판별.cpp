#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long nn = sqrt(n);
    
    if (nn * nn == n) answer = (nn+1)*(nn+1);
    else answer = -1;
    return answer;
}