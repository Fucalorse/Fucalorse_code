#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct discrete
{
    private:
        vector<LL>num;
    public:
        void add(LL n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(LL n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int size() { return (int)num.size(); }
};

struct Bit
{
    private:
        int n;
        vector<int>op;
    public:
        Bit(int _n):n(_n),op(_n+1,0){}

        void update(int pos,int k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]+=k;
        }

        int query(int pos)
        {
            int ans=0;
            for(int i=pos;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }
};

int n;
LL a[MAX],f[MAX];

void solve()
{
    cin>>n;

    bool ok=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
        if(f[i]<0) ok=false;
    }

    if(!ok)
    {
        cout<<-1<<endl;
        return;
    }

    discrete dis;
    for(int i=1;i<=n;i++)
        dis.add(f[i]);
    dis.create();

    LL ans=0;
    Bit fu(dis.size());
    for(int i=n;i>=1;i--)
    {
        int pos=dis.find(f[i]);
        ans+=fu.query(pos-1);
        fu.update(pos,1);
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