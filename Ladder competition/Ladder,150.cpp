#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e4+90;

bool operator<(const vector<int>&a,const vector<int>&b)
{
    for(size_t i=0;i<a.size()&&i<b.size();i++)
        if(a[i]!=b[i]) return a[i]<b[i];
    return false;
}

int n,k;
int nxt[MAX],f[MAX];
bool vis[MAX];
vector<int>p[MAX];
vector<vector<int>>ans;

int dfs(int u)
{
    if(f[u]) return f[u];
    f[u]=1;
    for(auto &v:p[u])
    {
        int now=dfs(v)+1;
        if(now>f[u]) f[u]=now,nxt[u]=v;
        else if(now==f[u]&&v<nxt[u]) nxt[u]=v;
    }
    // cout<<u<<' '<<nxt[u]<<endl;
    return f[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int u=0;u<n;u++)
    {
        nxt[u]=-1;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            int v;
            cin>>v;
            p[u].push_back(v);
        }
    }
    for(int i=0;i<n;i++)
        dfs(i);
    int maxn=0;
    for(int i=0;i<n;i++)
        maxn=max(maxn,f[i]);
    cout<<maxn<<endl;
    for(int i=0;i<n;i++)
        if(f[i]==maxn)
        {
            vector<int>now;
            for(int j=i;j!=-1;j=nxt[j])
                now.push_back(j);
            ans.push_back(now);
        }
    sort(ans.begin(),ans.end());
    for(size_t i=0;i<ans.front().size();i++)
    {
        if(i) cout<<' ';
        cout<<ans.front()[i];
    }
    return 0;
}