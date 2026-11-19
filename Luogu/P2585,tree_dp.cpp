#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e5+90;

int n,idx,qwq;
int f[MAX][3],g[MAX][3];
char s[MAX];
vector<int>p[MAX];

int find()
{
    if(idx>n) return 0;
    int now=s[idx++]-'0',pos=++qwq;
    // cout<<now<<' '<<qwq<<endl;
    if(!now) return pos;
    if(now>=1) p[pos].push_back(find());
    if(now==2) p[pos].push_back(find());
    return pos;
}

void print(int pos)
{
    if(!pos) return;
    cout<<pos<<' ';
    for(auto &to:p[pos])
        print(to);
}

void dfs(int ch,int fa)
{
    f[ch][0]=g[ch][0]=1;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
        if((int)p[ch].size()==2)
        {
            int l=p[ch].front(),r=p[ch].back();
            f[ch][0]=max(f[l][1]+f[r][2],f[l][2]+f[r][1])+1;
            f[ch][1]=max(f[l][0]+f[r][2],f[l][2]+f[r][0]);
            f[ch][2]=max(f[l][0]+f[r][1],f[l][1]+f[r][0]);

            g[ch][0]=min(g[l][1]+g[r][2],g[l][2]+g[r][1])+1;
            g[ch][1]=min(g[l][0]+g[r][2],g[l][2]+g[r][0]);
            g[ch][2]=min(g[l][0]+g[r][1],g[l][1]+g[r][0]);
        }
        else if((int)p[ch].size()==1)
        {
            int to=p[ch].front();
            f[ch][0]=max(f[to][1],f[to][2])+1;
            f[ch][1]=max(f[to][0],f[to][2]);
            f[ch][2]=max(f[to][0],f[to][1]);

            g[ch][0]=min(g[to][1],g[to][2])+1;
            g[ch][1]=min(g[to][0],g[to][2]);
            g[ch][2]=min(g[to][0],g[to][1]);
        }
    }
}

void solve()
{
    cin>>(s+1);
    n=strlen(s+1);
    idx=1,qwq=0;
    int root=find();
    // print(root);
    dfs(root,0);
    int maxn=max({f[root][0],f[root][1],f[root][2]});
    int minn=min({g[root][0],g[root][1],g[root][2]});
    cout<<maxn<<' '<<minn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}