#include <bits/stdc++.h>
using namespace std;

const int MAX=5005,inf=0x3f3f3f3f,LEN=3e7;

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

int t,n,q;
char s[MAX];
vector<vector<int>>f,p;

int main()
{
    n=read(),q=read();
    f.assign(n+5,vector<int>(n+5,inf));
    p.assign(n+5,vector<int>{});
    for(int i=1;i<n;i++)
    {
        scanf(" %s",s+1);
        int len=strlen(s+1);
        for(int j=1;j<=len;j++)
        {
            if(s[j]=='1')
            {
                f[i][i+j]=1;
                p[i].push_back(i+j);
            }
            else
            {
                f[i+j][i]=1;
                p[i+j].push_back(i);
            }
        }
    }
    if(n<=100)
    {
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        while(q--)
        {
            int u=read(),v=read();
            printf("%d\n",f[u][v]==inf?-1:f[u][v]-1);
        }
    }
    else
    {
        while(q--)
        {
            int u=read(),v=read();
            if(f[u][v]!=inf)
            {
                printf("0\n");
                continue;
            }
            for(auto &to:p[u])
                if(f[u][to]!=inf)
                {
                    printf("1\n");
                    break;
                }
        }
    }
    return 0;
}