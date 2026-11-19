#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    char c;
    int l,r;
};

int n;
int a[MAX];
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    int c0=0,c1=0,del_0=0,del_1=0;
    vector<qwq>rest;
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&s[l]==s[r]) ++r;

        // cout<<l<<' '<<r-1<<endl;
        if(s[l]=='0')
        {
            c0+=r-l;
            del_0+=max(0,r-l-1);
        }
        else
        {
            c1+=r-l;
            del_1+=max(0,r-l-1);
        }

        rest.push_back({s[l],l,r-1});
    }

    if(abs((c0-del_0)-(c1-del_1))>1)
    {
        cout<<-1<<endl;
        return;
    }

    int ans=del_0+del_1,r=abs(del_0-del_1);
    if(r>1)
    {
        if(del_0<del_1)
        {
            int other=0;
            if(rest.back().c=='0') ++other;
            if((int)rest.size()>=2&&rest.front().c=='0') ++other;

            if(abs(del_0+other-del_1)>1)
            {
                cout<<-1<<endl;
                return;
            }

            ans+=min(abs(del_0-del_1)-1,other);
        }
        else
        {
            int other=0;
            if(rest.back().c=='1') ++other;
            if((int)rest.size()>=2&&rest.front().c=='1') ++other;

            if(abs(del_1+other-del_0)>1)
            {
                cout<<-1<<endl;
                return;
            }

            ans+=min(abs(del_1-del_0)-1,other);
        }
    }

    cout<<ans<<endl;
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