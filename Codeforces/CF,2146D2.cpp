#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=30;

int t;
LL l,r,ans;
map<LL,LL>op;

LL get(LL l,LL r)
{
    LL ans=0;
    for(int k=LEN;k>=0;k--)
    {
        LL pl=(l>>k)&1,pr=(r>>k)&1;
        ans|=pr<<k;
        if(pl!=pr) return ans;
    }
    return ans;
}

LL cal(LL a,LL b) { return a|b; }

void dfs(LL l,LL r)
{
    if(l>r) return;
    if(l==r)
    {
        op[l]=l;
        ans+=l;
        return;
    }
    LL t=get(l,r);
    if(t-l<=r-t+1)
    {
        for(LL i=l;i<t;i++)
        {
            op[i]=2*t-1-i;
            op[2*t-1-i]=i;
            ans+=cal(i,2*t-1-i)*2;
        }
        dfs(2*t-l,r);
    }
    else
    {
        for(LL i=t;i<=r;i++)
        {
            op[i]=2*t-1-i;
            op[2*t-1-i]=i;
            ans+=cal(i,2*t-1-i)*2;
        }
        dfs(l,2*t-r-2);
    }
}

void solve()
{
    cin>>l>>r;

    op.clear();
    ans=0;
    dfs(l,r);

    cout<<ans<<endl;
    for(auto it=op.begin();it!=op.end();++it)
        cout<<it->second<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}