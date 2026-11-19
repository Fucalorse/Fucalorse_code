#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=5090,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct fucalorse
{
    private:
        struct qwq
        {
            LL key,val,maxn;
            int pri,l,r;
            qwq(LL _key=0,LL _val=0):key(_key),val(_val),maxn(_val),pri(dist(rng)),l(0),r(0){}
        };

        int root,tot;
        vector<qwq>op;

        void maintain(int pos)
        {
            op[pos].maxn=max(op[pos].val,
            max(op[op[pos].l].maxn,op[op[pos].r].maxn));
        }

        pair<int,int> split(int pos,const LL &k)
        {
            if(!pos) return {0,0};
            if(op[pos].key<=k)
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
        fucalorse(int _n)
        {
            root=tot=0;
            op.assign(_n+5,qwq());
        }

        void update(LL key,LL val)
        {
            op[++tot]=qwq(key,val);
            auto [left,right]=split(root,key);
            root=merge(left,tot);
            root=merge(root,right);
        }

        LL get_max(LL val)
        {
            auto [left,right]=split(root,val-1);
            LL ans=right?op[right].maxn:0LL;
            root=merge(left,right);
            return ans;
        }
};

struct qwq
{
    LL w;
    int c;
    bool operator<(const qwq &a)const { return w<a.w; }
}op[MAX];

int n,m;

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>op[i].w>>op[i].c;

    sort(op+1,op+n+1);
    vector<LL>dp(m+1,0LL);
    vector<fucalorse>fu(m+1,fucalorse(n));
    for(int i=1;i<=n;i++)
    {
        const auto &[w,c]=op[i];
        for(int k=m;k>=c;k--)
        {
            LL sum=fu[k-c].get_max(w-1);
            if(sum||(sum==0&&w==1))
            {
                dp[k]=max(dp[k],sum+w);
                fu[k].update(sum,sum+w);
            }
        }
    }

    cout<<dp[m]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}