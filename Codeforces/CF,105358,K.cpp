#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=200,G=3,MOD=998244353,INF=2e9;

LL qpow(LL a,LL p)
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

int n;
LL k;
LL fac[MAX],inv[MAX];

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m) { return fac[n]*inv[n-m]%MOD*inv[m]%MOD; }
LL A(int n,int m) { return fac[n]*inv[n-m]%MOD; }

pair<vector<LL>,vector<LL>> split(const vector<LL>& op,int bit)
{
    vector<LL>f0,f1;

    for(auto &cur:op)
    {
        if((cur>>bit)&1) f1.push_back(cur);
        else f0.push_back(cur);
    }

    return {f0,f1};
}

vector<LL> cal(const vector<LL>& a,const vector<LL>& b)
{
    int lim=min(a.size(),b.size()),lena=a.size(),lenb=b.size();
    vector<LL>ans(lim+1,0LL);
    
    for(int i=0;i<=lim;i++)
        ans[i]=C(lena,i)*C(lenb,i)%MOD*fac[i]%MOD;

    return ans;    
}

vector<LL> dfs(vector<LL>A,vector<LL>B,int bit)
{   
    if(A.empty()||B.empty()) return {1};

    int lim=min(A.size(),B.size());
    vector<LL>f(lim+1,0LL);

    if((k>>bit)&1)
    {
        vector<LL>P,Q;
        auto [A0,A1]=split(A,bit);
        auto [B0,B1]=split(B,bit);

        if(bit)
        {
            P=dfs(A0,B1,bit-1);
            Q=dfs(A1,B0,bit-1);
        }
        else P=cal(A0,B1),Q=cal(A1,B0);

        int lenp=P.size(),lenq=Q.size();
        for(int i=0;i<lenp;i++)
            for(int j=0;j<lenq;j++)
                f[i+j]=(f[i+j]+P[i]*Q[j]%MOD)%MOD;
    }
    else
    {
        vector<LL>P,Q;
        auto [A0,A1]=split(A,bit);
        auto [B0,B1]=split(B,bit);
        int a0=A0.size(),a1=A1.size(),b0=B0.size(),b1=B1.size();
        
        if(bit)
        {
            P=dfs(A0,B0,bit-1);
            Q=dfs(A1,B1,bit-1);
        }
        else P=cal(A0,B0),Q=cal(A1,B1);

        int lenp=P.size(),lenq=Q.size();
        for(int x=0;x<lenp;x++)
            for(int y=0;y<lenq;y++)
            {
                LL base=P[x]*Q[y]%MOD;
                int minu=min(a0-x,b1-y),minv=min(a1-y,b0-x);

                for(int u=0;u<=minu;u++)
                    for(int v=0;v<=minv;v++)
                    {
                        if(x+y+u+v>n) break;

                        int nxt=x+y+u+v;
                        LL conu=C(a0-x,u)*C(b1-y,u)%MOD*fac[u]%MOD;
                        LL conv=C(a1-y,v)*C(b0-x,v)%MOD*fac[v]%MOD;
                        f[nxt]=(f[nxt]+base*conu%MOD*conv%MOD)%MOD;
                    }
            }
    }

    return f;
}

void solve()
{
    cin>>n>>k;

    vector<LL>a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    vector<LL>ans=dfs(a,b,59);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}