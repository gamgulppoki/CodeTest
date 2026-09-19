// 2023 카카오 기출 표현 가능한 이진트리

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1 1 1 1 1

void dfs(int start, int end, int rootidx, vector<pair<char, int>>& vec, bool& f)
{
    if (f == false)
    {
        return;
    }
    
    // 끝과 시작 판단
    if (rootidx < start || rootidx > end || vec[rootidx].second == 1)
    {
        return;
    }
    if (start == end) return;
    
    vec[rootidx].second = 1;
    
    int length = (end - start) / 2; // 3 / 2 -> 1
    
    int leftidx = -1;
    int rightidx = vec.size();
    
    leftidx  = (start + rootidx - 1) / 2;
    rightidx = (rootidx + 1 + end) / 2;
    
    // 0이면 리프노드 없는지 확인
    // 리프노드 있으면 못만듦
    if (vec[rootidx].first == '0')
    {
        if (vec[leftidx].first != '0' || vec[rightidx].first != '0')    f = false;
        
        if(f == false) return;
    }
    
    // 왼쪽 처리
    dfs(start, rootidx-1, leftidx, vec, f);
    
    // 오른쪽 처리
    dfs(rootidx+1, end , rightidx, vec, f);
    
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(auto& n : numbers)
    {
        // 숫자, visited
        vector<pair<char, int>> vec;
        
        int len = 0;
        while((n >> len) > 0) len++;
        
        int full = 1;
        while(full < len) full = full * 2 + 1;
        int pad = full - len;
        
        while (pad > 0)
        {
            vec.push_back({'0', 0});
            pad--;
        }
        
        for(int i=len-1;i>=0;i--)
        {
            if ((n >> i) & 1)   vec.push_back({'1', 0});
            else                vec.push_back({'0', 0});
        }
        
        // 재귀로 확인
        int rootidx = full / 2;
        bool flag = true;
        
        dfs(0, full-1, rootidx, vec, flag);
        
        answer.push_back(flag);
    }
    
    return answer;
}
