#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curr_weight = 0;
    queue<int> bridge;          //실제 다리에 이동하는 것처럼 구현하기 위해 queue 사용

    //init
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    int index = 0;
    int truck_passed = 0;
    while (truck_passed < truck_weights.size()) // 종료 조건은 다리 도착지점인 front가 0이 아닌 경우 트럭이 도착한 것으로 봄
    {    
        answer++;
        curr_weight -= bridge.front();          //현재 무게는 도착하면 빼준다(다리에 있지 않으므로)
        bridge.pop();
        if (index < truck_weights.size() 
            && curr_weight + truck_weights[index] <= weight) // 후행 트럭과 합한 값보다 작으면 트럭 이동
        {
            bridge.push(truck_weights[index]);     
            curr_weight += truck_weights[index];
            index++;
        }
        else {
            bridge.push(0);                    // 그 외 0을 push (bridge_length 맞추기 위함)
        }        
        if (bridge.front() != 0) truck_passed++;
    }
    return answer+1;                            // 시작 시간이 0부터 시작했으므로 1을 더 더해주어야 한다.
}

int main() {

    vector<int> truck_weights(10, 10);
    
    cout << solution(100, 100, truck_weights);


    return 0;
}