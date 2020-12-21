#include <string>
#include <vector>

using namespace std;
//문제 풀이 팁: 요령은 없는 문제, 날 것 그대로 풀면 된다.

string binary(int n)
{
    string result="";
    while(n > 0)
    {
        if(n % 2 == 0) result = "0" + result;
        else result = "1" + result;
        n = n / 2;
    }
    return result;
}

int getCount(string result)
{
    int count = 0;
    for(int i = 0;i<result.length();i++)
    {
        if(result[i] == '1') count++;
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    string number ="";
    int count1 = 0, count2 = 0;
    
    count1 = getCount(binary(n));
    
    while(true)
    {
        string number = binary(++n);
        count2 = getCount(number);
        if(count1 == count2)
        {
            answer = n;
            break;
        }
    }
    return answer;
}