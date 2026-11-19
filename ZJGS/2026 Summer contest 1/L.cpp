#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e5+90,LEN=1e6,MOD=998244353,INF=2e9;

struct peach
{
    private:
        struct qwq
        {
            vector<LL>cost;
            vector<int>end_state;
            qwq(int S)
            {
                cost.assign(S+1,0LL);
                end_state.assign(S+1,0);
            }
        };

        int n,m,S;
        vector<qwq>op;
        vector<vector<LL>>cnt;

        void update(int l,int id)
        {
            for(int k=0;k<S;k++)
            {
                LL pre=0;
                int state=0;
                qwq &now=op[id];
                now.cost[k]=now.end_state[k]=0;

                for(int i=0;i<n-1;i++)
                {
                    pre+=cnt[i][l];
                    if((k>>i)&1) ++pre;

                    if(pre&1) state|=1<<i;
                    now.cost[k]+=pre>>1;
                    pre>>=1;
                }

                pre+=cnt[n-1][l];
                now.end_state[k]=state;
                now.cost[k]+=(m-l)*pre;
            }
        }

        qwq merge(const qwq &a,const qwq &b)
        {
            qwq ans=qwq(S);

            for(int leftstate=0;leftstate<S;leftstate++)
            {
                int midstate=a.end_state[leftstate];
                int rightstate=b.end_state[midstate];

                ans.cost[leftstate]=a.cost[leftstate]+b.cost[midstate]+__builtin_popcount(midstate);
                // ans.cost[leftstate]=a.cost[leftstate]+b.cost[midstate];
                ans.end_state[leftstate]=rightstate;
            }

            return ans;
        }

        void create(int l,int r,int id)
        {
            if(l==r)
            {
                update(l,id);
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);

            op[id]=merge(op[hl],op[hr]);
        }

        void dfs(int l,int r,int id,const int &row,const int &col,const LL &val)
        {
            if(l==r)
            {
                cnt[row][col]+=val;
                update(l,id);
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(col<=mid) dfs(l,mid,hl,row,col,val);
            else dfs(mid+1,r,hr,row,col,val);

            op[id]=merge(op[hl],op[hr]);
        }
    public:
        peach(int _n,int _m,vector<vector<LL>>& a)
        {
            n=_n,m=_m;
            S=(1<<(n-1));
            op.assign((m+90)<<2,qwq(S));
            cnt=a;

            create(1,m,1);
        }

        void revise(int x,int y,LL val) { dfs(1,m,1,x,y,val); }

        LL query() { return op[1].cost[0]; }
};

int n,m,q;

void solve()
{
    cin>>n>>m>>q;

    vector<vector<LL>>a(n+1,vector<LL>(m+1,0));
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    peach fu(n,m,a);

    while(q--)
    {
        int x,y;
        LL val;
        cin>>x>>y>>val;--x;

        fu.revise(x,y,val);
        cout<<fu.query()<<endl;
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