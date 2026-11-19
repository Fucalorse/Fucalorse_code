#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct edge
{
    int u,v;
}op[MAX];

int t,n,st;
int deg[MAX],col[MAX],f[MAX];
vector<int>p[MAX];

void clear()
{
    st=-1;
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        deg[i]=0;
    }
}

void dfs(int ch,int fa,int k)
{
    f[ch]=fa;
    col[ch]=k;
    if(k==1) cout<<ch<<' '<<fa<<endl;
    else cout<<fa<<' '<<ch<<endl;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,3-k);
    }
}

void solve()
{
    cin>>n;clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        op[i]={u,v};
        p[u].push_back(v);
        p[v].push_back(u);
        deg[u]++,deg[v]++;
    }

    int pos=-1;
    for(int i=1;i<=n;i++)
        if(deg[i]==2)
        {
            pos=i;
            break;
        }
    if(pos==-1) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        dfs(p[pos][0],pos,1);
        dfs(p[pos][1],pos,2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}