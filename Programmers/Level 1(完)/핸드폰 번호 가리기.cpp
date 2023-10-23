#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    string back = "";
    for(int i = phone_number.size() - 4; i < phone_number.size();i++)
    {
        back += phone_number[i];
    }
    for(int i = 0;i<phone_number.size()-4;i++){
        answer+='*';
    }
    answer += back;

    return answer;
}