#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;
const LL inf=1e18;

struct qwq
{
    LL cnt;
    int col;
    bool operator<(const qwq &a)const { return cnt>a.cnt; }
};

int T,n,m;
LL a,b;
LL cnt[MAX],f[MAX],g[MAX],col[550][550];

void clear()
{
    for(int i=0;i<=n*m;i++)
    {
        cnt[i]=0;
        f[i]=g[i]=0;
    }
}

void solve()
{
    cin>>n>>m>>a>>b;clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>col[i][j];
            cnt[col[i][j]]++;
        }
    
    vector<qwq>op;
    op.push_back({inf,-1});
    for(int i=1;i<=n*m;i++)
        if(cnt[i]!=0) op.push_back({cnt[i],i});
    sort(op.begin(),op.end());

    int len=op.size()-1;
    for(int i=1;i<=len;i++)
    {
        f[i]=f[i-1]+min(a,b*(i-1))*op[i].cnt;
        g[i]=g[i-1]+a*op[i].cnt;
    }

    LL ans=(n*m-cnt[0])*a;
    // cout<<ans<<' ';
    for(int i=1;i<=len;i++)
    {
        LL now=f[i]-f[1]+g[len]-g[i]+cnt[0]*i*b;
        ans=min(ans,now);
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