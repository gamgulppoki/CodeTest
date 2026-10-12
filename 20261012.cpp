#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    int num = elements.size();
    set<int> st;
    
    for(int i = 1; i<=num;i++)
    {
        for(int j=0;j<num;j++)
        {
            //cout << "j: " << j << endl;
            int tmp = 0;
            for(int k=0;k<i;k++)
            {
                int idx = j + k;
                if (idx >= num) idx %= num;
                tmp += elements[idx];
            }
            st.insert(tmp);
            //cout << tmp << " ";
        }
        //cout << endl;
    }
    
    answer = st.size();
    
    return answer;
}
