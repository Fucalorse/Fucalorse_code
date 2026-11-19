#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    map<LL,int>f;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
        ++f[a[i]];
    }

    LL sum=0;
    vector<LL>rest;
    for(auto &[val,cnt]:f)
    {
        int k=cnt>>1,r=cnt&1;
        if(k&1) sum^=val;
        if(r&1) rest.push_back(val);
    }

    if(rest.empty())
    {
        if(sum==0) cout<<"Menji"<<endl;
        else cout<<"Bot"<<endl;
    }
    else if((int)rest.size()==2)
    {
        for(auto &cur:rest)
            if((sum^cur)==0)
            {
                cout<<"Menji"<<endl;
                return;
            }
        cout<<"Bot"<<endl;
    }
    else cout<<"Bot"<<endl;
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