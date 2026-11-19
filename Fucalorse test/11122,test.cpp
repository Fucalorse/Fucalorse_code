#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=3e5+10,MOD=998244353,INF=2e9;

struct discrete
{
    private:
        vector<int>num;
    public:
        void add(int n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int size() { return num.size(); }
};

struct peach
{
    private:
        struct qwq
        {
            LL sum;
            LL lz_mul;
            qwq()
            {
                sum=0;
                lz_mul=1;
            }
        };

        int n;
        vector<qwq>op;

        void multiply(int id,LL k)
        {
            op[id].sum=op[id].sum*k%MOD;
            op[id].lz_mul=op[id].lz_mul*k%MOD;
        }

        void down(int id)
        {
            if(op[id].lz_mul!=1)
            {
                int hl=id<<1,hr=id<<1|1;
                multiply(hl,op[id].lz_mul);
                multiply(hr,op[id].lz_mul);
                op[id].lz_mul=1;
            }
        }

        void dfs_mul(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                multiply(id,k);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs_mul(l,mid,hl,st,ed,k);
            if(mid<ed) dfs_mul(mid+1,r,hr,st,ed,k);

            op[id].sum=(op[hl].sum+op[hr].sum)%MOD;
        }

        void dfs_add(int l,int r,int id,const int &x,const LL &k)
        {
            if(l==r)
            {
                op[id].sum=(op[id].sum+k)%MOD;
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs_add(l,mid,hl,x,k);
            else dfs_add(mid+1,r,hr,x,k);

            op[id].sum=(op[hl].sum+op[hr].sum)%MOD;
        }

        LL query(int l,int r,int id,const int &x)
        {
            if(l==r) return op[id].sum;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) return query(l,mid,hl,x);
            else return query(mid+1,r,hr,x);
        }
    public:
        peach(int _n) { n=_n,op.assign((n+90)<<2,qwq{}); }

        void add(int x,LL k) { dfs_add(0,n,1,x,k); }

        void mutiply(int st,int ed,LL k) { dfs_mul(0,n,1,st,ed,k); }

        LL get(int x) { return query(0,n,1,x); }
};

LL cal(LL a,int p)
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

int n;
int a[MAX];
LL pow2[MAX],inv[MAX];

void create()
{
    pow2[0]=1;
    for(int i=1;i<=LEN;i++)
        pow2[i]=pow2[i-1]*2%MOD;

    inv[LEN]=cal(pow2[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*2%MOD;
}

vector<LL> cal_l(int maxn)
{
    vector<int>st;
    vector<bool>vis(maxn+1,false);
    vector<int>pos(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==maxn) break;

        if(st.empty()||a[i]>st.back())
        {
            st.push_back(a[i]);
            vis[a[i]]=true;
        }
    }

    for(int i=1;i<=n;i++)
        if(vis[a[i]])
        {
            int now=lower_bound(st.begin(),st.end(),a[i])-st.begin()+1;
            pos[i]=now;
        }

    int m=st.size();
    peach fu(m);
    vector<LL>ans(n+10,0);
    ans[0]=ans[n+1]=1;
    fu.add(0,1);

    if(!m)
    {
        for(int i=1;i<=n;i++)
            ans[i]=1;
        return ans;
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==maxn||(st.size()&&a[i]>st.back()))
        {
            ans[i]=fu.get(m);
            continue;
        }

        if(pos[i]==-1)
        {
            int p=upper_bound(st.begin(),st.end(),a[i])-st.begin()+1;
            fu.mutiply(p,m,2);
        }
        else
        {
            LL pre=fu.get(pos[i]-1);
            fu.mutiply(pos[i],m,2);
            fu.add(pos[i],pre);
        }

        ans[i]=fu.get(m);
    }

    return ans;
}

vector<LL> cal_r(int maxn)
{
    vector<int>st;
    vector<bool>vis(maxn+1,false);
    vector<int>pos(n+1,-1);
    for(int i=n;i>=1;i--)
    {
        if(a[i]==maxn) break;

        if(st.empty()||a[i]>st.back())
        {
            st.push_back(a[i]);
            vis[a[i]]=true;
        }
    }

    for(int i=n;i>=1;i--)
        if(vis[a[i]])
        {
            int now=lower_bound(st.begin(),st.end(),a[i])-st.begin()+1;
            pos[i]=now;
        }

    int m=st.size();
    peach fu(m);
    vector<LL>ans(n+10,0);
    ans[0]=ans[n+1]=1;
    fu.add(0,1);

    if(!m)
    {
        for(int i=1;i<=n;i++)
            ans[i]=1;
        return ans;
    }

    for(int i=n;i>=1;i--)
    {
        if(a[i]==maxn||(st.size()&&a[i]>st.back()))
        {
            ans[i]=fu.get(m);
            continue;
        }

        if(pos[i]==-1)
        {
            int p=upper_bound(st.begin(),st.end(),a[i])-st.begin()+1;
            fu.mutiply(p,m,2);
        }
        else
        {
            LL pre=fu.get(pos[i]-1);
            fu.mutiply(pos[i],m,2);
            fu.add(pos[i],pre);
        }

        ans[i]=fu.get(m);
    }

    return ans;
}

void solve()
{
    cin>>n;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dis.add(a[i]);
    }

    dis.create();

    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=dis.find(a[i]);
        maxn=max(maxn,a[i]);
    }

    vector<int>pos;
    vector<LL>pre=cal_l(maxn),suf=cal_r(maxn);
    for(int i=1;i<=n;i++)
        if(a[i]==maxn) pos.push_back(i);

    // for(int i=1;i<=n;i++)
    //     cout<<pre[i]<<' ';
    // cout<<endl;
    // for(int i=n;i>=1;i--)
    //     cout<<suf[i]<<' ';
    // cout<<endl;
    
    LL con=0,ans=0;
    for(auto &x:pos)
    {
        ans=(ans+pre[x-1]*suf[x+1]%MOD)%MOD;

        LL now=con*pow2[x]%MOD*suf[x+1]%MOD;
        ans=(ans+now)%MOD;

        LL cost=pre[x-1]*inv[x+1]%MOD;
        con=(con+cost)%MOD;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}