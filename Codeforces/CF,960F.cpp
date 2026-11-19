#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=1e5,MOD=1e9+7,INF=2e9;

struct peach
{
    private:
        struct qwq
        {
            int l,r;
            int maxn;
            qwq():l(0),r(0),maxn(0){}
        };
        
        int tot,size;
        vector<qwq>op;
        vector<int>root;

        void dfs(int &pos,int l,int r,const int &x,const int &val)
        {
            if(!pos) pos=++tot;
            op[pos].maxn=max(op[pos].maxn,val);
            if(l==r) return;

            int mid=(l+r)>>1;
            if(x<=mid) dfs(op[pos].l,l,mid,x,val);
            else dfs(op[pos].r,mid+1,r,x,val);
        }

        int query(int pos,int l,int r,const int &st,const int &ed)
        {
            if(!pos||r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[pos].maxn;

            int mid=(l+r)>>1;
            return max(query(op[pos].l,l,mid,st,ed),query(op[pos].r,mid+1,r,st,ed));
        }
    public:
        peach(int _n,int _len)
        {
            size=_len,tot=0;
            op.assign(_len*25,qwq{});
            root.assign(_n+3,0);
        }

        void update(int pos,int x,int val) { dfs(root[pos],1,size,x,val); }

        int get(int pos,int st,int ed)
        {
            if(st>ed) return 0;
            return query(root[pos],1,size,st,ed);
        }
};

int n,m;

void solve()
{
    cin>>n>>m;

    int ans=0;
    peach fu(n,LEN+1);
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;++val;

        int dp=fu.get(u,1,val-1)+1;
        fu.update(v,val,dp);

        ans=max(ans,dp);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}