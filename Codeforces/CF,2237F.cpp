#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m;
int a[MAX];
bool ok[MAX];

vector<int> cal_l()
{
    deque<int>q;
    vector<int>dp(n+3,0);
    int maxn=0,tag=0;

    for(int i=1;i<=m;i++)
        q.push_back(0);

    for(int i=1;i<=n;i++)
    {
        tag=max(tag,q.back());
        q.push_front(maxn),q.pop_back();

        int dx=ok[i];
        q[a[i]-1]=max(q[a[i]-1],tag)+dx;
        maxn=max(maxn,q[a[i]-1]);

        dp[i]=maxn;
    }

    return dp;
}

vector<int> cal_r()
{
    deque<int>q;
    vector<int>dp(n+3,0);
    int maxn=0,tag=0;

    for(int i=1;i<=m;i++)
        q.push_back(0);

    for(int i=n;i>=1;i--)
    {
        tag=max(tag,q.front());
        q.push_back(maxn),q.pop_front();

        int dx=ok[i];
        q[a[i]-1]=max(q[a[i]-1],tag)+dx;
        maxn=max(maxn,q[a[i]-1]);

        dp[i]=maxn;
    }

    return dp;
}

void solve()
{
    cin>>n>>m;

    int st=1,ed=n-m+1;
    vector<int>cnt(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int pos=i-a[i]+1,l=st+a[i]-1,r=ed+a[i]-1;

        if(pos>=1&&pos<=n) ++cnt[pos];

        if(i>=l&&i<=r) ok[i]=true;
        else ok[i]=false;
    }

    int minn=INF;
    vector<int>L=cal_l(),R=cal_r();

    for(int l=1,r=m;l<=n&&r<=n;l++,r++)
    {
        int save=L[l-1]+R[r+1]+cnt[l];
        minn=min(minn,n-save);
    }

    cout<<minn<<endl;
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