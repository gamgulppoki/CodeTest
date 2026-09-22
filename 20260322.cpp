#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> disvec;
int N;
int g_dis;

bool check(int num)
{
    int cnt = 0;
    int cur = 0;
    
    for(int i=0;i < disvec.size(); i++)
    {
        cur += disvec[i];
        if(cur < num)
        {
            cnt++;
        }
        else
        {
            cur = 0;
        }
    }
    
    return cnt <= N;
}

// 최단거리 구하기
int go()
{
    int start = 0; int end = 987654321;
    
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if (!check(mid)) // 값이 안된다면
        {
            end = mid - 1;
        }
        else // 된다면
        {
            start = mid + 1;
        }
    }
    
    return end;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    N = n;
    g_dis = distance;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    for(int i=0;i<rocks.size()-1;i++)
    {
        disvec.push_back(rocks[i+1] - rocks[i]);
    }
    
    answer = go();
    return answer;
}
