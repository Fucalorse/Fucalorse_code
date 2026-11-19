#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int b[MAX];

void solve()
{
    cin>>n;

    vector<int>f(n+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]>0)
        {
            int l=max(1,i-b[i]+1),r=min(n,i+b[i]-1);
            ++f[l],--f[r+1];
        }
    }

    for(int i=1;i<=n;i++)
        f[i]+=f[i-1];

    // for(int i=1;i<=n;i++)
    //     cout<<(f[i]>=1)<<' ';
    // cout<<endl;

    string s;

    for(int i=1;i<=n;i++)
    {
        if(b[i]!=-1)
        {
            int l=max(1,i-b[i]),r=min(n,i+b[i]);
            if(f[l]&&f[r])
            {
                cout<<-1<<endl;
                return;
            }
        }

        if(f[i]) s.push_back('0');
        else s.push_back('1');
    }

    cout<<s<<endl;
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