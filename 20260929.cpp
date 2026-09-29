#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for(int i=0;i<s.size();i++)
    {
        char curchar = s[i];
        
        if (curchar == '(')
        {
            st.push('(');
        }
        else if (curchar == ')')
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    
    if (!st.empty())
    {
        return false;
    }
    
    return true;
}
