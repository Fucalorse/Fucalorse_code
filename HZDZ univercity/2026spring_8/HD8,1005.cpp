#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90;

int t;
int pre1[MAX],pre0[MAX];
string s;

void cal_0()
{
    int len=s.size()-1;
    stack<int>st;
    for(int i=len;i>=1;i--)
    {
        if(s[i]=='0')
        {
            while(st.size())
            {
                pre0[st.top()]=i;
                st.pop();
            }
            pre0[i]=i;
        }
        else st.push(i);
    }
    while(st.size())
    {
        pre0[st.top()]=0;
        st.pop();
    }
}

void cal_1()
{
    int len=s.size()-1;
    stack<int>st;
    for(int i=len;i>=1;i--)
    {
        if(s[i]=='1')
        {
            while(st.size())
            {
                pre1[st.top()]=i;
                st.pop();
            }
            pre1[i]=i;
        }
        else st.push(i);
    }
    while(st.size())
    {
        pre1[st.top()]=0;
        st.pop();
    }
}

void solve()
{
    cin>>s;s=' '+s;
    int len=s.size()-1;
    cal_0(),cal_1();
    LL ans=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='0') ans+=i-pre1[i]+pre1[i]*2;
        else ans+=pre0[i]*2;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}