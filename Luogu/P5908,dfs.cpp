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
vector<int>p[MAX];

int dfs(int depth,int ch,int fa)
{
    if(depth==d) return 1;
    if(depth>d) return 0;
    int cnt=0;
    for(auto i:p[ch])
        if(i!=fa) cnt+=dfs(depth+1,i,ch);
    return cnt+1;
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
    printf("%d\n",dfs(0,1,-1)-1);
    return 0;
}