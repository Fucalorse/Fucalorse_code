#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=1e9;

struct peach
{
    private:
        struct qwq
        {
            int fa,ch[2];
            int val,minn,cnt,add;
            bool reverse;
            qwq(int k=INF)
            {
                fa=ch[0]=ch[1]=0;
                val=minn=k;
                add=0;
                cnt=!k;
                reverse=false;
            }
        };

        vector<qwq>op;

        bool isroot(int x)
        {
            int fa=op[x].fa;
            return op[fa].ch[0]!=x&&op[fa].ch[1]!=x;
        }

        int get(int x) { return x==op[op[x].fa].ch[1]; }

        void maintain(int x)
        {
            if(!x) return;

            op[x].minn=op[x].val;

            int l=op[x].ch[0],r=op[x].ch[1];
            op[x].minn=min({op[x].minn,op[l].minn,op[r].minn});
            op[x].cnt=(op[x].val==op[x].minn);
            if(l&&op[l].minn==op[x].minn) op[x].cnt+=op[l].cnt;
            if(r&&op[r].minn==op[x].minn) op[x].cnt+=op[r].cnt;
        }

        void reverse(int x)
        {
            if(!x) return;

            swap(op[x].ch[0],op[x].ch[1]);
            op[x].reverse^=1;
        }

        void apply_add(int x,int k)
        {
            if(!x) return;

            op[x].val+=k;
            op[x].minn+=k;
            op[x].add+=k;
        }

        void pushdown(int x)
        {
            if(!x) return;

            int l=op[x].ch[0],r=op[x].ch[1];
            
            if(op[x].reverse)
            {
                reverse(l),reverse(r);
                op[x].reverse=false;
            }

            if(op[x].add)
            {
                apply_add(l,op[x].add);
                apply_add(r,op[x].add);
                op[x].add=0;
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
            op[y].fa=x;
            op[x].ch[k^1]=y;

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
                    if(get(y)==get(x)) rotate(y);
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

                if(op[x].ch[0]) x=op[x].ch[0];
                else break;
            }

            splay(x);
            return x;
        }
    public:
        peach(int _n) { op.assign(_n+90,qwq{}); }

        void set_value(int x,int k=INF) { op[x]=qwq(k); }

        bool connected(int x,int y)
        {
            makeroot(x);
            return findroot(y)==x;
        }

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
            op[x].val=k;
            maintain(x);
        }

        void add(int x,int y,int k)
        {
            makeroot(x);
            access(y);
            apply_add(y,k);
        }

        int query(int x,int y)
        {
            makeroot(x);
            access(y);
            
            if(op[y].minn==0) return op[y].cnt;
            else return 0;
        }
};

struct edge
{
    int u,v;
}op[MAX];

struct query
{
    int opt,u,v;
}rest[MAX];

int n,m;
int ans[MAX];

void solve()
{
    cin>>n>>m;

    auto update=[&](int &a,int &b)
    {
        if(a>b) swap(a,b);
    };

    int edge_id=n;
    set<pair<int,int>>st;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=m;i++)
    {
        cin>>op[i].u>>op[i].v;
        update(op[i].u,op[i].v);

        pair<int,int>now={op[i].u,op[i].v};
        st.insert(now);

        if(mp.count(now)) continue;
        mp[now]=++edge_id;
    }

    int tot=0,opt;
    while(cin>>opt)
    {
        if(opt==-1) break;
        int u,v;
        cin>>u>>v;
        update(u,v);

        ++tot;
        rest[tot]={opt,u,v};

        if(opt==0)
        {
            pair<int,int>now={u,v};
            st.erase(now);

            if(mp.count(now)) continue;
            mp[now]=++edge_id;
        }
    }

    peach fu(edge_id);
    for(int i=1;i<=n;i++)
        fu.set_value(i,INF);

    for(auto &[u,v]:st)
    {
        if(fu.connected(u,v)) fu.add(u,v,1);
        else
        {
            int edge_id=mp[make_pair(u,v)];
            fu.set_value(edge_id,0);
            fu.link(u,edge_id);
            fu.link(edge_id,v);
        }
    }

    for(int i=tot;i>=1;i--)
    {
        auto [opt,u,v]=rest[i];

        if(opt==0)
        {
            if(fu.connected(u,v)) fu.add(u,v,1);
            else
            {
                int edge_id=mp[make_pair(u,v)];
                fu.set_value(edge_id,0);
                fu.link(u,edge_id);
                fu.link(edge_id,v);
            }
        }
        else ans[i]=fu.query(u,v);
    }

    for(int i=1;i<=tot;i++)
    {
        if(rest[i].opt==0) continue;
        cout<<ans[i]<<endl;
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