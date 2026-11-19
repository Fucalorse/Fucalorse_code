#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

string s;

void solve()
{
    cin>>s;
    int len=s.size();
    s=' '+s;
    
    int v=0,f=0,y=0,n=0,g=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') v++;
        else
        {
            f++;
            if(s[i]=='Y') y++;
            else if(s[i]=='N') n++;
            else if(s[i]=='G') g++;
        }
    }

    int pair_ng=min(n,g),ans=-INF;
    for(int cur=1;cur<=v+y;cur++)
    {
        int nf=cur>v?f-(cur-v):f;
        int pair=max(0,min(pair_ng,nf-2*cur));

        if(nf-pair>=2*cur)
        {
            int now=cur+pair*2+(2*cur-pair);
            ans=max(ans,now);
        }
    }

    if(ans==-INF) cout<<0<<endl;
    else cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}