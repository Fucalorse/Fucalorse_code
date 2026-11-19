#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,q;
int a[MAX];

void solve()
{
    cin>>n;

    map<int,int>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    vector<int>st;
    for(int i=0;i<n;i++)
        if(!cnt.count(i)) st.push_back(i);

    cin>>q;

    int ans=0;
    map<int,int>memo;

    while(q--)
    {
        int k;
        cin>>k;

        auto it=memo.find(k);
        if(it!=memo.end())
        {
            ans^=it->second;
            continue;
        }

        int now=n,lim=n;

        for(const auto &x:st)
        {
            if(x>lim) break;
            if(k%2==0&&(x==k/2))
            {
                now=x;
                break;
            }

            if(x<=k/2)
            {
                auto it=cnt.find(k-x);

                if(it==cnt.end())
                {
                    now=x;
                    break;
                }

                if(it->second==1) lim=k-x;
            }
            else if(x>k/2)
            {
                auto it=cnt.find(k-x);

                if(it==cnt.end())
                {
                    now=x;
                    break;
                }

                if(it->second==1)
                {
                    now=x;
                    break;
                }
            }
        }

        ans^=min(now,lim);
        memo[k]=min(now,lim);
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