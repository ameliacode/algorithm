#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max_num = max(n,m);
    int min_num = min(n,m);
    
    for(int i = max_num; i >= 1;i--){
        if(n % i == 0 && m % i == 0){
            answer.push_back(i);
            break;
        }
    }
    
    for(int i = min_num; i <= min_num * max_num;i++){
        if(i % n == 0 && i % m == 0){
            answer.push_back(i);
            break;
        }
    }
    
    return answer;
}