#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=3e5+90;
const LL inf=1e17;

LL read()
{
    LL ans=0,f=1;
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

int n,k;
int ans[MAX];
LL num[MAX],st[MAX],ed[MAX];
priority_queue<LL,vector<LL>,greater<LL>>q;
unordered_set<LL>f;

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;++i)
    {
        num[i]=read();
        if(i<=k)
        {
            q.push(num[i]);
            st[i]=0,ed[i]=num[i];
        }
    }
    for(int i=k+1;i<=n;++i)
    {
        LL cur=q.top();q.pop();
        st[i]=cur,ed[i]=cur+num[i];
        q.push(ed[i]);
    }
    printf("%lld\n",q.top());
    f.insert(q.top());
    for(int i=n;i>=1;--i)
        if(f.find(ed[i])!=f.end())
        {
            f.insert(st[i]);
            if(i<=k) ans[i]=1;
        }
    for(int i=1;i<=k;i++)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}