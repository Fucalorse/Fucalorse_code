#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e5+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;
typedef array<LL,26> ovo;

int n,m;
string s[MAX];

void solve()
{
    cin>>n>>m;

    ovo cnt={},a={};
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(auto &c:s[i])
        {
            ++a[c-'A'];
            cnt[c-'A']+=m;
        }
    }

    for(int i=1;i<=n;i++)
    {
        ovo temp=cnt,b=a;
        bool ok=true;
        for(auto &c:s[i])
        {
            int p=c-'A';
            b[p]--;
            temp[p]-=m+1;
            if(temp[p]<0)
            {
                ok=false;
                break;
            }
        }

        if(!ok)
        {
            cout<<-1<<' ';
            continue;
        }

        auto check=[&](LL mid)->bool
        {
            for(int i=0;i<26;i++)
            {
                if(b[i]*mid>temp[i]) return false;
            }
            return true;
        };

        LL l=0,r=1LL*n*m;
        while(l<=r)
        {
            LL mid=(l+r)>>1;
            if(check(mid)) l=mid+1;
            else r=mid-1;
        }

        cout<<r<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}