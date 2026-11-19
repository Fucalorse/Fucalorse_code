#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

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

int n,q;
int fa[MAX];
char kind[MAX];

int find(int x)
{
    if(x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}

void combine(int x,int y) { fa[find(x)]=find(y); }

int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)
    {
        scanf(" %c",kind+i);
        fa[i]=i;
    }
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        if(kind[u]==kind[v]) combine(u,v);
    }
    string ans="";
    while(q--)
    {
        int u=read(),v=read();
        char c;
        scanf(" %c",&c);
        if(find(u)==find(v)&&c!=kind[u]) ans+='0';
        else ans+='1';
    }
    cout<<ans<<'\n';
    return 0;
}