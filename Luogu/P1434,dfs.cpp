#include <bits/stdc++.h>
using namespace std;

const int MAX=150;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

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

int n,m;
int op[MAX][MAX],f[MAX][MAX];

bool dis(const int &i,const int &j)
{
    return i>=1&&i<=n&&j>=1&&j<=m;
}

int dfs(int i,int j)
{
    if(f[i][j]) return f[i][j];
    int cnt=0;
    for(int s=0;s<4;s++)
    {
        int ni=i+dx[s],nj=j+dy[s];
        if(dis(ni,nj)&&op[i][j]<op[ni][nj]) cnt=max(cnt,dfs(ni,nj));
    }
    return f[i][j]=cnt+1;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            op[i][j]=read();
    int ans=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=max(ans,dfs(i,j));
    printf("%d\n",ans);
    return 0;
}