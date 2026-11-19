#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    LL val;
    int pos;
    bool operator<(const qwq &a)const
    {
        if(val!=a.val) return val<a.val;
        return pos<a.pos;
    }
}op[MAX];

int n;
int t[MAX];
bool is_left[MAX],is_right[MAX];
LL a[MAX],ans[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>t[i];

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[t[i]]) is_right[i]=true;
        else is_left[i]=true;
    }

    set<qwq>st;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        bool ok=(is_left[i]&&is_right[t[i]])||(is_right[i]&&is_left[t[i]]);
        if(ok)
        {
            LL val=llabs(a[i]-a[t[i]]);
            op[i]={val,i};
            st.insert({val,i});
        }

        adj[t[i]].push_back(i);
    }

    auto bfs=[&](qwq minn)
    {
        queue<int>q;
        ans[minn.pos]=minn.val,vis[minn.pos]=true;
        q.push(minn.pos);

        while(q.size())
        {
            auto pos=q.front();q.pop();
            st.erase(op[pos]);

            for(auto &to:adj[pos])
            {
                LL cost_middle=llabs(a[pos]-a[to]);
                if((is_left[pos]&&is_left[to])||(is_right[pos]&&is_right[to]))
                {
                    LL now=2*cost_middle+ans[pos];
                    // cout<<to<<' '<<llabs(a[pos]-a[to])<<' '<<ans[pos]<<endl;
                    ans[to]=now;
                }
                else
                {
                    if(ans[pos]>=cost_middle) ans[to]=cost_middle;
                    else ans[to]=2*cost_middle-ans[pos];
                }
                
                if(!vis[to])
                {
                    q.push(to);
                    vis[to]=true;
                }
            }
        }
    };

    while(st.size()) bfs(*st.begin());

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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