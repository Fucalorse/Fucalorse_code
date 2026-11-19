#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
int p[MAX],fa[MAX],sz[MAX],used[MAX],minn[MAX],pos[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        sz[i]=1;
        used[i]=0;
    }
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        pos[p[i]]=i;
        minn[i]=p[i];
    }

    LL ans=1;
    for(int i=n;i>=1;i--)
    {
        int cur=find(pos[i]);
        ans=ans*(sz[cur]-used[cur])%MOD;
        used[cur]++;

        if(pos[i]>1&&pos[i]<n)
        {
            int l=find(pos[i]-1),r=find(pos[i]+1);
            if(l!=r&&i>minn[l]&&i>minn[r])
            {
                fa[l]=r;
                sz[r]+=sz[l];
                used[r]+=used[l];
                minn[r]=min(minn[r],minn[l]);
            }
        }
    }

    cout<<ans<<endl;
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