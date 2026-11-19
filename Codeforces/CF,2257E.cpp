#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    int pos,h;
    LL minn,profit;
    bool operator<(const qwq &a)const { return minn>a.minn; }
};

int n;
LL x;
int m[MAX];

void solve()
{
    cin>>n>>x;

    vector<vector<LL>>a(n+1),b(n+1);
    vector<vector<qwq>>op(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
        a[i].assign(m[i]+1,0LL);
        b[i].assign(m[i]+1,0LL);

        for(int j=1;j<=m[i];j++)
            cin>>a[i][j];
        for(int j=1;j<=m[i];j++)
            cin>>b[i][j];

        for(int l=1,r=1;l<=m[i];l=r)
        {
            qwq cur={i,0,0,0};

            while(r<=m[i]&&cur.profit<=0)
            {
                cur.minn=max(cur.minn,a[i][r]-cur.profit);
                cur.profit+=b[i][r]-a[i][r];
                cur.h++;
                r++;
            }

            op[i].push_back(cur);
        }
    }

    LL now=x;
    priority_queue<qwq>q;
    vector<int>nxt(n+1,0),ans(n+1,0);

    auto add=[&](int pos)
    {
        if(nxt[pos]>=(int)op[pos].size()||op[pos][nxt[pos]].profit<=0LL) return;

        q.push(op[pos][nxt[pos]]);
        ++nxt[pos];
    };

    for(int i=1;i<=n;i++)
        add(i);

    while(q.size())
    {
        auto [pos,h,minn,profit]=q.top();q.pop();
        if(minn>now) break;

        ans[pos]+=h;
        now+=profit;
        add(pos);
    }

    int maxn=0,pos=1;
    for(int i=1;i<=n;i++)
    {
        int sum=ans[i];
        LL rest=now;
        for(int j=ans[i]+1;j<=m[i];j++)
        {
            if(rest>=a[i][j])
            {
                rest+=b[i][j]-a[i][j];
                ++sum;
            }
            else break;
        }

        if(sum>maxn)
        {
            maxn=sum;
            pos=i;
        }
    }

    cout<<maxn<<' '<<pos<<endl;
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