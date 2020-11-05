#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    int num;

    for (int i = 0; i < operations.size(); i++)
    {
        char oper = operations[i][0];
        num = stoi(operations[i].substr(2));
        switch (oper)
        {
        case 'I':           
            dq.push_back(num);
            sort(dq.begin(), dq.end());
            break;
        case 'D':
            if (!dq.empty())
            {
                if (num == 1)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }
            else continue;
            break;
        default:
            continue;
        }
    }

    if (dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }

    return answer;
}

int main()
{
    vector<string> oper{ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
    //cout << solution(oper)[0] <<" " << solution(oper)[1] << endl;
    return 0;
}