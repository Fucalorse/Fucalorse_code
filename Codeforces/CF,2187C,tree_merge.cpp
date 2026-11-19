#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct Segment
{
    private:
        struct qwq
        {
            int l,r;
            LL cnt,sum;
        };

        int size,tot;
        vector<qwq>op;
        vector<int>root;

        void dfs(int &pos,int l,int r,const int &x)
        {
            if(!pos) pos=++tot;
            op[pos].cnt++,op[pos].sum+=x;
            if(l==r) return;

            int mid=(l+r)>>1;
            if(x<=mid) dfs(op[pos].l,l,mid,x);
            else dfs(op[pos].r,mid+1,r,x);
        }

        int merge_tree(int x,int y,int l,int r,LL &ans,const int &dep_lca)
        {
            if(!x||!y) return x|y;

            if(l==r)
            {
                ans+=2*op[x].cnt*op[y].cnt*(l-dep_lca);
                // cout<<l<<" "<<dep_lca<<endl;

                op[x].cnt+=op[y].cnt;
                op[x].sum+=op[y].sum;

                return x;
            }

            int xl=op[x].l,xr=op[x].r;
            int yl=op[y].l,yr=op[y].r;
            ans+=(op[xl].sum-op[xl].cnt*dep_lca)*op[yr].cnt;
            ans+=(op[yl].sum-op[yl].cnt*dep_lca)*op[xr].cnt;

            int mid=(l+r)>>1;
            op[x].l=merge_tree(op[x].l,op[y].l,l,mid,ans,dep_lca);
            op[x].r=merge_tree(op[x].r,op[y].r,mid+1,r,ans,dep_lca);

            op[x].cnt+=op[y].cnt;
            op[x].sum+=op[y].sum;

            return x;
        }
    public:
        Segment(int n)
        {
            tot=0;
            size=n;
            op.assign(n*20,{0,0,0,0});
            root.assign(n+3,0);
        }

        void update(int pos,int x) { dfs(root[pos],1,size,x); }
        LL merge(int x,int y,int dep_lca)
        {
            LL ans=0;
            root[x]=merge_tree(root[x],root[y],1,size,ans,dep_lca);

            return ans;
        }
};

int T,n,m;
LL ans;
int fa[MAX],depth[MAX];
vector<int>p[MAX];

void dfs(int ch,int fa,Segment& fu)
{
    depth[ch]=depth[fa]+1;
    fu.update(ch,depth[ch]);
    // cout<<ch<<' '<<depth[ch]<<endl;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,fu);
        ans+=fu.merge(ch,to,depth[ch]);
    }
}

void clear()
{
    ans=0;

    for(int i=1;i<=n;i++)
    {
        fa[i]=0;
        if(i<n) fa[i]=i+1;

        p[i].clear();
    }
}

void solve()
{
    cin>>n>>m;clear();

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        fa[u]=max(fa[u],v);
    }

    // for(int i=1;i<=n;i++)
    //     cout<<fa[i]<<' ';
    // cout<<endl;

    for(int i=1;i<n;i++)
        p[fa[i]].push_back(i);

    Segment fu(n);
    dfs(n,0,fu);

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