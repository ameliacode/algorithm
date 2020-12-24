#include <string>
#include <vector>
#include <iostream>

using namespace std;

//문제 풀이 팁: 문제 그대로 해석해서 풀면 된다!
string binary(int n)        //이진화 
{
    string result = "";
    while (n > 0)
    {
        if (n % 2 == 0) 
            result = '0' + result;
        else
            result = '1' + result;
        n = n / 2;
    }
    return result;
}

int one_count(string s)     //0을 굳이 제거 하지 않고 1을 센 횟수만으로 바로 이진 변환
{
    int count = 0;
    for(int i = 0; i < s.length() ; i++)
    {
        if(s[i] == '1') count++;
    }
    return count;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int trans_count = 0;
    int rid_zero = 0;

    while(s.length() != 1)
    {
        int onecount = one_count(s);
        rid_zero += s.length() - onecount;
        s = binary(onecount);
        trans_count++;
    }
    answer.push_back(trans_count);
    answer.push_back(rid_zero);
    
    return answer;
}