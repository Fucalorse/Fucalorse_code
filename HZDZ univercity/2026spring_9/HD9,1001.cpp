#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int n,m;
int cnt[MAX];
bool disappear[MAX],walk[MAX];
LL op[MAX],x[MAX],y[MAX];
map<LL,vector<LL>>mp;

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        LL x,y;
        cin>>x>>y;
        op[i]=y;
        mp[x].push_back(i);
    }
    while(m--)
    {
        LL l,r,u,v;
        cin>>l>>r>>u>>v;
        auto itl=mp.lower_bound(l),itr=mp.upper_bound(r);
        map<LL,vector<LL>>now;
        for(auto it=itl;it!=itr&&it->first<=r;++it)
        {
            for(auto &cur:it->second)
            {
                cnt[cur]++;
                if(cnt[cur]>=6)
                {
                    disappear[cur]=true;
                    continue;
                }
                walk[cur]=true;
                now[it->first+u].push_back(cur);
                op[cur]+=v;
            }
        }
        mp.erase(itl,itr);
        for(auto it=now.begin();it!=now.end();++it)
        {
            for(auto &cur:it->second)
                mp[it->first].push_back(cur);
        }
    }
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        for(auto &cur:it->second)
            x[cur]=it->first,y[cur]=op[cur];
    }
    for(int i=1;i<=n;i++)
    {
        if(disappear[i]) cout<<"Disappeared"<<endl;
        else if(walk[i]) cout<<"Cirrus"<<' '<<x[i]<<' '<<y[i]<<endl;
        else cout<<"Cumulus"<<' '<<x[i]<<' '<<y[i]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}