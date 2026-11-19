#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9,LEN=30;

struct qwq
{
    int pos;
    LL val;
    bool operator<(const qwq &a)const
    {
        if(val!=a.val) return val<a.val;
        else return pos<a.pos;
    }
}op[MAX];

int n,q;
int to[MAX];
LL a[MAX];

bool check(const LL &mid)
{
    LL len=1;
    while(len<=mid) len<<=1;

    for(int i=1;i<=n;i++)
    {
        int now=(i-1)^(to[i]-1);
        if(now>=len) return false;
    }
    return true;
}

void solve()
{
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op[i]={i,a[i]};
    }

    sort(op+1,op+n+1);
    for(int i=1;i<=n;i++)   
        to[op[i].pos]=i;

    LL l=0,r=INF;
    while(l<=r)
    {
        int mid=(l+r)>>1;

        if(check(mid)) r=mid-1;
        else l=mid+1;
    }

    cout<<l<<endl;
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