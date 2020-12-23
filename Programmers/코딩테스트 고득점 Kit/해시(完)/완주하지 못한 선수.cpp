#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "None";
    
    sort(participant.begin(),participant.end());        //participant와 completion을 모두 정렬한다.
    sort(completion.begin(),completion.end());
    
    for(int i=0;i<participant.size();i++){              //순서에 맞게 정렬이 되었으면 해당 위치에 이름이 나와야한다.
        if(participant[i] != completion[i]){            //그렇지 않을 경우 반환
            answer = participant[i];
            break;
        }
    }  
    return answer;
}