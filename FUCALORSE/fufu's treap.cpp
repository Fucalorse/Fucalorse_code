#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct peach
{
    private:
        struct qwq
        {
            int val,size,pri;
            int l,r;
            qwq(int k=0,int sz=0):val(k),size(sz),pri(dist(rng)),l(0),r(0){}
        };

        int root,tot;
        vector<qwq>op;

        void maintain(int pos) { op[pos].size=1+op[op[pos].l].size+op[op[pos].r].size; }

        pair<int,int> split(int pos,const int &k)
        {
            if(!pos) return {0,0};
            
            if(k>=op[pos].val)
            {
                auto [left,right]=split(op[pos].r,k);
                op[pos].r=left;
                maintain(pos);
                return {pos,right};
            }
            else
            {
                auto [left,right]=split(op[pos].l,k);
                op[pos].l=right;
                maintain(pos);
                return {left,pos};
            }
        }

        int merge(int left,int right)
        {
            if(!left||!right) return left|right;

            if(op[left].pri>op[right].pri)
            {
                op[left].r=merge(op[left].r,right);
                maintain(left);
                return left;
            }
            else
            {
                op[right].l=merge(left,op[right].l);
                maintain(right);
                return right;
            }
        }
    public:
        peach(int _n)
        {
            tot=root=0;
            op.assign(_n+90,qwq());
        }

        void insert(int val)
        {
            op[++tot]=qwq(val,1);
            auto [left,right]=split(root,val);
            root=merge(left,tot);
            root=merge(root,right);
        }

        void remove(int target)
        {
            int now=root,fa=0,type=0;
            vector<int>st;

            while(now)
            {
                if(op[now].val==target)
                {
                    int node=merge(op[now].l,op[now].r);
                    if(fa)
                    {
                        if(type==0) op[fa].l=node;
                        else op[fa].r=node;
                    }
                    else root=node;
                    break;
                }

                st.push_back(now);

                if(target<op[now].val)
                {
                    fa=now;
                    now=op[now].l;
                    type=0;
                }
                else
                {
                    fa=now;
                    now=op[now].r;
                    type=1;
                }
            }

            while(st.size())
            {
                int pos=st.back();st.pop_back();
                maintain(pos);
            }
        }

        int lower_bound(int target)
        {
            int now=root,ans=INF;

            while(now)
            {
                if(op[now].val>=target)
                {
                    ans=op[now].val;
                    now=op[now].l;
                }
                else now=op[now].r;
            }

            return ans;
        }

        int upper_bound(int target)
        {
            int now=root,ans=INF;

            while(now)
            {
                if(op[now].val>target)
                {
                    ans=op[now].val;
                    now=op[now].l;
                }
                else now=op[now].r;
            }

            return ans;
        }

        bool count(int target)
        {
            int now=root;

            while(now)
            {
                if(op[now].val==target) return true;

                if(target<op[now].val) now=op[now].l;
                else now=op[now].r;
            }

            return false;
        }
};

void solve()
{
    peach fu(114514);

    cout<<"Furina , the most famous goddess in the world!!"<<endl;  
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