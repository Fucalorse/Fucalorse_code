#include <bits/stdc++.h>
using namespace std;

const int MAX=1090,inf=1e9;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

int n,m,s;
int num[MAX][MAX];

int cal(const int &x)
{
    vector<int>f,g;
    f.resize(m+5,0),g.resize(m+5,inf);
    for(int i=x-s+1;i<=x;i++)
        for(int j=1;j<=m;j++)
        {
            f[j]=max(f[j],num[i][j]);
            g[j]=min(g[j],num[i][j]);
        }
    int ans=inf;
    deque<int>maxn,minn;
    for(int i=1;i<=m;i++)
    {
        while(maxn.size()&&f[i]>f[maxn.back()]) maxn.pop_back();
        while(maxn.size()&&maxn.front()<=i-s) maxn.pop_front();
        maxn.push_back(i);
        while(minn.size()&&g[i]<g[minn.back()]) minn.pop_back();
        while(minn.size()&&minn.front()<=i-s) minn.pop_front();
        minn.push_back(i);
        if(i>=s) ans=min(ans,f[maxn.front()]-g[minn.front()]);
    }
    return ans;
}

int main()
{
    n=read(),m=read(),s=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            num[i][j]=read();
    int ans=inf;
    for(int i=s;i<=n;i++)
        ans=min(ans,cal(i));
    printf("%d\n",ans);
    return 0;
}