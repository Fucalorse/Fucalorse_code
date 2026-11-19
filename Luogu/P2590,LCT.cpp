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
            int val,sum,maxn;
            bool reverse;

            qwq(int k=-INF)
            {
                fa=ch[0]=ch[1]=0;
                val=sum=maxn=k;
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

            op[x].sum=op[x].maxn=op[x].val;

            int l=op[x].ch[0],r=op[x].ch[1];
            if(l)
            {
                op[x].sum+=op[l].sum;
                op[x].maxn=max(op[x].maxn,op[l].maxn);
            }
            if(r)
            {
                op[x].sum+=op[r].sum;
                op[x].maxn=max(op[x].maxn,op[r].maxn);
            }
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
                    if(get(x)==get(y)) rotate(y);
                    else rotate(x);
                }

                rotate(x);
            }
        }

        void access(int x)
        {
            for(int y=x,last=0;y;y=op[y].fa)
            {
                splay(y);
                op[y].ch[1]=last;
                last=y;
                maintain(y);
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

        void set_value(int x,int k) { op[x]=qwq(k); }

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

            op[y].ch[0]=op[x].fa=0;
            maintain(y);
            return true;
        }

        void modify(int x,int k)
        {
            access(x);
            op[x].val=k;
            maintain(x);
        }

        int query_max(int x,int y)
        {
            makeroot(x);
            access(y);
            return op[y].maxn;
        }

        int query_sum(int x,int y)
        {
            makeroot(x);
            access(y);
            return op[y].sum;
        }
};

struct edge
{
    int u,v;
};

int n,q;
int a[MAX];

void solve()
{
    cin>>n;

    peach fu(n);
    vector<edge>op;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        op.push_back({u,v});
    }

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fu.set_value(i,a[i]);   
    }

    for(auto &[u,v]:op)
        fu.link(u,v);

    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;

        if(s[0]=='C')
        {
            int u,t;
            cin>>u>>t;

            fu.modify(u,t);
        }
        else
        {
            int u,v;
            cin>>u>>v;

            if(s[1]=='M') cout<<fu.query_max(u,v)<<endl;
            else cout<<fu.query_sum(u,v)<<endl;
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