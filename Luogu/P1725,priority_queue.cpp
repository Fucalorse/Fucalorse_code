#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90;

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

int n,l,r;
int f[MAX],op[MAX];
priority_queue<int>q;
unordered_map<int,int>vis;

int main()
{
    n=read(),l=read(),r=read();
    for(int i=0;i<=n;i++)
        op[i]=read();
    memset(f,0xf0,sizeof f);
    f[0]=0;
    int ans=-1e9;
    for(int i=l;i<=n;i++)
    {
        int p=i-l;
        if(i-r-1>=0) vis[f[i-r-1]]++;
        while(q.size()&&vis[q.top()]>0)
        {
            vis[q.top()]--;
            q.pop();
        }
        q.push(f[p]);
        f[i]=max(f[i],q.top()+op[i]);
        if(i+r>n) ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}