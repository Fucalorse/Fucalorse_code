#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,inf=1e9;

struct interval
{
    int l,r;
}op[MAX];

int T,n,L,k,len;
int f[MAX];
int x[MAX],y[MAX],sx[MAX],sy[MAX],max_pre[MAX],max_suf[MAX];
int sum_l[MAX],sum_r[MAX],max_l[MAX],max_r[MAX];

void clear()
{
    for(int i=0;i<=len+2*n+1;i++)
    {
        x[i]=y[i]=sx[i]=sy[i]=0;
        max_pre[i]=max_suf[i]=-inf;
        max_l[i]=max_r[i]=-inf;
        sum_l[i]=sum_r[i]=0;
        f[i]=0;
    }
}

void solve()
{
    cin>>n>>L>>k;
    len=4*n+1;
    clear();
    int ans=0,cnt=0,ed=len-L;

    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l;++l;
        r=l+L-1;
        op[i]={l,r};
        f[l]++,f[r+1]--;
    }

    //disjoint
    for(int i=1;i<=len;i++)
    {
        f[i]+=f[i-1];
        x[i]=(f[i]==k+1)-(f[i]==k);
        y[i]=(f[i]==k-1)-(f[i]==k);
        sx[i]=sx[i-1]+x[i];
        sy[i]=sy[i-1]+y[i];
        if(f[i]==k)
        {
            ++cnt;
            ++ans;
        }
    }
    for(int i=L;i<=ed;i++)
        max_pre[i]=max(max_pre[i-1],sy[i]-sy[i-L]);
    for(int i=ed+1;i>=1;i--)
        max_suf[i]=max(max_suf[i+1],sy[i+L-1]-sy[i-1]);

    for(int i=1;i<=n;i++)
    {
        const auto &[l,r]=op[i];
        ans=max(ans,sx[r]-sx[l-1]+cnt+max(max_pre[l-1],max_suf[r+1]));
    }

    //intersect
    for(int i=1;i<=len;i++)
    {
        sum_r[i]=sum_r[i-1]+x[i]+y[i+L];
        sum_l[i]=sum_l[i-1]+x[i]+y[max(0,i-L)];
    }

    auto cal_r=[&]()
    {
        deque<int>q;
        for(int i=ed;i>=1;i--)
        {
            while(q.size()&&sum_r[i]>=sum_r[q.back()]) q.pop_back();
            q.push_back(i);
            while(q.size()&&q.front()>=i+L-1) q.pop_front();
            if(q.size()) max_r[i]=sum_r[q.front()]-sum_r[i-1];
        }
    };
    auto cal_l=[&]()
    {
        deque<int>q;
        for(int i=1;i<=ed;i++)
        {
            while(q.size()&&sum_l[i]<=sum_l[q.back()]) q.pop_back();
            q.push_back(i);
            while(q.size()&&q.front()<max(i-L+1,L)) q.pop_front();
            if(q.size()) max_l[i]=sum_l[i]-sum_l[q.front()];
        }
    };

    cal_l(),cal_r();
    for(int i=1;i<=n;i++)
    {
        const auto &[l,r]=op[i];
        ans=max(ans,cnt+max(max_l[r],max_r[l]));
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}