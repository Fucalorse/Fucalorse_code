#include <bits/stdc++.h>
using namespace std;

const int MAX=150;

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

int n,k,st,ed;
int num[MAX];
vector<int>f,g;
void dfs(int pos,int sum,vector<int>&op)
{
    if(sum>k) return;
    op.push_back(sum);
    for(int i=pos;i<=ed;i++)
        dfs(i+1,sum+num[i],op);
}

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    st=1,ed=n/2;
    dfs(st,0,f);
    st=n/2+1,ed=n;
    dfs(st,0,g);
    sort(f.begin(),f.end(),greater<int>());
    sort(g.begin(),g.end());
    int total=0;
    for(size_t i=0,l=0,r=0;i<f.size();i++)
    {
        while(l<g.size()&&f[i]+g[l]<k) l++;
        r=l;
        while(r<g.size()&&f[i]+g[r]<=k) r++;
        total+=r-l;
    }
    printf("%d\n",total);
    return 0;
}