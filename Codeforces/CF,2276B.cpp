#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

string s;

void solve()
{
    cin>>s;

    int len=(int)s.size();
    int have_one=0,have_three=0;
    for(int l=0,r=0;l<len;l=r)
    {
        while(r<len&&s[l]==s[r]) ++r;
        if(r-l==1)
        {
            if(l!=0&&l!=len-1) have_one=1;
        }
        else if(r-l>=3) have_three=1;
    }

    cout<<have_one+have_three+1<<endl;
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