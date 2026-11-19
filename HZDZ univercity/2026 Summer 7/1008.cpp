#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
LL w;
string s;

void solve()
{
    cin>>n>>w>>s;s=' '+s;

    int a=0,x=0,o=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='&') ++a;
        else if(s[i]=='^') ++x;
        else ++o;
    }

    vector<LL>ans(n+1,0);
    if(a)
    {
        int l,r;
        for(int i=1;i<n;i++)
            if(s[i]=='&')
            {
                l=r=i;
                while(r<n&&s[r]=='&') ++r;
                break;
            }

        for(int i=l;i<=r;i++)
            ans[i]=w;
    }
    else
    {
        if(x)
        {
            vector<pair<int,int>>op;

            for(int l=1,r=1;l<n;l=r)
            {
                if(s[l]=='|')
                {
                    r++;
                    continue;
                }

                while(r<n&&s[r]=='^') ++r;
                op.push_back({l,r-1});
            }

            for(auto [l,r]:op)
            {
                int st=l,ed=r+1;
                int len=ed-st+1;
                if(len%2==0) --ed;

                for(int i=st;i<=ed;i++)
                    ans[i]=w;
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
                ans[i]=w;
        }
    }

    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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