#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=2e5,MOD=998244353,INF=2e9;

LL cal(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }

    return ans;
}

struct qwq
{
    int x,y;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        return y<a.y;
    }
};

int n,m;
LL f[MAX],inv[MAX];

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=cal(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m) { return f[n]*inv[m]%MOD*inv[n-m]%MOD; }

LL cal_greater(vector<qwq>& op)
{
    vector<vector<bool>>ob(n+1,vector<bool>(m+1,0));
    vector<LL>dp(m+1);

    for(auto &[x,y]:op)
        ob[x][y]=true;

    if(ob[1][1]||ob[n][m]) return 0;

    dp[1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(ob[i-1][j]) dp[j]=0;
            if(!ob[i][j-1]) dp[j]=(dp[j]+dp[j-1])%MOD;
        }

    return dp[m];
}

LL cal_lower(vector<qwq>& op)
{
    sort(op.begin(),op.end());
    
    LL ans=0;
    int len=(int)op.size();
    vector<LL>f(len,0);

    for(int i=0;i<len;i++)
    {
        auto &[nx,ny]=op[i];
        f[i]=C(nx+ny-2,nx-1);

        for(int j=0;j<i;j++)
        {
            auto &[px,py]=op[j];
            if(px>nx||py>ny) continue;

            f[i]=(f[i]-f[j]*C(nx-px+ny-py,nx-px)%MOD+MOD)%MOD;
        }

        ans=(ans+f[i]*C(n-nx+m-ny,n-nx)%MOD)%MOD;
    }

    return ans;
}

void solve()
{
    cin>>n>>m;

    int len=n*m;
    vector<int>cnt(len+1,0);
    vector<vector<int>>a(n+1,vector<int>(m+1));
    vector<vector<qwq>>pos(len+1);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            ++cnt[a[i][j]];
            pos[a[i][j]].push_back({i,j});
        }

    int B=sqrt(len);
    LL total=C(n+m-2,n-1),ans=0;
    for(int i=1;i<=len;i++)
    {
        auto &op=pos[i];
        if(op.empty()) continue;

        if((int)op.size()>=B)
        {
            LL now=cal_greater(op);
            ans=(ans+total-now+MOD)%MOD;
        }
        else
        {
            LL now=cal_lower(op);
            ans=(ans+now)%MOD;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}