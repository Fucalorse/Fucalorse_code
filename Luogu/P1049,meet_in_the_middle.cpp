#include <bits/stdc++.h>
using namespace std;

const int MAX=50;

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

int w,n,st,ed;
int num[MAX];
vector<int>f,g;

void dfs(int pos,int sum,vector<int>&op)
{
    if(sum>w) return;
    op.push_back(sum);
    for(int i=pos;i<=ed;i++)
        dfs(i+1,sum+num[i],op);
}

int main()
{
    w=read(),n=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    st=1,ed=n/2;
    dfs(st,0,f);
    st=n/2+1,ed=n;
    dfs(st,0,g);
    sort(f.begin(),f.end(),greater<int>());
    sort(g.begin(),g.end());
    int ans=0;
    for(size_t l=0,r=0;l<f.size();l++)
    {
        while(r<g.size()&&f[l]+g[r]<=w) r++;
        ans=max(ans,f[l]+g[r-1]);
    }
    printf("%d\n",w-ans);
    return 0;
}