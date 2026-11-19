#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    int l,r;
    char col;
};

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    vector<qwq>op;
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&s[l]==s[r]) r++;

        if(r-l>1&&s[l]=='0')
        {
            cout<<-1<<endl;
            return;
        }

        op.push_back({l,r-1,s[l]});
    }

    if(op.front().col=='0')
    {
        cout<<-1<<endl;
        return;
    }

    auto check=[&](int k)
    {
        set<int>dp;
        dp.insert(0);

        for(int pos=1;pos<=n;pos++)
        {
            set<int>ndp;

            if(s[pos]=='+')
            {
                for(int num=1;num<=k+1;num++)
                    for(int dx=1;dx<=k;dx++)
                        if(dp.count(num-dx)||dp.count(num+dx)) ndp.insert(num);
            }
            else if(s[pos]=='-')
            {
                for(int num=-(k+1);num<=-1;num++)
                    for(int dx=1;dx<=k;dx++)
                        if(dp.count(num-dx)||dp.count(num+dx)) ndp.insert(num);
            }
            else
            {
                for(int dx=1;dx<=k;dx++)
                    if(dp.count(-dx)||dp.count(dx)) ndp.insert(0);
            }

            if(ndp.empty()) return false;
            dp=ndp;
        }

        return true;
    };

    for(int k=1;k<=3;k++)
        if(check(k))
        {
            cout<<k<<endl;
            break;
        }
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