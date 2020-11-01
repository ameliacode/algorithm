#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
    return a > b;  
}
string solution(string s) {
    string answer = "";
    vector<int> arr;
    
    for(int i = 0;i<s.length();i++){
        arr.push_back(s[i]);
    }  
    sort(arr.begin(),arr.end(), compare);
    
    for(int i = 0;i<arr.size();i++){
        answer+= arr[i];
    }
    cout <<answer<<endl;
    return answer;
}