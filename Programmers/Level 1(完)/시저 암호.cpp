#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char c : s)
    {
        char start = c;
        if ('a'<=c&&c<='z') start = 'a';
        else if ('A' <= c&&c<='Z') start = 'A'; 
        
        if(c != ' ') start = char(c + n - start) % 26 + start;
        answer += start;
    }
    return answer;
}