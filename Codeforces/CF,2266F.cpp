#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=1e9;

struct qwq
{
    LL val,cnt;
    bool operator<(const qwq &a)const { return val<a.val; }
}op[MAX];

int n;

void solve()
{
    cin>>n;

    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].val>>op[i].cnt;
        sum+=op[i].cnt;
    }

    sort(op+1,op+n+1);

    auto check=[&](const LL &mid)
    {
        int pos=op[1].val==0?2:1;
        LL c0=op[1].val==0?op[1].cnt:0;
        LL need=1,extra=0,now=mid-1;

        for(int i=n;i>=pos;i--)
        {
            if(now>op[i].val)
            {
                LL len=now-op[i].val;
                if(len>=60) return false;
                i128 nxt=(i128)need<<len;
                if(nxt>sum) return false;

                need=(LL)nxt;
                now=op[i].val;
            }
            
            if(now==op[i].val)
            {
                if(op[i].cnt>=need) extra+=op[i].cnt-need;
                else need+=need-op[i].cnt;
            }
            else extra+=op[i].cnt-need;

            if(need>sum) return false;

            now=op[i].val-1;
        }

        if(now>=60) return false;
        i128 nxt=(i128)need<<now;
        if(nxt>sum) return false;
        need=nxt;

        return extra+c0>=need;
    };

    LL l=op[n].val+1,r=sum,ans=op[n].val;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    cout<<ans<<endl;
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