#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    
    int pos = 0;
    
    vector<int> vec;
    
    int tmp = 0;
    vec.push_back(0);
    for(auto& s : sequence)
    {
        tmp += s;
        vec.push_back(tmp);
    }
    
    int left = 0;
    int right = 0;
    
    int ret = 0;
    int len = 987654321;
    while(left < vec.size() && right < vec.size())
    {
        ret = vec[right] - vec[left];
        //cout << "ret: " << ret << endl;
        if (ret < k)
        {
            right ++;
        }
        if (ret > k)
        {
            left++;
        }
        
        if (ret == k)
        {
            int tmplen = right - left;
            if (tmplen < len)
            {
                answer[0] = left; answer[1] = right - 1;
                len = tmplen;
            }
            right ++;
        }
    }
    
    return answer;
}
