#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 최소공배수 = 두 수의 곱 / 최대공약수

int GCD(int a, int b)
{
    if(a % b == 0){
        return b;
    }
    return GCD(b, a%b);
}

int LCM(int a, int b){
    return a*b / GCD(a,b);
}

int solution(vector<int> arr) {
    int answer = 0;
    int lcm = 1;
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0;i<arr.size();i++)
    {
        lcm = LCM(lcm, arr[i]);
    }
    answer = lcm;
    return answer;
}