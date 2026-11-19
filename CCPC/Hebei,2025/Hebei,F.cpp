#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=20;

int n,q;
int f[MAX][LEN+3],cnt[MAX][LEN+3],depth[MAX],a[MAX];
vector<int>p[MAX],pre[MAX];

void dfs(int ch,int fa)
{
    pre[a[ch]].push_back(ch);

    depth[ch]=depth[fa]+1;
    f[ch][0]=pre[a[ch]+1].empty()?0:pre[a[ch]+1].back();
    cnt[ch][0]=1;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
    }
    pre[a[ch]].pop_back();
}

void create()
{
    dfs(1,0);
    for(int k=1;(1<<k)<=n;k++)
        for(int i=1;i<=n;i++)
        {
            f[i][k]=f[f[i][k-1]][k-1];
            cnt[i][k]=cnt[i][k-1]+cnt[f[i][k-1]][k-1];
        }    
}

int query(int pos,int ed)
{
    int ans=1;
    for(int k=LEN;k>=0;k--)
    {
        int aft=f[pos][k];
        if(aft&&depth[aft]>=depth[ed])
        {
            ans+=cnt[pos][k];
            pos=aft;
        }
    }
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        p[fa].push_back(i);
        p[i].push_back(fa);
    }
    create();
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<query(u,v)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}