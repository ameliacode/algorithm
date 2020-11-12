#include <string>
#include <vector>
#include <iostream>

using namespace std;

//2와 5의 곱이 10인 것을 착안해서 푼 문제(찬스 사용)

int main()
{
    int N;
    cin >> N;
    int cnt_2 = 0;
    int cnt_5 = 0;

    for(int i = 1;i<=N;i++)
    { 
        int tmp = i;
        while (tmp > 0)
        {
            if (tmp % 2 == 0) {
                cnt_2++;
                tmp = tmp / 2;
            }
            else break;
        }
        
        tmp = i;
        while (tmp > 0)
        {
            if (tmp % 5 == 0) {
                cnt_5++;
                tmp = tmp / 5;
            }
            else break;
        }
    }

    cout << min(cnt_2, cnt_5) << endl;
    
    return 0;
}