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
int num[MAX],op[MAX],indeg[MAX],f[MAX];
vector<int>p[MAX];

void bfs()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(indeg[i]==0)
        {
            q.push(i);
            f[i]=num[i];
            if(f[i]>maxn) maxn=f[i],st=i;
        }
    while(q.size())
    {
        int cur=q.front();q.pop();
        for(auto i:p[cur])
        {
            if(f[cur]+num[i]>f[i])
            {
                f[i]=f[cur]+num[i];
                op[i]=cur;
            }
            if(f[i]>maxn) maxn=f[i],st=i;
            indeg[i]--;
            if(indeg[i]==0) q.push(i);
        }
    }
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
                p[j].push_back(i);
                indeg[i]++;
            }
        }
    bfs();
    for(int i=st;i;i=op[i])
        printf("%d ",i);
    printf("\n%d\n",maxn);
    return 0;
}