#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=1e9;

struct peach
{
    private:
        struct qwq
        {
            int maxn,lazy;
            qwq(int mx=0,int lz=0):maxn(mx),lazy(lz){}
        };

        int n;
        vector<qwq>op;

        void add(int id,int k)
        {
            op[id].maxn+=k;
            op[id].lazy+=k;
        }

        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                add(hl,op[id].lazy);
                add(hr,op[id].lazy);
                op[id].lazy=0;
            }
        }

        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                add(id,k);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);

            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
        }
    public:
        peach(int _n) { n=_n,op.assign((n+90)<<2,qwq()); }

        void update(int st,int ed,int k)
        {
            if(st>ed) exit(-182497);
            dfs(1,n,1,st,ed,k);
        }

        void remove(int k)
        {
            int l=1,r=n,id=1;
            vector<int>rest;

            while(l<r)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
                rest.push_back(id);
                down(id);

                if(op[hl].maxn==k)
                {
                    r=mid;
                    id=hl;
                }
                else
                {
                    l=mid+1;
                    id=hr;
                }
            }

            op[id].maxn=-INF;

            reverse(rest.begin(),rest.end());
            for(auto &id:rest)
            {
                int hl=id<<1,hr=id<<1|1;
                op[id].maxn=max(op[hl].maxn,op[hr].maxn);
            }
        }

        int maxn() { return op[1].maxn; }
};

int n;
int p[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        p[i+n]=p[i];
    }

    int m=n<<1,ans=n;
    vector<int>pre(n+2,-INF);
    peach fu(n);

    for(int i=1;i<=m;i++)
    {
        int L=max(1,i-n+1),R=min(n,i),x=p[i];
        pre[x]=i;

        if(L<=R)
        {
            fu.update(L,R,1);
            if(x>1&&pre[x-1]>=L) fu.update(L,min(pre[x-1],R),-1);
            if(x<n&&pre[x+1]>=L) fu.update(L,min(pre[x+1],R),-1);

            while(fu.maxn()>2)
            {
                int cur=fu.maxn();
                fu.remove(cur);
                --ans;
            }
        }
    }

    cout<<ans<<endl;
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