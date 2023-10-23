#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {   //에라토스테네스의 체 | 구글 찬스 사용..
    int answer = 0;
    bool *prime = new bool[n+1];
    
    for(int i = 0; i <= n; i++)
        prime[i] = true;
    
    for(int i = 2 ;i<=int(sqrt(n));i++){
        if(prime[i])
        {
            for(int j = i;i*j<= n;j++)
            {
                prime[i * j]=false;
            }
        }
       
    }
    
    for(int i = 2;i<=n;i++)
    {
        if(prime[i]) answer++;
    }
    return answer;
}