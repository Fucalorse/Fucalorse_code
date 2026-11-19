#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,MOD=998244353,LEN=3e5;
const LL INF=1e18;

struct peach
{
    private:
        struct qwq
        {
            LL sum;
            LL mul;
        };

        int size;
        vector<qwq>op;

        void add(int id,LL k)
        {
            op[id].sum=op[id].sum*k%MOD;
            op[id].mul=op[id].mul*k%MOD;
        }

        void down(int id)
        {
            if(op[id].mul!=1)
            {
                int hl=id<<1,hr=id<<1|1;

                add(hl,op[id].mul);
                add(hr,op[id].mul);
                op[id].mul=1;
            }
        }

        void multiply(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                add(id,k);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) multiply(l,mid,hl,st,ed,k);
            if(mid<ed) multiply(mid+1,r,hr,st,ed,k);

            op[id].sum=(op[hl].sum+op[hr].sum)%MOD;
        }

        void plus(int l,int r,int id,const int &x,const LL &k)
        {
            if(l==r)
            {
                op[id].sum=(op[id].sum+k)%MOD;
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) plus(l,mid,hl,x,k);
            else plus(mid+1,r,hr,x,k);

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
        peach(int n) { size=n,op.assign((n+90)<<2,{0,1}); }

        void update_multiply(int st,int ed,LL k)
        {
            if(st>ed) exit(-182497);
            multiply(1,size,1,st,ed,k);
        }
        void update_plus(int x,LL k)
        {
            if(x<1||x>size) exit(-182497);
            plus(1,size,1,x,k);
        }
        LL query_point(int x)
        {
            if(x<1||x>size) exit(-182497);
            return query(1,size,1,x);
        }

        int Peach() { return size; }
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

int T,n;
LL pow_2[MAX],inv_2[MAX];

vector<LL> cal_c(int maxn,vector<int>& a,bool flip)
{
    if(flip) reverse(a.begin(),a.end());

    vector<int>st;
    st.push_back(-10086);

    for(int i=1;i<=n;i++)
    {
        if(st.size()&&st.back()>=a[i]) continue;

        if(a[i]<maxn) st.push_back(a[i]);
        if(a[i]==maxn) break;
    }

    int len=st.size()-1;
    vector<LL>dp(n+3,0);
    dp[0]=dp[n+1]=1;

    if(len==0)
    {
        for(int i=1;i<=n;i++)
            dp[i]=1;
        return dp;
    }

    peach fu(len);

    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(st.begin()+1,st.end(),a[i])-st.begin();

        if(pos<=len)
        {
            LL pre=pos==1?1:fu.query_point(pos-1);

            fu.update_multiply(pos,len,2LL);
            if(st[pos]==a[i]) fu.update_plus(pos,pre);
        }

        if(flip) dp[n-i+1]=fu.query_point(len);
        else dp[i]=fu.query_point(len);
    }

    return dp;
}

void create()
{
    LL inv2=cal(2LL,MOD-2);

    pow_2[0]=inv_2[0]=1;
    for(int i=1;i<=LEN;i++)
    {
        pow_2[i]=pow_2[i-1]*2%MOD;
        inv_2[i]=inv_2[i-1]*inv2%MOD;
    }
}

void solve()
{
    cin>>n;

    int maxn=0;
    vector<int>a;

    a.push_back(182497);
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;

        a.push_back(val);
        maxn=max(maxn,val);
    }
    a.push_back(182497);

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }

    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<' ';
    // cout<<endl;

    vector<int>id;
    for(int i=1;i<=n;i++)
        if(a[i]==maxn) id.push_back(i);

    vector<LL>L=cal_c(maxn,a,false),R=cal_c(maxn,a,true);

    LL ans=0,pre=0;
    int len=id.size();
    for(int i=0;i<len;i++)
    {
        int pos=id[i];
        ans=(ans+L[pos-1]*R[pos+1]%MOD)%MOD;

        ans=(ans+pre*R[pos+1]%MOD*pow_2[pos-1]%MOD)%MOD;
        pre=(pre+L[pos-1]*inv_2[pos]%MOD)%MOD;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}