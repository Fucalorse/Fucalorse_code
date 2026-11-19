#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;
LL b[MAX];

void solve()
{
    cin>>n;

    bool ok=false;
    map<LL,vector<int>>f;
    vector<LL>a(n+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        f[b[i]].push_back(i);

        if(b[i]==0) ok=true;
    }

    if(!ok)
    {
        cout<<-1<<endl;
        return;
    }

    LL pre=0,pre_num=0;
    for(auto itl=f.begin();itl!=f.end();++itl)
    {
        auto itr=itl;++itr;
        if(itr==f.end()) break;

        LL numr=itr->first;

        if((numr-pre)%(LL)itl->second.size()!=0)
        {
            cout<<-1<<endl;
            return;
        }

        LL each=(numr-pre)/(LL)itl->second.size();

        if(each<=pre_num)
        {
            cout<<-1<<endl;
            return;
        }

        for(auto &cur:itl->second)
        {
            a[cur]=each;
            pre+=each;
        }

        pre_num=each;
    }

    LL maxn=0;
    for(int i=1;i<=n;i++)
        maxn=max(maxn,a[i]);

    for(int i=1;i<=n;i++)
        if(!a[i]) a[i]=maxn+1;

    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
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