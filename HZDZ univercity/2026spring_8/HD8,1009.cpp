#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90;

int t;
string s;

void solve()
{
    cin>>s;s=' '+s;
    int len=s.size()-1,ans=0;
    unordered_map<char,int>pre;
    pre['R']=pre['W']=pre['B']=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='R')
        {
            if(pre['B']) ++pre['R'],--pre['B'];
            else if(pre['W']) ++pre['R'],--pre['W'];
            else
            {
                ++ans;
                ++pre['R'];
            }
        }
        else if(s[i]=='B')
        {
            if(pre['R']) ++pre['B'],--pre['R'];
            else if(pre['W']) ++pre['B'],--pre['W'];
            else
            {
                ++ans;
                ++pre['B'];
            }
        }
        else
        {
            if(!ans) ans=1;
            pre['W']=ans;
            pre['B']=pre['R']=0;
        }
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