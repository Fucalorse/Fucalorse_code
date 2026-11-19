#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define ULL unsigned long long
const int MAX=1e5+90,LEN=26,MOD=1e9+7,INF=2e9;
const ULL base=131;

struct peach
{
    private:
        vector<ULL>f,pw;
    public:
        peach(const string &s)
        {
            int n=s.size();
            f.assign(n+1,0LL),pw.assign(n+1,0LL);

            pw[0]=1;
            for(int i=1;i<=n;i++)
            {
                f[i]=f[i-1]*base+(ULL)s[i-1];
                pw[i]=pw[i-1]*base;
            }
        }

        ULL cal(int l,int r) { return f[r]-f[l-1]*pw[r-l+1]; }

        ULL get_hash(const string &s)
        {
            ULL ans=0;

            for(auto &cur:s)
                ans=ans*base+(ULL)cur;

            return ans;
        }
};

int n;
int k[MAX];
ULL Val[MAX];
string s,t[MAX];

void solve()
{
    cin>>s>>n;

    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i]>>t[i];
        maxn=max(maxn,(int)t[i].size());
    }

    peach fu(s);
    vector<vector<int>>num(maxn+1);
    for(int i=1;i<=n;i++)
    {
        int len=t[i].size();
        num[len].push_back(i);
        Val[i]=fu.get_hash(t[i]);
    }

    vector<vector<int>>pos(n+1);
    for(int len=1;len<=maxn;len++)
    {
        auto &op=num[len];
        if(op.empty()) continue;

        unordered_map<ULL,int>mp;
        mp.max_load_factor(0.7);
        mp.reserve(op.size());
        for(auto &id:op)
            mp[Val[id]]=id;

        for(int l=0,r=len-1;l<(int)s.size()&&r<(int)s.size();l++,r++)
        {
            ULL now_hash=fu.cal(l+1,r+1);
            if(mp.count(now_hash)) pos[mp[now_hash]].push_back(l);
        }
    }

    for(int i=1;i<=n;i++)
    {
        auto &op=pos[i];
        int len=(int)op.size(),ans=INF;

        for(int l=0,r=k[i]-1;l<len&&r<len;l++,r++)
        {
            int now=op[r]-op[l]+t[i].size();
            ans=min(ans,now);
        }

        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
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