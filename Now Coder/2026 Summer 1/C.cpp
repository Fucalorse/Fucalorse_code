#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9;
const vector<pair<int,int>>h={{-1,0},{0,1},{1,0},{0,-1}};

struct LCT
{
    private:
        struct qwq
        {
            int fa,ch[2];
            int val,maxn,size;
            bool reverse;
            qwq(int k=-INF,int sz=0)
            {
                fa=ch[0]=ch[1]=0;
                val=maxn=k,size=sz;
                reverse=false;
            }
        };
        vector<qwq>op;

        bool isroot(int x)
        {
            int fa=op[x].fa;
            return x!=op[fa].ch[0]&&x!=op[fa].ch[1];
        }

        int get(int x) { return x==op[op[x].fa].ch[1]; }

        void maintain(int x)
        {
            if(!x) return;
            int l=op[x].ch[0],r=op[x].ch[1];
            op[x].size=1+op[l].size+op[r].size;
            op[x].maxn=max({op[x].val,op[l].maxn,op[r].maxn});
        }

        void reverse(int x)
        {
            if(!x) return;
            swap(op[x].ch[0],op[x].ch[1]);
            op[x].reverse^=1;
        }

        void pushdown(int x)
        {
            if(!x) return;

            if(op[x].reverse)
            {
                reverse(op[x].ch[0]);
                reverse(op[x].ch[1]);
                op[x].reverse=false;
            }
        }

        void pushall(int x)
        {
            if(!isroot(x)) pushall(op[x].fa);
            pushdown(x);
        }

        void rotate(int x)
        {
            int y=op[x].fa,z=op[y].fa;
            int k=get(x),w=op[x].ch[k^1];

            if(!isroot(y)) op[z].ch[get(y)]=x;
            op[x].fa=z;

            op[y].ch[k]=w;
            if(w) op[w].fa=y;
            op[x].ch[k^1]=y;
            op[y].fa=x;

            maintain(y);
            maintain(x);
        }

        void splay(int x)
        {
            pushall(x);

            while(!isroot(x))
            {
                int y=op[x].fa;

                if(!isroot(y))
                {
                    if(get(x)==get(y)) rotate(y);
                    else rotate(x);
                }

                rotate(x);
            }
        }

        void access(int x)
        {
            int last=0;

            for(int y=x;y;y=op[y].fa)
            {
                splay(y);
                op[y].ch[1]=last;
                maintain(y);
                last=y;
            }

            splay(x);
        }

        void makeroot(int x)
        {
            access(x);
            reverse(x);
        }

        int findroot(int x)
        {
            access(x);

            while(1)
            {
                pushdown(x);
                if(!op[x].ch[0]) break;
                x=op[x].ch[0];
            }

            splay(x);
            return x;
        }
    public:
        LCT(int _n) { op.assign(_n+90,qwq{}); }

        void set_value(int x,int k) { op[x]=qwq(k,1); }

        bool link(int x,int y)
        {
            makeroot(x);
            if(findroot(y)==x) return false;
            op[x].fa=y;
            return true;
        }

        bool cut(int x,int y)
        {
            makeroot(x);
            access(y);

            if(op[y].ch[0]!=x||op[x].ch[1]!=0) return false;

            op[x].fa=0;
            op[y].ch[0]=0;

            maintain(y);
            return true;
        }

        void modify(int x,int k)
        {
            access(x);
            op[x].val=op[x].maxn=k;
            maintain(x);
        }

        int query(int x,int y)
        {
            makeroot(x);
            access(y);
            return op[y].maxn;
        }
};

int n,m,q;
int fa[MAX],sz[MAX],op[MAX];
bool vis[MAX];

void create()
{
    for(int i=1;i<=n*m;i++)
        fa[i]=i;
}

int get_id(int x,int y) { return (x-1)*m+y; }

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void solve()
{
    cin>>n>>m>>q;create();

    LCT fu(n*m);
    vector<vector<int>>id(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            id[i][j]=get_id(i,j);
            fu.set_value(id[i][j],-INF);
        }
     
    auto check=[&](int x,int y) { return x>=1&&x<=n&&y>=1&&y<=m; };

    int pre=0;
    while(q--)
    {
        int p;
        cin>>p;
        
        if(p==1)
        {
            int x,y,v;
            cin>>x>>y>>v;
            x^=pre,y^=pre;

            int pos=id[x][y];

            vector<int>rest;
            for(auto &[dx,dy]:h)
            {
                int nx=x+dx,ny=y+dy;
                if(!check(nx,ny)) continue;

                int npos=find(id[nx][ny]);
                if(!vis[npos]) continue;
                rest.push_back(npos);
            }

            sort(rest.begin(),rest.end());
            rest.erase(unique(rest.begin(),rest.end()),rest.end());

            int ans=0;
            for(auto &cur:rest)
            {
                ans+=sz[cur];
                int now=v-sz[cur]+1;
                fa[cur]=pos;
                fu.link(cur,pos);
                fu.modify(cur,now);
            }

            vis[pos]=true;
            sz[pos]=ans+1;
            op[pos]=v;

            cout<<ans<<endl;
            pre=ans;
        }
        else
        {
            int x,y;
            cin>>x>>y;
            x^=pre,y^=pre;
            int pos=id[x][y];

            int now=max(op[pos],fu.query(pos,find(pos)));

            cout<<now-op[pos]<<endl;
            pre=now-op[pos];
        }
    }
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