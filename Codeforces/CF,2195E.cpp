#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=19,mod=1e9+7;

int t,n;
int f[MAX][LEN+3];
LL cnt[MAX][LEN+3],path[MAX],ans[MAX];
vector<int>p[MAX];

struct peach
{
    LL dfs(int ch)
    {
        ans[ch]=path[ch]=0;
        for(auto &to:p[ch])
        {
            if(to==f[ch][0]) continue;
            path[ch]+=dfs(to);
        }
        if(p[ch].size()) path[ch]+=3;
        else path[ch]=1;
        path[ch]%=mod;
        return path[ch];
    }
    void find(int pos)
    {
        ans[pos]+=path[pos];
        for(auto &to:p[pos])
        {
            ans[to]+=ans[pos];
            ans[to]%=mod;
            find(to);
        }
        ans[pos]%=mod;
    }
    void debut()
    {
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
};

void initial()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        initial();
        for(int i=1;i<=n;i++)
        {
            int l,r;
            cin>>l>>r;
            if(l&&r) p[i].push_back(l),p[i].push_back(r);
        }
        peach fu;
        fu.dfs(1);
        fu.find(1);
        // for(int i=1;i<=n;i++)
        //     cout<<path[i]<<' ';
        // cout<<endl;
        fu.debut();
    }
    return 0;
}