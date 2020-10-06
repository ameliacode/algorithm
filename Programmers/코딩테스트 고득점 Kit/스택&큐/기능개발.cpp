#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days(0);

    for (int i = 0; i < speeds.size(); i++) {
        int left = 100 - progresses[i];
        int day = 0;
        if (left % speeds[i] != 0) {
            day = left / speeds[i] + 1;
        }
        else {
            day = left / speeds[i];
        }
        days.push_back(day);
    }

    bool end_flag = false;
    for (int i = 0; i < days.size(); i++) {
        int count = 0;
        for (int j = i; j < days.size(); j++) {
            if (days[i] >= days[j]) {
                count++;
            }
            else {
                answer.push_back(count);
                i = j - 1;
                break;
            }
            if (j == days.size() - 1) {
                answer.push_back(count);
                end_flag = true;
                break;
            }
        }
        if (end_flag == true) {
            break;
        }
    }
   
    return answer;
}