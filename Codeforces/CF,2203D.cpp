#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e6+90,LEN=2e6,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    int N=n+m;
    vector<int>cnt(N+1,0),f(N+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    for(int i=1;i<=N;i++)
    {
        if(cnt[i])
        {
            for(int x=i;x<=N;x+=i)
                f[x]+=cnt[i];
        }
    }

    int cntA=0,cntB=0,each=0;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        if(f[b[i]]==n) ++cntA;
        else if(f[b[i]]==0) ++cntB;
        else ++each;
    }

    if(each&1)
    {
        if(cntA>=cntB) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    else
    {
        if(cntA>cntB) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}