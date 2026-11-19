#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

LL qpow(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ans;
}

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct fucalorse
{
    private:
        struct qwq
        {
            LL val,sum;
            int sz,pri;
            int l,r;
            qwq(LL _val=0,int _sz=0):val(_val),sum(_val),sz(_sz),
            pri(dist(rng)),l(0),r(0){}
        };

        int root,tot;
        vector<qwq>op;

        void maintain(int pos)
        {
            op[pos].sum=op[pos].val+op[op[pos].l].sum+op[op[pos].r].sum;
            op[pos].sz=(1+op[op[pos].l].sz+op[op[pos].r].sz);
        }

        pair<int,int> split_size(int pos,int k)
        {
            if(!pos) return {0,0};
            int cnt=op[pos].l?op[op[pos].l].sz+1:1;
            if(k>=cnt)
            {
                auto [left,right]=split_size(op[pos].r,k-cnt);
                op[pos].r=left;
                maintain(pos);
                return {pos,right};
            }
            else
            {
                auto [left,right]=split_size(op[pos].l,k);
                op[pos].l=right;
                maintain(pos);
                return {left,pos};
            }
        }

        pair<int,int> split_val(int pos,const LL &k)
        {
            if(!pos) return {0,0};
            if(op[pos].val<k)
            {
                auto [left,right]=split_val(op[pos].r,k);
                op[pos].r=left;
                maintain(pos);
                return {pos,right};
            }
            else
            {
                auto [left,right]=split_val(op[pos].l,k);
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

        void print(int pos)
        {
            if(!pos) return;
            print(op[pos].l);
            cout<<op[pos].val<<' ';
            print(op[pos].r);
        }
    public:
        fucalorse(int _n)
        {
            root=tot=0;
            op.assign(_n+5,qwq());
        }

        void update(LL val)
        {
            op[++tot]=qwq(val,1);
            auto [left,right]=split_val(root,val);
            root=merge(left,tot);
            root=merge(root,right);
            // print(root);
            // cout<<endl;
        }

        LL kth(int k)
        {
            int pos=root;
            while(pos)
            {
                int cnt=op[pos].l?op[op[pos].l].sz+1:1;
                if(k==cnt) return op[pos].val;
                if(k>cnt)
                {
                    k-=cnt;
                    pos=op[pos].r;
                }
                else pos=op[pos].l;
            }
            return LINF;
        }

        pair<LL,LL> get(int mid)
        {
            int total_cnt=op[root].sz;
            LL mid_val=kth(mid),total_sum=op[root].sum;
            LL left_val=kth(mid-1),right_val=kth(mid+1);
            auto [left,right]=split_size(root,mid-1);

            int left_cnt=op[left].sz,right_cnt=total_cnt-left_cnt-1;
            --left_cnt,--right_cnt;
            LL left_sum=op[left].sum,right_sum=total_sum-left_sum-mid_val;
            left_sum-=left_val,right_sum-=right_val;

            // cout<<mid<<' '<<" left_val:"<<left_val<<" left_cnt:"<<left_cnt<<" left_sum:"<<left_sum<<endl;
            // cout<<mid<<' '<<"right_val:"<<right_val<<" right_cnt:"<<right_cnt<<" right_sum:"<<right_sum<<endl;
            
            auto cal=[&](LL val,int cnt,LL sum)->LL
            {
                LL now=cnt*val;
                return llabs(sum-now);
            };
            root=merge(left,right);
            
            if(left_val==LINF) return {-LINF,cal(right_val,right_cnt,right_sum)};
            else if(right_val==LINF) return {cal(left_val,left_cnt,left_sum),-LINF};
            else return {cal(left_val,left_cnt,left_sum),cal(right_val,right_cnt,right_sum)};
        }
};

int n;
LL a[MAX],len_inv[MAX];

void create()
{
    for(int i=1;i<=LEN;i++)
        len_inv[i]=qpow(i,MOD-2);
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    fucalorse fu(n);
    fu.update(a[1]),fu.update(a[2]);
    for(int i=3;i<=n;i++)
    {
        fu.update(a[i]);
        LL minn=LINF;
        int l=1,r=i;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            auto [left,right]=fu.get(mid);
            // cout<<mid<<' '<<left<<' '<<right<<endl;
            minn=min(minn,max(left,right));
            if(left>right) r=mid-1;
            else l=mid+1;
        }
        cout<<minn%MOD*len_inv[i-2]%MOD<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}