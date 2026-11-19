#include <bits/stdc++.h>
using namespace std;

const int MAX=15,LEN=1e5+90;

string s;
int k;
int f[MAX],ans[LEN];
bool op[MAX][MAX],vis[MAX];

int dfs(int pos)
{
    if(vis[pos]) return 0;
    vis[pos]=true;
    int cnt=0;
    for(int to=1;to<=9;to++)
        if(op[pos][to]&&!vis[to])
            cnt+=dfs(to);
    return cnt+1;
}

int cal(const int &x,int len)
{
    for(int i=0;i<len;i++)
        ans[i]*=x;
    for(int i=0;i<len;i++)
    {
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
        if(ans[len]) len++;
    }
    return len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>s>>k;
    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        op[a][b]=true;
    }
    ans[0]=1;
    int len=1;
    for(auto &i:s)
    {
        memset(vis,false,sizeof vis);
        int now=dfs(i-'0');
        len=cal(now,len);
    }
    for(int i=len-1;i>=0;i--)
        cout<<ans[i];
    cout<<'\n';
    return 0;
}