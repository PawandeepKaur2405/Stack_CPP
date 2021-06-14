#include<iostream>
#include<stack>
using namespace std;

void reverse(string s)
{
    stack<string> st;
    string word = "";

    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ')
        {
            st.push(word);
            word = "";
        }
        else
        {
            word+=s[i];
        }
        
    }
    st.push(word);  //for last word of sentence

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    string s = "Hello! How are you doing?";
    reverse(s);

    return 0;
}