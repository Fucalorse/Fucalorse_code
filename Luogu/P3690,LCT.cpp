#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9;

struct LCT
{
    private:
        struct qwq
        {
            int fa,ch[2];
            int val,sum,size;
            bool reverse;
            qwq()
            {
                fa=0,ch[0]=ch[1]=0;
                val=sum=size=0;
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
            int l=op[x].ch[0],r=op[x].ch[1];
            op[x].sum=op[x].val^op[l].sum^op[r].sum;
            op[x].size=1+op[l].size+op[r].size;
        }

        void reverse(int x)
        {
            if(!x) return;
            swap(op[x].ch[0],op[x].ch[1]);
            op[x].reverse^=1;
        }

        void pushdown(int x)
        {
            if(!x||!op[x].reverse) return;
            reverse(op[x].ch[0]);
            reverse(op[x].ch[1]);
            op[x].reverse=0;
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
            
            op[y].ch[0]=0;
            op[x].fa=0;

            maintain(y);
            return true;
        }

        void set_value(int x,int val)
        {
            op[x].val=val;
            op[x].sum=val;
            op[x].size=1;
            op[x].reverse=false;
            op[x].ch[0]=op[x].ch[1]=op[x].fa=0;
        }

        void modify(int x,int val)
        {
            access(x);
            op[x].val=val;
            maintain(x);
        }

        int query(int x,int y)
        {
            split(x,y);
            return op[y].sum;
        }
};

int n,q;
int a[MAX];

void solve()
{
    cin>>n>>q;

    LCT fu(n);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fu.set_value(i,a[i]);
    }

    while(q--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;

        if(opt==0) cout<<fu.query(x,y)<<endl;
        else if(opt==1) fu.link(x,y);
        else if(opt==2) fu.cut(x,y);
        else fu.modify(x,y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}