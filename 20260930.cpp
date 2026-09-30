#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(auto& c : clothes) m[c[1]] ++;
    
    for(auto& [type, n] : m) answer *= (n+1);
    
    answer--;
    
    return answer;
}
