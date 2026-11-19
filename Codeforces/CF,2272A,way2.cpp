#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int maxn=0;
    pair<int,int>best={0,0};

    auto update=[&](int i,int j)
    {
        swap(a[i],a[j]);

        int ans=0,m=n-k+1;
        vector<bool>vis(n+1,false);
        for(int i=1;i<=m;i++)
            vis[a[i]]=true;

        for(int i=0;i<=n;i++)
        {
            if(vis[i]) ++ans;
            else break;
        }

        swap(a[i],a[j]);
        
        if(ans>maxn)
        {
            maxn=ans;
            best={i,j};
        }
    };
    update(0,0);

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            update(i,j);

    if(best.first==0) cout<<-1<<endl;
    else cout<<best.first<<' '<<best.second<<endl;
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