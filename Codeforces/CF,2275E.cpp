#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    auto get=[&](int pa,int pb)
    {
        if(a[pa]==b[pb]) return 2;
        else return 1;
    };

    vector<int>pre(n+3,0),suf(n+3,0);
    pre[1]=0,suf[n]=get(n,n);

    for(int i=2;i<=n;i++)
        pre[i]=pre[i-1]+get(i-1,i-1)+get(i,i-1);

    for(int i=n-1;i>=1;i--)
        suf[i]=suf[i+1]+get(i,i+1)+get(i+1,i);

    int maxn=-INF;
    for(int i=1;i<=n;i++)
        maxn=max(maxn,pre[i]+suf[i]);

    cout<<maxn<<endl;
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