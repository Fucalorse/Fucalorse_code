#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

struct qwq
{
    int pos;
    int mod;
    bool operator<(const qwq &a)const { return pos>a.pos; }
};

int n;
int f[MAX];
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    vector<int>suf(n+1,0);
    suf[n]=n;
    for(int i=n-1;i>=1;i--)
    {
        if(s[i]==s[i+1]) suf[i]=i;
        else suf[i]=suf[i+1];
    }

    LL ans=n;
    vector<LL>sum(3,0LL);
    priority_queue<qwq>q;

    for(int i=1;i<=n;i++)
    {
        while(q.size()&&q.top().pos<i)
        {
            auto [pos,mod]=q.top();q.pop();
            sum[mod]++;
        }

        if(s[i]=='0') f[i]=((f[i-1]-1)%3+3)%3;
        else f[i]=(f[i-1]+1)%3;

        LL now=0;
        for(int j=0;j<3;j++)
        {
            if(j==f[i]) continue;
            ans+=sum[j];
            now+=sum[j];
        }
        // cout<<now<<endl;

        q.push({suf[i],f[i-1]});
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