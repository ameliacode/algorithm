#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> hash;

    for (vector<string> pair : clothes) {
        hash[pair[1]]++;
    }

    unordered_map<string, int> ::iterator iter;
    for (iter = hash.begin(); iter != hash.end(); iter++)
    {
        answer *= iter->second + 1;
    }
    return answer - 1;
}

int main() {
    
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int n;
        cin >> n;

        vector<vector<string>> clothes;
        for (int j = 0; j < n; j++) {
            vector<string> cloth(2);
            
            cin >> cloth[0] >> cloth[1];
            clothes.push_back(cloth);
        }
        
        cout << solution(clothes) << endl;
    }

    return 0;
}