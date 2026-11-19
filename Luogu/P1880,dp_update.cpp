#include <bits/stdc++.h>
using namespace std;

const int MAX=220,inf=2e9;

int n;
int num[MAX],op[MAX],f[MAX][MAX],g[MAX][MAX],s[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        op[i]=num[i]+op[i-1];
        s[i][i]=i,s[i+n][i+n]=i+n;
    }
    for(int i=1;i<=n;i++)
        op[i+n]=op[i+n-1]+num[i];
    int len=n<<1;
    for(int i=len;i>=1;i--)
        for(int j=i+1;j<=len;j++)
        {
            int ans=inf,p;
            f[i][j]=max(f[i][j-1],f[i+1][j])+op[j]-op[i-1];
            for(int k=s[i][j-1];k<=s[i+1][j];k++)
            {
                int now=g[i][k]+g[k+1][j]+op[j]-op[i-1];
                if(now<ans)
                {
                    ans=now;
                    p=k;
                }
            }
            g[i][j]=ans;
            s[i][j]=p;
        }
    int minn=inf,maxn=-inf;
    for(int i=1;i<=n;i++)
    {
        minn=min(minn,g[i][i+n-1]);
        maxn=max(maxn,f[i][i+n-1]);
    }
    cout<<minn<<'\n'<<maxn<<'\n';
    return 0;
}