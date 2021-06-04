#include<bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/' || c=='%')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string convert(string s)
{
    string result ="";
    stack<char> st;
    reverse(s.begin(), s.end());

    for(int i=0 ; i<s.length() ; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result+=s[i];
        }
        else if(s[i] == ')')
        {
            st.push(s[i]);
        }
        else if(s[i] == '(')
        {
            while(!st.empty() && st.top() !=')')
            {
                result+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();   //popping opening bracket
            }
        }
        else
        {
            if(st.empty() || (precedence(s[i]) >= precedence(st.top())))  //note here.
            {
                st.push(s[i]);
            }
            else
            {
                while(!st.empty() && (precedence(s[i]) <= precedence(st.top())))
                {
                    result+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while(!st.empty())  //checking if something remains in stack
    {
        result+=st.top();
        st.pop();
    }

    return result;
}
int main()
{
    string s = "(a-b/c)*(a/k-l)";
    string str = convert(s);
    reverse(str.begin() , str.end());
    cout<<str;
    return 0;
}