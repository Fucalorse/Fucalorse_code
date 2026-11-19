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

struct qwq
{
    int x,y,val;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int n,m;
int op[MAX][MAX],f[MAX][MAX];
priority_queue<qwq>q;

bool dis(const int &i,const int &j)
{
    return i>=1&&i<=n&&j>=1&&j<=m;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            op[i][j]=read();
            f[i][j]=1;
            q.push({i,j,op[i][j]});
        }
    int ans=1;
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        int i=cur.x,j=cur.y;
        for(int s=0;s<4;s++)
        {
            int ni=i+dx[s],nj=j+dy[s];
            if(dis(ni,nj)&&op[i][j]>op[ni][nj]) 
                f[ni][nj]=max(f[ni][nj],f[i][j]+1);
            ans=max(ans,f[ni][nj]);
        }
    }
    printf("%d\n",ans);
    return 0;
}