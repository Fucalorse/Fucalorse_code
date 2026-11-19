#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=120;

int n;
char op[MAX];
LL num[MAX],f[MAX][MAX],g[MAX][MAX];

LL cal(const LL &a,const LL &b,const char &c)
{
    if(c=='t') return a+b;
    else return a*b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i]>>num[i];
        op[i+n]=op[i],num[i+n]=num[i];
    }
    memset(f,-0x3f,sizeof f);
    memset(g,0x3f,sizeof g);
    int m=n<<1;
    for(int i=1;i<=m;i++)
        f[i][i]=g[i][i]=num[i];
    for(int len=2;len<=m;len++)
        for(int i=1;i+len-1<=m;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
            {
                LL a=cal(f[i][k],f[k+1][j],op[k+1]);
                LL b=cal(g[i][k],g[k+1][j],op[k+1]);
                LL c=cal(f[i][k],g[k+1][j],op[k+1]);
                LL d=cal(g[i][k],f[k+1][j],op[k+1]);
                f[i][j]=max(f[i][j],max(max(a,b),max(c,d)));
                g[i][j]=min(g[i][j],min(min(a,b),min(c,d)));
            }
        }
    LL ans=-1e17;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i][i+n-1]);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)
        if(ans==f[i][i+n-1]) cout<<i<<' ';
    cout<<'\n';
    return 0;
}