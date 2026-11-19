#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=6090;

int n;
int a[MAX],f[MAX],dp[MAX],g[MAX];
vector<int>p[MAX];

void dfs(int pos)
{
    dp[pos]=a[pos];
    g[pos]=0;
    for(auto &to:p[pos])
    {
        dfs(to);
        dp[pos]+=g[to];
        g[pos]+=max(g[to],dp[to]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int ch,fa;
        cin>>ch>>fa;
        f[ch]=fa;
        p[fa].push_back(ch);
    }
    int root=1;
    while(f[root]) root=f[root];
    memset(dp,-0x3f,sizeof(dp));
    memset(g,-0x3f,sizeof(g));
    dfs(root);
    cout<<max(dp[root],g[root])<<endl;
    return 0;
}