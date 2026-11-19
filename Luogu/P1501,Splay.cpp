#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=51061,INF=2e9;

struct LCT
{
    private:
        struct qwq
        {
            int fa,ch[2];
            int val,size;
            LL sum,add,mul;
            bool reverse;
            qwq(LL k=0,int sz=0)
            {
                fa=ch[0]=ch[1]=0;
                val=k,size=sz;
                sum=k,add=0,mul=1;
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
            int l=op[x].ch[0],r=op[x].ch[1];
            op[x].sum=(op[x].val+op[l].sum+op[r].sum)%MOD;
            op[x].size=1+op[l].size+op[r].size;
        }

        void reverse(int x)
        {
            if(!x) return;
            swap(op[x].ch[0],op[x].ch[1]);
            op[x].reverse^=1;
        }

        void apply_add(int x,LL k)
        {
            if(!x) return;
            op[x].val=(op[x].val+k)%MOD;
            op[x].add=(op[x].add+k)%MOD;
            op[x].sum=(op[x].sum+k*op[x].size)%MOD;
        }

        void apply_mul(int x,LL k)
        {
            if(!x) return;
            op[x].val=op[x].val*k%MOD;
            op[x].add=op[x].add*k%MOD;
            op[x].mul=op[x].mul*k%MOD;
            op[x].sum=op[x].sum*k%MOD;
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

            if(op[x].mul!=1)
            {
                apply_mul(op[x].ch[0],op[x].mul);
                apply_mul(op[x].ch[1],op[x].mul);
                op[x].mul=1;
            }

            if(op[x].add)
            {
                apply_add(op[x].ch[0],op[x].add);
                apply_add(op[x].ch[1],op[x].add);
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

        void split(int x,int y)
        {
            makeroot(x);
            access(y);
        }
    public:
        LCT(int _n) { op.assign(_n+90,qwq{}); }

        void set_value(int x,LL k) { op[x]=qwq(k,1); }

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

        void modify(int x,LL val)
        {
            access(x);
            op[x].val=val;
            maintain(x);
        }

        void plus(int x,int y,LL val)
        {
            makeroot(x);
            access(y);
            apply_add(y,val);
        }

        void multiply(int x,int y,LL val)
        {
            makeroot(x);
            access(y);
            apply_mul(y,val);
        }

        LL qeury(int x,int y)
        {
            split(x,y);
            return op[y].sum;
        }
};

struct Edge
{
    int u,v;
}edge[MAX];

int n,q;

void solve()
{
    cin>>n>>q;

    LCT fu(n);

    for(int i=1;i<=n;i++)
        fu.set_value(i,1);
    for(int i=1;i<n;i++)
    {
        cin>>edge[i].u>>edge[i].v;
        fu.link(edge[i].u,edge[i].v);
    }

    while(q--)
    {
        char c;
        cin>>c;

        if(c=='+')
        {
            int u,v;
            LL val;
            cin>>u>>v>>val;
            
            fu.plus(u,v,val);
        }
        else if(c=='-')
        {
            int u1,v1,u2,v2;
            cin>>u1>>v1>>u2>>v2;

            fu.cut(u1,v1);
            fu.link(u2,v2);
        }
        else if(c=='*')
        {
            int u,v;
            LL val;
            cin>>u>>v>>val;

            fu.multiply(u,v,val);
        }
        else
        {
            int u,v;
            cin>>u>>v;

            cout<<fu.qeury(u,v)<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}