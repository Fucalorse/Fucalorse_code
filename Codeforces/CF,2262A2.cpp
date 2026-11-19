#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=1e9+7,INF=2e9;

struct fucalorse
{
    private:
        struct qwq
        {
            LL sum;
            bool clear;
            qwq(LL _sum=0,bool _clear=false):sum(_sum),clear(_clear){}
        };

        int n;
        vector<qwq>op;

        void down(int id)
        {
            if(op[id].clear)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl].sum=op[hr].sum=0;
                op[hl].clear=op[hr].clear=true;
                op[id].clear=false;
            }
        }

        void dfs_sum(int l,int r,int id,const int &x,const LL &k)
        {
            if(l==r)
            {
                op[id].sum=(op[id].sum+k)%MOD;
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs_sum(l,mid,hl,x,k);
            else dfs_sum(mid+1,r,hr,x,k);

            op[id].sum=(op[hl].sum+op[hr].sum)%MOD;
        }

        void dfs_clear(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                op[id].sum=0;
                op[id].clear=true;
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs_clear(l,mid,hl,st,ed);
            if(mid<ed) dfs_clear(mid+1,r,hr,st,ed);

            op[id].sum=(op[hl].sum+op[hr].sum)%MOD;
        }

        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].sum;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return (query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed))%MOD;
        }
    public:
        fucalorse(int _n):n(_n),op((_n+90)<<2,qwq{}){}

        void update_sum(int x,LL k) { dfs_sum(0,n,1,x,k); }
        void update_clear(int st,int ed) { dfs_clear(0,n,1,st,ed); }

        LL get(int st,int ed) { return query(0,n,1,st,ed); }
};

int n;
int a[MAX];

void solve()
{
    cin>>n;

    vector<int>f(n+3,0),pre(n+3);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        LL l=1LL*i*a[i]+1,r=1LL*(a[i]+1)*i;
        if(l<=n)
        {
            ++f[l];
            --f[min(r+1,1LL*n+1)];
        }
        for(int num=0;num<a[i];num++)
        {
            LL l=1LL*i*num+1,r=1LL*(num+1)*i;
            if(l<=n)
            {
                r=min(1LL*n,r);
                pre[r]=max(pre[r],(int)l);
            }
        }
    }

    fucalorse fu(n);
    fu.update_sum(0,1);
    bool updated=false;

    for(int i=1;i<=n;i++)
    {
        f[i]+=f[i-1];

        if(f[i]==0)
        {
            LL con=fu.get(0,i-1);
            fu.update_sum(i,con);
            updated=true;
        }

        if(updated) fu.update_clear(0,pre[i]-1);
    }

    cout<<fu.get(0,n)<<endl;
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