#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=1e9;
const LL LINF=9e18;

struct qwq
{
    int l,r,id;
    bool operator<(const qwq &a)const { return l>a.l; }
};

int n;
int a[MAX];

void solve()
{
    cin>>n;

    int maxn=-INF;
    multiset<int>exist;
    vector<vector<qwq>>interval(n+1);
    vector<int>wait;
    for(int i=1;i<=n;i++)
    {
        int k,L,R;
        cin>>k>>L>>R;
        maxn=max(maxn,L);

        int sum=0;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j];
            sum+=a[j];
        }

        for(int j=0,pre=0;j<=k;j++)
        {
            pre+=a[j];
            int st=L+pre,ed=R-(sum-pre);
            interval[i].push_back({st,ed,i});
            wait.push_back(st);
            exist.insert(ed);
        }
    }

    sort(wait.begin(),wait.end());
    wait.erase(unique(wait.begin(),wait.end()),wait.end());
    int ans=0;
    priority_queue<qwq>q;
    vector<int>cur(n+1,0);
    for(int i=1;i<=n;i++)
        q.push(interval[i].front());

    for(auto &fixed:wait)
    {
        if(fixed<maxn) continue;

        while(q.size()&&q.top().l<=fixed)
        {
            auto [l,r,id]=q.top();q.pop();
            auto &op=interval[id];
            int now=cur[id],nxt=++cur[id];
            if(nxt!=(int)op.size()) q.push(op[nxt]);
            if(now>=1)
            {
                auto it=exist.find(op[now-1].r);
                exist.erase(it);
            }
        }

        int L=fixed,R=*exist.begin();
        ans=max(ans,max(0,R-L));
        // cout<<fixed<<' '<<L<<' '<<R<<endl;
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