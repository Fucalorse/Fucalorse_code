#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e7+90,LEN=1e7,MOD=998244353;
const LL INF=1e18;

int l,r,n;
int minp[MAX],mu[MAX],pre[MAX],id[MAX];
vector<int>op;

void oula(int n)
{
    minp[1]=1,mu[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            mu[i]=-1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
            mu[i*j]=-mu[i];
        }
    }

    int len=op.size();
    pre[1]=1;
    for(int i=2,pos=0;i<=n;i++)
    {
        while(pos<len&&op[pos]<=i) ++pos;
        pre[i]=op[pos-1];
    }

    // for(int i=1;i<=6;i++)
    //     printf("%d ",mu[i]);
    // printf("\n");
}

LL cal_first(int l,int r)
{
    if(l>r) return 0LL;

    vector<int>rest;

    auto add=[&](int x)
    {
        if(x>r) return;
        rest.push_back(x);
    };

    for(int i=1;i*i<=n;i++)
    {
        if(n%i!=0) continue;

        add(i);
        if(i*i!=n) add(n/i);
    }

    LL con1=0,con2=0;
    for(auto &d:rest)
    {
        int vl=0,vr=r/d*mu[d];
        if(d<l) vl=(l-1)/d*mu[d];
        con1+=vr-vl;
    }

    con2=(r-l+1-con1)*2;

    // for(int i=l;i<=r;i++)
    //     cout<<i<<' ';
    // cout<<endl;
    // cout<<con1<<' '<<con2<<endl;

    return con1+con2;
}

LL cal_second(int l,int r)
{
    if(l>r) return 0LL;

    vector<LL>dp(n-l+5,INF);

    for(int i=l,tot=0;i<=n-1;i++)
    {
        id[i]=++tot;
        dp[id[i]]=__gcd(i,n);
    }

    for(int i=n-1;i>=l;i--)
        for(int j=i+1;j<=n-1;j++)
        {
            int u=id[i],v=id[j];
            dp[u]=min(dp[u],__gcd(i,j)+dp[v]);
        }

    LL ans=0;
    for(int i=l;i<=r;i++)
        ans+=dp[id[i]];

    return ans;
}

void solve()
{
    cin>>l>>r>>n;

    LL ans=0;
    int mid=pre[n];
    if(r<=mid) ans=cal_first(l,r);
    else if(l>mid) ans=cal_second(l,r);
    else ans=cal_first(l,mid)+cal_second(mid+1,r);

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}