#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e4+10,LEN=1e5+90,inf=2e9;

struct ovo
{
    int u,v,val;
    bool operator<(const ovo &a)const { return val>a.val; }
}edge[LEN];

int n,m;
int col[MAX],match[MAX];
vector<int>p[MAX];

bool dfs(int pos,int c)
{
    col[pos]=c;
    for(auto &to:p[pos])
    {
        if(col[to]==c) return false;
        if(!col[to])
        {
            bool f=dfs(to,3-c);
            if(!f) return false;
        }
    }
    return true;
}

bool dis(const int &mid)
{
    for(int i=1;i<=n;i++)
        p[i].clear(),col[i]=0;
    for(int i=1;i<=m;i++)
    {
        if(edge[i].val>mid)
        {
            p[edge[i].u].push_back(edge[i].v);
            p[edge[i].v].push_back(edge[i].u);
        }
        else break;
    }
    for(int i=1;i<=n;i++)
        if(!col[i]&&!dfs(i,1)) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    int l=0,r=-inf;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].val;
        r=max(r,edge[i].val);
    }
    sort(edge+1,edge+m+1);
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(dis(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}