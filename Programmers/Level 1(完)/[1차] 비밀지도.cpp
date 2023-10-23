#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string binary(int num, int size)
{
    string result="";
    while(num > 0)
    {
        if(num % 2 == 0) result += "0";
        else result += "1";
        num = num / 2;
    }
    while (result.size() != size) result += "0";
    reverse(result.begin(), result.end());
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    string road ="";
    for(int i = 0;i < n ;i++)
    {
        string arr1_road = binary(arr1[i], n);
        string arr2_road = binary(arr2[i], n);
        for(int j = 0; j < n;j++)
        {        
            if(arr1_road[j] == '0' && arr2_road[j] == '0') road += " ";        
            else road += "#";  
            if (j == n - 1) 
            {
                answer.push_back(road);
                road ="";
            }
        }   
    }

    
    return answer;
}