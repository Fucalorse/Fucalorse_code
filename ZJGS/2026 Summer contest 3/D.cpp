#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int _n) { size=_n,op.assign(size+3,0); }

        void update(int n,int k)
        {
            for(int i=n;i<=size;i+=i&-i)
                op[i]+=k;
        }

        int query(int n)
        {
            int ans=0;

            for(int i=n;i;i-=i&-i)
                ans+=op[i];

            return ans;
        }

        int get(int st,int ed)
        {
            if(st>ed) return 0;
            return query(ed)-query(st-1);
        }
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
        ans+=fu.get(last[a[i]]+1,i-1);

        if(last[a[i]]) fu.update(last[a[i]],-1);
        fu.update(i,1);
        last[a[i]]=i;
    }

    int cnt=st.size();
    ans+=1LL*cnt*(cnt-1)/2;
    ans+=1LL*cnt*(m-cnt);

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