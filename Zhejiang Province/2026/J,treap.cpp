#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct peach
{
    private:
        struct qwq
        {
            int val,timer,size;
            int pri,l,r;
            qwq(int k=0,int t=0,int sz=0):val(k),timer(t),size(sz),pri(dist(rng)),l(0),r(0){}
        };

        int root,tot;
        vector<qwq>op;

        void maintain(int id)
        {
            op[id].size=1;
            if(op[id].l) op[id].size+=op[op[id].l].size;
            if(op[id].r) op[id].size+=op[op[id].r].size;
        }

        pair<int,int> split(int id,int k)
        {
            if(!id) return {0,0};

            int num=op[id].l?op[op[id].l].size+1:1;
            if(k>=num)
            {
                auto [left,right]=split(op[id].r,k-num);
                op[id].r=left;
                maintain(id);
                return {id,right};
            }
            else
            {
                auto [left,right]=split(op[id].l,k);
                op[id].l=right;
                maintain(id);
                return {left,id};
            }
        }

        int merge(int x,int y)
        {
            if(!x||!y) return x|y;

            if(op[x].pri>op[y].pri)
            {
                op[x].r=merge(op[x].r,y);
                maintain(x);
                return x;
            }
            else
            {
                op[y].l=merge(x,op[y].l);
                maintain(y);
                return y;
            }
        }
    public:
        peach(int _n)
        {
            root=tot=0;
            op.assign((_n+90),qwq());
        }

        void insert(int x,int val,int timer)
        {
            ++tot;
            op[tot]=qwq(val,timer,1);

            auto p=split(root,x);
            root=merge(p.first,tot);
            root=merge(root,p.second);
        }

        pair<int,int> kth(int k)
        {
            int id=root;

            while(id)
            {
                int num=op[id].l?op[op[id].l].size:0;

                if(k==num+1) return {op[id].val,op[id].timer};
                if(k<num+1) id=op[id].l;
                else
                {
                    k-=num+1;
                    id=op[id].r;
                }
            }

            return {-10086,-10086};
        }
};

int q,c;

void solve()
{
    cin>>q>>c;

    int timer=0;
    peach row(q),col(q);
    row.insert(0,c,timer),col.insert(0,c,timer);

    while(q--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;

        if(opt==1)
        {
            ++timer;
            row.insert(x,y,timer);
        }
        else if(opt==2)
        {
            ++timer;
            col.insert(x,y,timer);
        }
        else
        {
            auto V_row=row.kth(x);
            auto V_col=col.kth(y);

            if(V_row.second>V_col.second) cout<<V_row.first<<endl;
            else cout<<V_col.first<<endl;
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