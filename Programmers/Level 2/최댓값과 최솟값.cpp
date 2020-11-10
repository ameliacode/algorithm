#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr;
    
    string num;
    for(istringstream is (s); is >> num;)
    {
        arr.push_back(stoi(num));
    }
    
    sort(arr.begin(), arr.end());
    
    answer = to_string(arr[0]);
    answer += " ";
    answer += to_string(arr[arr.size()-1]);

    return answer;
}