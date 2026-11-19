#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int n;
        vector<LL>op;
    public:
        peach(int _n):n(_n),op(_n+3){}

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

        LL query_range(int l,int r) { return query(r)-query(l-1); }
};

int n,m;
int a[MAX],last[MAX];

void solve()
{
    cin>>n>>m;
    
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }

    LL ans=0;
    peach fu(n);

    for(int i=1;i<=n;i++)
    {
        int l=last[a[i]]+1,r=i-1;
        if(l<=r) ans+=fu.query_range(l,r);

        if(last[a[i]]) fu.update(last[a[i]],-1);
        fu.update(i,1);
        last[a[i]]=i;
    }

    int cnt=st.size();
    ans+=1LL*m*(m-1)/2;
    ans-=1LL*(m-cnt)*(m-cnt-1)/2;

    cout<<ans<<endl;
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