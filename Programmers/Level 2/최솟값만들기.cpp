#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//문제 풀이: 예시에서 규칙 찾는 것이 포인트였던 문제
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int i,j;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(i = 0, j = B.size() - 1; i < A.size(), j >= 0; i++, j--)
    {
        answer += A[i] * B[j];
    }

    return answer;
}