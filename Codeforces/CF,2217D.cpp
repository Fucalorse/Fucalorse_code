#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=26,MOD=998244353,INF=2e9;

int n,k;
int a[MAX],p[MAX];

void solve()
{
    cin>>n>>k;

    vector<int>f(n+2,0);
    vector<pair<int,int>>op;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=k;i++)
    {
        cin>>p[i];
        op.push_back({p[i-1]+1,p[i]});
    }
    op.push_back({p[k]+1,n+1});

    // for(auto &[l,r]:op)
    //     cout<<l<<' '<<r<<endl;

    for(int i=1,x=a[p[1]];i<=n;i++)
    {
        a[i]^=x;
        f[i]=a[i]^a[i-1];
    }

    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<' ';
    // cout<<endl;

    int sum=0,maxn=0;
    vector<int>rest;
    for(auto &[l,r]:op)
    {
        int cnt=0;

        for(int i=l;i<=r;i++)
            cnt+=f[i]==1;

        sum+=cnt;
        maxn=max(maxn,cnt);
        rest.push_back(cnt);
    }

    // for(auto &cur:rest)
    //     cout<<cur<<' ';
    // cout<<endl;

    if(!sum)
    {
        cout<<0<<endl;
        return;
    }

    if(maxn==sum)
    {
        int ans=0;

        if(maxn==rest.back()) ans=(maxn&1)+maxn;
        else ans=maxn;

        cout<<ans<<endl;
        return;
    }

    if(sum-maxn>=maxn) cout<<(sum+1)/2<<endl;
    else
    {
        int con1=sum-maxn,r=maxn-(sum-maxn),con2;

        if(maxn==rest.back()) con2=(r&1)+r;
        else con2=r;

        cout<<con1+con2<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}