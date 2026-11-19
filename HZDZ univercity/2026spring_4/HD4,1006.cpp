#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int t,n,m,k;
int l[10],r[10],v[10][155],g[35][10],a[10][35],sum[10],id[10];
int f[155][155][155];

void solve()
{
    memset(v,0,sizeof v),memset(a,0,sizeof a);
    memset(sum,0,sizeof sum),memset(f,0,sizeof f);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        for(int j=0;j<=r[i]-l[i];j++)
            cin>>v[i][j];
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
            sum[j]+=g[i][j];
        }
    int cnt=0;
    for(int j=1;j<=n;j++)
        if(sum[j]>=l[j])
        {
            id[++cnt]=j;
            for(int i=1;i<=m;i++)
                a[cnt][i]=g[i][j];
        }
    l[8]=r[8]=0;
    for(int i=cnt+1;i<=3;i++)
        id[i]=8;
    f[0][0][0]=true;
    for(int i=1;i<=m;i++)
        for(int x=k;x>=a[1][i];x--)
            for(int y=k-x;y>=a[2][i];y--)
                for(int z=k-x-y;z>=a[3][i];z--)
                    f[x][y][z]|=f[x-a[1][i]][y-a[2][i]][z-a[3][i]];
    int ans=0;
    for(int x=0;x<=k;x++)
    {
        int num1=0;
        if(x>=l[id[1]]) num1=v[id[1]][x-l[id[1]]];
        for(int y=0;y<=k;y++)
        {
            int num2=0;
            if(y>=l[id[2]]) num2=v[id[2]][y-l[id[2]]];
            for(int z=0;z<=k;z++)
            {
                int num3=0;
                if(z>=l[id[3]]) num3=v[id[3]][z-l[id[3]]];
                if(f[x][y][z]) ans=max(ans,num1+num2+num3);
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}