#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    int S=1;
    while(S<=n) S<<=1;
    vector<int>f;
    for(int i=0;i<S/2;i++)
    {
        if(i&1)
        {
            f.push_back(i);
            f.push_back(i);
            f.push_back(i+(S>>1));
            f.push_back(i+(S>>1));
        }
        else
        {
            f.push_back(i+(S>>1));
            f.push_back(i+(S>>1));
            f.push_back(i);
            f.push_back(i);
        }
    }

    int len=f.size();
    cout<<len-1<<endl;
    for(int i=1;i<len;i++)
        cout<<(f[i]^f[i-1])<<" ";
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