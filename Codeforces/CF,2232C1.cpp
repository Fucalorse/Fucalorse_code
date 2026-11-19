#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3090;

int T,n,x,s;
string t;

void solve()
{
    cin>>n>>x>>s>>t;t=' '+t;

    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(t[i]=='A') t[i]='I';
        int a=0,b=0,now=0;
        for(int i=1;i<=n;i++)
        {
            if(t[i]=='I'&&a<x)
            {
                ++a;
                b+=s-1;
                ++now;
            }
            else if((t[i]=='E'||t[i]=='A')&&b)
            {
                --b;
                ++now;
            }
        }
        ans=max(ans,now);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}