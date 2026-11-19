#include <bits/stdc++.h>
using namespace std;

const int MAX=25;

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

int n,st,maxn=0;
int num[MAX],op[MAX],outdeg[MAX],f[MAX];
vector<int>p[MAX];

int dfs(int pos)
{
    if(!outdeg[pos])
    {
        if(num[pos]>maxn) maxn=num[pos],st=pos;
        return f[pos]=num[pos];
    }
    if(f[pos]) return f[pos];
    for(auto i:p[pos])
    {
        int ans=dfs(i);
        if(ans+num[pos]>f[pos])
        {
            f[pos]=ans+num[pos];
            op[pos]=i;
        }
        if(f[pos]>maxn) maxn=f[pos],st=pos;
    }
    return f[pos];
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int a=read();
            if(a)
            {
                p[i].push_back(j);
                outdeg[i]++;
            }
        }
    for(int i=1;i<=n;i++)
        if(!f[i]) dfs(i);
    for(int i=st;i;i=op[i])
        printf("%d ",i);
    printf("\n%d\n",maxn);
    return 0;
}