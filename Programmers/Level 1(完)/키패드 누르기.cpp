#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left = 10, right = 12;
    int leftDist = 0, rightDist = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        switch (numbers[i]) {
        case 1: case 4: case 7:
            //cout << left << " " << right << endl;
            answer += 'L';
            left = numbers[i];         
            break;
        case 3: case 6:case 9:
            //cout << left << " " << right << endl;
            answer += 'R';
            right = numbers[i];          
            break;
        case 2: case 5: case 8: case 0:
            if(numbers[i] == 0) numbers[i] = 11;
            leftDist = abs(numbers[i] - left);
            rightDist = abs(numbers[i] - right);
                
            leftDist = leftDist / 3 + leftDist % 3;
            rightDist = rightDist / 3 + rightDist % 3;
                
            if (leftDist > rightDist ) {
                right = numbers[i];
                answer += 'R';
            }
            else if (leftDist < rightDist)
            {
                left = numbers[i];
                answer += 'L';
            }
            else {
                if (hand == "right") {
                    answer += 'R';
                    right = numbers[i];
                }
                else {
                    answer += 'L';
                    left = numbers[i];
                }
            }
            break;
        default:
            continue;
        }
        //cout << answer << endl;
    }
    return answer;
}

int main() {

    solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
    return 0;
}