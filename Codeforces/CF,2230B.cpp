#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,inf=2e9;

int T;
int f[MAX],g[MAX];
string s;

void solve()
{
    cin>>s;s=' '+s;
    int n=s.size()-1,c4=0;

    for(int i=1;i<=n;i++)
    {
        int now=s[i]=='1'||s[i]=='3';
        f[i]=f[i-1]+now;
        g[i]=g[i-1]+(s[i]=='2');

        if(s[i]=='4') ++c4;
    }

    int ans=inf;
    for(int i=1;i<=n;i++)
    {
        int now=f[i-1]+g[n]-g[i];
        ans=min(ans,now);
    }

    cout<<ans+c4<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}