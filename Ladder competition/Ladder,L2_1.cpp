#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1090;

char s[MAX];
stack<char>st;

int main()
{
    cin>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if(s[i]==')')
        {
            stack<char>ans;
            while(st.top()!='(') ans.push(st.top()),st.pop();
            st.pop();
            while(ans.size())
            {
                cout<<ans.top();
                ans.pop();
            }
            cout<<endl;
        }
        else st.push(s[i]);
    }
    return 0;
}