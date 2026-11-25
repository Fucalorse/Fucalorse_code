#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct qwq
{
    LL a,b;
    bool operator<(const qwq &other)const
    {
        if(b!=other.b) return b<other.b;
        return a<other.a;
    }
    bool operator>(const qwq &other)const
    {
        if(b!=other.b) return b>other.b;
        return a>other.a;
    }
};

int n;
LL A,B,C;

void solve()
{
    cin>>n>>A>>B>>C;

    vector<qwq>op;
    for(int i=1;i<=n;i++)
    {
        LL a,b;
        cin>>a>>b;
        if(b<=B) op.push_back({a,b});
    }

    sort(op.begin(),op.end(),greater<qwq>());

    int ans=0;
    LL sum=0;
    priority_queue<LL>q;
    auto check=[&](LL a,LL b)->bool
    {
        LL left=(A-(sum+a))*B,right=b*C;
        return left>=right;
    };

    for(const auto &[a,b]:op)
    {
        if(check(a,b))
        {
            q.push(a);
            sum+=a;
        }
        else if(q.size())
        {
            LL cur=q.top();
            if(a>cur) continue;
            sum-=cur;
            q.pop();
            q.push(a);
            sum+=a;
        }

        ans=max(ans,(int)q.size());
    }

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