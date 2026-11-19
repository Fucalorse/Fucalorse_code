#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct Bit
{
    private:
        int n;
        vector<LL>op;
    public:
        Bit(int _n):n(_n),op(_n+1){}

        void update(int pos,LL k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]+=k;
        }

        LL query(int pos)
        {
            LL ans=0;
            for(int i=pos;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }
};

struct node
{
    int u,v;
    int round_id;
};

int n,m;
int a[MAX],nxt[MAX],first[MAX],Val[MAX],maxn[MAX];
vector<pair<int,int>>round_pair(MAX);

void solve()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        Val[i]=a[i];
    }

    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++)
        q.push({i,0});

    int round=0;
    while((int)q.size()>=2)
    {
        ++round;
        auto [u,fu]=q.front();q.pop();
        auto [v,fv]=q.front();q.pop();
        nxt[fu]=round;
        nxt[fv]=round;
        if(u<=n) first[u]=round;
        if(v<=n) first[v]=round;
        round_pair[round]={u,v};

        q.push({n+round,round});
    }

    Bit fu(round);

    auto update=[&](int pos)->void
    {
        for(int cur=first[pos];cur;cur=nxt[cur])
        {
            const auto &[u,v]=round_pair[cur];
            fu.update(cur,-maxn[cur]);
            maxn[cur]=max(Val[u],Val[v]);
            fu.update(cur,maxn[cur]);
            Val[cur+n]=min(Val[u],Val[v]);     
        }
    };

    for(int i=1;i<=n;i++)
        update(i);

    while(m--)
    {
        char c;
        cin>>c;

        if(c=='C')
        {
            int x,y;
            cin>>x>>y;
            int numx=Val[x],numy=Val[y];
            Val[x]=numy,update(x);
            Val[y]=numx,update(y);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<fu.query(r)-fu.query(l-1)<<endl;
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