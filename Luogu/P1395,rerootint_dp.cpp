#include <bits/stdc++.h>
using namespace std;

const int MAX=5e4+90,inf=2e9;

typedef pair<int,int> qwq;

int read()
{
    int ans = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans * f;
}

qwq cal(const qwq &a,const qwq &b)
{
    if(a.second==b.second) return a.first<b.first?a:b;
    return a.second<b.second?a:b;
}

int n;
int op[MAX], f[MAX];
vector<int> p[MAX];

int dfs(int ch, int fa)
{
    op[ch]=1;
    for(auto to : p[ch])
        if (to != fa)
        {
            op[ch]+=dfs(to,ch);
            f[ch]+=f[to]+op[to];
        }
    return op[ch];
}

qwq find(int ch,int fa)
{
    if(fa) f[ch]=f[fa]+op[1]-2*op[ch];
    qwq ans={ch,f[ch]};
    for(auto to:p[ch])
        if(to!=fa) ans=cal(ans,find(to,ch));
    return ans;
}

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    dfs(1,0);
    qwq now=find(1,0);
    printf("%d %d\n",now.first,now.second);
    return 0;
}