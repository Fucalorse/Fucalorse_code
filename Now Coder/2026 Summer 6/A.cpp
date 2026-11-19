#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;
int p[MAX],fa[MAX],sz[MAX],used[MAX],pos[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void merge(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py) return;

    fa[px]=py;
    sz[py]+=sz[px];
    used[py]+=used[px];
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
    }

    LL ans=1;
    for(int i=n;i>=1;i--)
    {
        int pa=find(pos[i]);
        LL now=sz[pa]-used[pa];
        ans=ans*now%MOD;
        used[pa]++;

        if(pos[i]>1&&pos[i]<n)
        {
            int l=find(pos[i]-1),r=find(pos[i]+1);
            if(l!=r&&sz[l]-used[l]>0&&sz[r]-used[r]>0) merge(l,r);
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