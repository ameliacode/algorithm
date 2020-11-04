#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int day = 0;
    int months[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    string days[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    for(int i = 0;i < a;i++)
    {
        day += months[i];
    }
    day += b - 1;
    answer = days[day % 7];
    
    return answer;
}