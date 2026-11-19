#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;
LL b[MAX],a[MAX];

void solve()
{
    cin>>n;

    multiset<LL>pos,neg;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]<=0) neg.insert(b[i]);
        else pos.insert(b[i]);
    }

    if(pos.empty())
    {
        cout<<-1<<endl;
        return;
    }

    auto it_st=pos.begin();
    a[1]=*it_st,pos.erase(it_st);

    for(int i=2;i<=n;i++)
    {
        LL neg_max=1-a[i-1];
        
        auto it_neg=neg.lower_bound(neg_max);
        if(it_neg!=neg.end())
        {
            a[i]=a[i-1]+*it_neg;
            neg.erase(it_neg);
            continue;
        }

        if(pos.empty())
        {
            cout<<-1<<endl;
            return;
        }

        auto it_pos=pos.begin();
        a[i]=a[i-1]+*it_pos;
        pos.erase(it_pos);
    }

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