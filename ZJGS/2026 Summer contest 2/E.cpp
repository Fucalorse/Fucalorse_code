#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090,LEN=1e7,MOD=998244353,INF=2e9;

int n;
int a[MAX],rev[MAX];

void solve()
{
    cin>>n;

    int m=n<<1;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        rev[a[i]]=i;
    }

    vector<bool>vis(m+2,false);
    vector<pair<int,int>>op;
    vis[m+1]=vis[0]=true;

    while(1)
    {
        int st=-1;
        for(int num=m;num>=1;num--)
            if(!vis[num])
            {
                st=rev[num];
                break;
            }

        if(st==-1) break;

        for(int i=st;i<=m;i++)
        {
            vis[a[i]]=true;
            if(vis[a[i+1]])
            {
                op.push_back({st,i});
                break;
            }
        }
    }

    reverse(op.begin(),op.end());

    // for(auto &[l,r]:op)
    //     for(int i=l;i<=r;i++)
    //         cout<<a[i]<<' ';
    // cout<<endl;

    // for(auto &[l,r]:op)
    //     cout<<l<<' '<<r<<endl;

    int len=op.size();
    vector<bool>dp(n+1,false),update(n+1,false);
    vector<int>pre(n+1,0),pos(n+1,0);
    dp[0]=true;

    for(int i=0;i<len;i++)
    {
        int cost=op[i].second-op[i].first+1;
        for(int j=n;j>=cost;j--)
            if(dp[j-cost])
            {
                dp[j]=true;

                if(!update[j])
                {
                    pre[j]=j-cost;
                    pos[j]=i;
                    update[j]=true;
                }
            }
    }

    // for(int i=1;i<=n;i++)
    //     cout<<i<<":"<<pos[i]<<endl;
    // cout<<endl;

    // for(int i=1;i<=n;i++)
    //     cout<<i<<"::"<<pre[i]<<endl;

    if(!dp[n]) cout<<-1<<endl;
    else
    {
        vector<int>first,second;
        vector<bool>vis_id(len+1,false);

        for(int i=n;i;i=pre[i])
        {
            first.push_back(pos[i]);
            vis_id[pos[i]]=true;
        }

        reverse(first.begin(),first.end());

        // for(auto &cur:first)
        // {
        //     cout<<op[cur].first<<' '<<op[cur].second<<endl;
        //     // cout<<cur<<' ';
        // }
        // cout<<endl;

        for(int i=0;i<len;i++)
            if(!vis_id[i]) second.push_back(i);

        auto print=[&](const vector<int>& now)
        {
            bool first=true;

            for(auto &id:now)
            {
                auto [l,r]=op[id];
                for(int i=l;i<=r;i++)
                {
                    if(first)
                    {
                        cout<<a[i];
                        first=false;
                    }
                    else cout<<' '<<a[i];
                }
            }
            cout<<endl;
        };

        print(first);
        print(second);
    }
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