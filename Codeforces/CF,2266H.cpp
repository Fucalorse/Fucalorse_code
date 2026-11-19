#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct fucalorse
{
    private:
        struct qwq
        {
            int maxn;
            bool clear;
            qwq()
            {
                maxn=-INF;
                clear=false;
            }
        };

        int n;
        vector<qwq>op;

        void reset(int id)
        {
            op[id].maxn=-INF;
            op[id].clear=true;
        }

        void down(int id)
        {
            if(op[id].clear)
            {
                int hl=id<<1,hr=id<<1|1;
                reset(hl);
                reset(hr);
                op[id].clear=false;
            }
        }

        void dfs(int l,int r,int id,const int &x,const int &k)
        {
            if(l==r)
            {
                op[id].maxn=max(op[id].maxn,k);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);

            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
        }

        void cover(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                reset(id);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) cover(l,mid,hl,st,ed);
            if(mid<ed) cover(mid+1,r,hr,st,ed);

            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
        }

        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return -INF;
            if(st<=l&&r<=ed) return op[id].maxn;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return max(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        fucalorse(int _n)
        {
            n=_n;
            op.assign((n+90)<<2,qwq());
        }

        void update(int x,int k) { dfs(1,n,1,x,k); }

        void clear(int st,int ed)
        {
            if(st>ed) return;
            cover(1,n,1,st,ed);
        }

        int get(int st,int ed)
        {
            if(st>ed) return -INF;
            return query(1,n,1,st,ed);
        }
};

int n,m;
int b[MAX];

vector<int> cal(const vector<int>& op,vector<vector<int>>& pos)
{
    fucalorse fu(m);
    vector<int>dp(m+1,-INF),ans(m+1,-INF);

    int len=op.size();
    for(auto &x:pos[op[0]])
    {
        dp[x]=1;
        fu.update(x,dp[x]);
        ans[x]=max(ans[x],dp[x]);
    }

    for(int i=1;i<len;i++)
    {
        int max_pos=0;
        for(auto &x:pos[op[i]])
        {
            int now=fu.get(x+1,m);
            if(now!=-INF) dp[x]=now+1;
            max_pos=max(max_pos,x);
        }

        fu.clear(max_pos+1,m);
        for(auto &x:pos[op[i]])
        {
            fu.update(x,dp[x]);
            ans[x]=max(ans[x],dp[x]);
        }
    }

    return ans;
}

void solve()
{
    cin>>n>>m;

    vector<vector<int>>pos(n+1);
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        pos[b[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)
        if(pos[i].empty())
        {
            cout<<-1<<endl;
            return;
        }

    vector<int>op(n);
    for(int i=0;i<n;i++)
        op[i]=i+1;

    vector<int>L=cal(op,pos);
    reverse(op.begin(),op.end());
    vector<int>R=cal(op,pos);

    int maxn=0;
    for(int i=1;i<=m;i++)
        if(L[i]!=-INF&&R[i]!=-INF)
        {
            int now=L[i]+R[i];
            maxn=max(maxn,now-1);
        }

    cout<<n-maxn<<endl;
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