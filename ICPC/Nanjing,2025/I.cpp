#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const double EPS=1e-7;

int n,m;
int a[MAX],b[MAX],c[MAX],d[MAX],e[MAX],p[MAX];

int sgn(double x)
{
    if(fabs(x)<=EPS) return 0;
    if(x<-EPS) return -1;
    else return 1;
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i]>>p[i];

    vector<vector<double>>dp(m+1,vector<double>(4,0));

    for(int i=n;i>=1;i--)
    {
        vector<vector<double>>ndp(m+1,vector<double>(4,-INF));
        double pa=1.00*p[i]/100,pb=1-pa;
        
        //in dining room
        for(int j=0;j<=m-b[i];j++)
            for(int mask=0;mask<4;mask++)
            {
                int maskA=mask|1,maskB=mask|2;
                double now=0;
                bool ok=true;

                if(p[i]>0)
                {
                    if(sgn(dp[j][maskA])<0) ok=false;
                    else now+=dp[j][maskA]*pa;
                }

                if(p[i]<100)
                {
                    if(sgn(dp[j][maskB])<0) ok=false;
                    else now+=dp[j][maskB]*pb;
                }

                if(ok) ndp[j+b[i]][mask]=max(ndp[j+b[i]][mask],now+a[i]);
            }

        //hang out
        for(int j=0;j<=m-d[i];j++)
            for(int mask=0;mask<3;mask++)
            {
                int maskA=mask|1,maskB=mask|2;
                double now=0;
                bool ok=true;

                if(p[i]>0)
                {
                    if(sgn(dp[j][maskA])<0) ok=false;
                    else now+=dp[j][maskA]*pa;
                }

                if(p[i]<100)
                {
                    if(sgn(dp[j][maskB])<0) ok=false;
                    else now+=dp[j][maskB]*pb;
                }

                if(ok) ndp[j+d[i]][mask]=max(ndp[j+d[i]][mask],now+c[i]);
            }

        for(int j=0;j<=m-d[i]-e[i];j++)
            if(sgn(dp[j][0])>=0) ndp[j+d[i]+e[i]][3]=max(ndp[j+d[i]+e[i]][3],dp[j][0]+c[i]);

        dp=ndp;
    }

    if(sgn(dp[m][0])<0) cout<<-1<<endl;
    else
    {
        cout<<fixed<<setprecision(20);
        cout<<dp[m][0]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}