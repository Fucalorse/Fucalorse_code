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

int n,d;
int f[MAX];
bool vis[MAX];
vector<int>p[MAX];

void bfs()
{
    queue<int>q;
    q.push(1);
    vis[1]=true;
    int total=0;
    while(q.size())
    {
        int cur=q.front();q.pop();
        if(f[cur]>=d) continue;
        for(auto i:p[cur])
            if(!vis[i])
            {
                vis[i]=true;
                f[i]=f[cur]+1;
                q.push(i);
                if(f[i]<=d) total++;
            }
    }
    printf("%d\n",total);
}

int main()
{
    n=read(),d=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    bfs();
    return 0;
}