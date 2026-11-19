#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
LL a[MAX],pos[MAX],neg[MAX];

void dfs(int ch,int fa,vector<vector<int>>& p)
{
    LL x=0,y=0;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,p);
        x=max(x,pos[to]),y=max(y,neg[to]);
        pos[ch]=max(pos[ch],pos[to]),neg[ch]=max(neg[ch],neg[to]);
    }

    if((int)p[ch].size()==1&&ch!=1)
    {
        if(a[ch]<0) pos[ch]=-a[ch];
        else neg[ch]=a[ch];
        return;
    }

    LL now=a[ch]+x-y;
    // cout<<ch<<' '<<now<<endl;
    if(now>0) neg[ch]+=now;
    else pos[ch]-=now;
}

void solve()
{
    cin>>n;

    vector<vector<int>>p(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        cin>>a[i];

    dfs(1,0,p);

    // for(int i=1;i<=n;i++)
    //     cout<<i<<"::"<<pos[i]<<' '<<neg[i]<<endl;

    cout<<pos[1]+neg[1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}