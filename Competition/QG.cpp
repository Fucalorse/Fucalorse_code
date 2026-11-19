#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=150;
const double eps=1e-7;

struct qwq
{
    int pos;
    double val;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int t,n,k;
LL cnt[MAX];
double op[MAX];

LL cal(const double &mid)
{
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        cnt[i]=mid-1/op[i];
        cnt[i]=max(0LL,cnt[i]);
        total+=cnt[i];
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>op[i];
            cnt[i]=0;
            op[i]/=100;
        }
        double l=0,r=1e6;
        while(r-l>eps)
        {
            double mid=(l+r)/2;
            if(cal(mid)<=k) l=mid;
            else r=mid;
        }
        LL now=cal(l);
        priority_queue<qwq>q;
        for(int i=1;i<=n;i++)
        {
            double aft=(1+(cnt[i]+1)*op[i])/(1+cnt[i]*op[i]);
            q.push({i,aft});
        }
        while(now<k)
        {
            auto [pos,val]=q.top();q.pop();
            cnt[pos]++;
            now++;
            double aft=(1+(cnt[pos]+1)*op[pos])/(1+cnt[pos]*op[pos]);
            q.push({pos,aft});
        }
        double ans=1.00;
        for(int i=1;i<=n;i++)
            ans*=(1+cnt[i]*op[i]);
        cout<<ans<<'\n';
    }
    return 0;
}