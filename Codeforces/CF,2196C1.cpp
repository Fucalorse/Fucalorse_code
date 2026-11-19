#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct Edge
{
    int u,v;
    bool operator==(const Edge &a)const { return u==a.u&&v==a.v; }
};

int n;
int pos[MAX],tot;

void ask(int k)
{
    cout<<"? "<<k<<endl<<flush;

    cin>>tot;
    for(int i=1;i<=tot;i++)
        cin>>pos[i];
}

void solve()
{
    cin>>n;

    int now=1,S=(1<<n)-1;
    vector<Edge>ans;
    while(1)
    {
        ask(now);
        if(tot==0) break;
        if(tot==1)
        {
            now++;
            continue;
        }

        Edge edge={pos[1],pos[2]};
        ans.push_back(edge);

        int l=now,r=S;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            ask(mid);
            if(tot<=1)
            {
                r=mid-1;
                continue;
            }

            Edge cur_edge={pos[1],pos[2]};
            if(edge==cur_edge) l=mid+1;
            else r=mid-1;
        }

        now=l;
    }

    cout<<"! "<<ans.size()<<endl<<flush;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl<<flush;
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