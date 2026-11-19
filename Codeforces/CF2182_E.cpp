#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=2e5+90;

struct qwq
{
    int x,diff;
    bool operator<(const qwq &a)const { return diff>a.diff; }
}op[MAX];

int t,n,m;
LL k;
vector<bool>vis;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        map<int,int>f;
        vis.assign(n+1,false);
        for(int i=1;i<=m;i++)
        {
            int a;
            cin>>a;
            f[a]++;
        }
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            op[i]={x,z-y};
            k-=y;
        }
        sort(op+1,op+n+1);
        for(int i=1;i<=n;i++)
        {
            auto pos=f.lower_bound(op[i].x);
            if(pos!=f.end())
            {
                vis[i]=true;
                if(--pos->second==0) f.erase(pos);
            }
        }
        int ans=0;
        for(int i=n;i>=1;i--)
        {
            if(vis[i]) ans++;
            else if(k>=op[i].diff)
            {
                k-=op[i].diff;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}