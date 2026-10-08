#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

string ToUpper(string& s)
{
    string ret = "";
    for(int i=0;i<s.size();i++)
    {
        ret += tolower(s[i]);
    }
    return ret;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> cache;
    int cnt = 0;
    
    for(auto& ctmp : cities)
    {
        cnt = 5;
        string c = ToUpper(ctmp);
        int isFound = 0;
        for(auto v = cache.begin(); v != cache.end(); v++)
        {
            if (c == *v)
            {
                cache.erase(v);
                cnt = 1;
                isFound = 1;
                break;
            }
        }
        
        cache.push_back(c);
        answer += cnt;
        
        while(cache.size() > cacheSize && !cache.empty())
        {
            cache.pop_front();
        }
    }
    
    return answer;
}
