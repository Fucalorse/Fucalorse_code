#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct interval
{
    LL l,r;
    int id;
    bool operator<(const interval& a)const { return l<a.l; }
}op[MAX];

int n;
LL m,k;
LL f[MAX];

void solve()
{
    cin>>n>>m>>k;

    op[0]={1,0,0};
    vector<interval>wait;
    for(int i=1;i<=n;i++)
    {
        op[i].id=i;
        cin>>op[i].l>>op[i].r;
        f[i]=f[i-1]+op[i].r-op[i].l+1;
        wait.push_back({op[i-1].r+1,op[i].l-1,0});
        wait.push_back(op[i]);
    }
    wait.push_back({op[n].r+1,op[n].r+1,0});
    
    // for(auto &[l,r,id]:wait)
    //     cout<<l<<' '<<r<<' '<<id<<endl;

    auto find=[&](LL target)->int
    {
        int l=1,r=n;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(target>=op[mid].l) l=mid+1;
            else r=mid-1;
        }
        return r;
    };

    auto cal=[&](LL st,LL ed)->LL
    {
        int L=find(st),R=find(ed);
        LL ans=f[R]-f[max(0,L-1)]-max(0LL,op[R].r-ed)-min(op[L].r-op[L].l+1,st-op[L].l);
        return ans;
    };

    for(auto [l,r,col]:wait)
    {
        if(col==0)
        {
            while(l<=r)
            {
                LL mid=(l+r)>>1;
                LL now=cal(mid,mid+m-1);
                // cout<<mid<<' '<<now<<endl;
                if(now==k)
                {
                    cout<<mid<<endl;
                    return;
                }
                if(now>k) r=mid-1;
                else l=mid+1;
            }
        }
        else
        {
            while(l<=r)
            {
                LL mid=(l+r)>>1;
                LL now=cal(mid,mid+m-1);
                // cout<<mid<<" "<<now<<endl;
                if(now==k)
                {
                    cout<<mid<<endl;
                    return;
                }
                if(now>k) l=mid+1;
                else r=mid-1;
            }
        }
    }

    cout<<-1<<endl;
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