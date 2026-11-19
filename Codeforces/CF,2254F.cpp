#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    a[0]=b[0]=0;
    int suma=0,sumb=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        suma^=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        sumb^=b[i];
    }

    int x=suma^sumb;
    vector<int>fa,fb;
    for(int i=0;i<=n;i++)
    {
        fa.push_back(a[i]^x);
        fb.push_back(b[i]);
    }

    sort(fa.begin(),fa.end());
    sort(fb.begin(),fb.end());

    for(size_t i=0;i<fa.size();i++)
        if(fa[i]!=fb[i])
        {
            cout<<"NO"<<endl;
            return;
        }

    cout<<"YES"<<endl;
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