#include <string>
#include <vector>
#include <iostream>

using namespace std;

//2와 5의 곱이 10인 것을 착안해서 푼 문제(1676 문제와 유사)

pair<long long,long long> zero_count(long long n)
{
    long long tmp = n;
    long long two = 0;
    long long five = 0;
  
    for (long long i = 2; i <= n; i *= 2)
    {
        two += n / i;
    }
   
    for (long long i = 5; i <= n; i *= 5)
    {
        five += n / i;
    }
    return { two, five };
}

int main()
{
    long long n, m;
    cin >> n >> m;
    
    long long two = zero_count(n).first - zero_count(m).first - zero_count(n - m).first;
    long long five = zero_count(n).second - zero_count(m).second - zero_count(n - m).second;

    cout << min(two, five) << endl;
    
    return 0;
}