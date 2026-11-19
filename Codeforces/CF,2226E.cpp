#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

struct Segment
{
    private:
        struct qwq
        {
            int minn,lazy;
        };
        
        int size;
        vector<qwq>op;

        void add(int id,int k)
        {
            op[id].minn+=k;
            op[id].lazy+=k;
        }

        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;

                add(hl,op[id].lazy),add(hr,op[id].lazy);
                op[id].lazy=0;
            }
        }

        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                add(id,k);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].minn=min(op[hl].minn,op[hr].minn);
        }

        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return inf;
            if(st<=l&&r<=ed) return op[id].minn;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return min(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        Segment(int n) { size=n,op.assign((n+90)<<2,{0,0}); }

        void update(int st,int ed,int k)
        {
            if(st>ed) exit(-182497);

            dfs(0,size,1,st,ed,k);
        }
        int get(int st,int ed)
        {
            if(st>ed) exit(-182497);

            return query(0,size,1,st,ed);
        }
};

int T,n;
int a[MAX];

void solve()
{
    cin>>n;
    int maxn=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }

    Segment fu(n);
    vector<int>cnt(maxn+1,0);

    int ans=1,now=1;
    fu.update(0,0,-1);

    for(int i=1;i<=n;i++)
    {
        if(a[i]<now)
        {
            if(cnt[a[i]]==0) fu.update(0,a[i],1);
            else if(a[i]>0)
            {
                int x=(a[i]-1)>>1;
                fu.update(0,x,1);
            }
        }
        else if(a[i]>0)
        {
            int x=(a[i]-1)>>1;
            fu.update(0,x,1);
        }
        ++cnt[a[i]];

        while(now<=n&&fu.get(0,now-1)>=0)
        {
            if(cnt[now]==0) fu.update(0,now,-1);
            else if(now>0)
            {
                int x=(now-1)>>1;
                fu.update(0,x,-1);
            }

            ans=now;
            ++now;
        }

        cout<<ans<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}