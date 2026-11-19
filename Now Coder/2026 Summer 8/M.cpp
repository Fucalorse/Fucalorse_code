#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=26,MOD=998244353,INF=2e9;

struct tree
{
    int nxt[LEN],fa;
    vector<int>aft;
    tree()
    {
        memset(nxt,0,sizeof(nxt));
        fa=0;
    }
}op[MAX];

int n,m;
string s[MAX];

void solve()
{
    cin>>n>>m;

    int tot=0;
    auto update=[&](const string &s,const int &pos)
    {
        int now=0;

        for(auto &cur:s)
        {
            int p=cur-'a';
            if(!op[now].nxt[p]) op[now].nxt[p]=++tot;

            op[op[now].nxt[p]].fa=now;
            now=op[now].nxt[p];
            op[now].aft.push_back(pos);
        }
    };

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        update(s[i],i);
    }

    LL ans=0,use=0;
    priority_queue<pair<int,int>>q;
    vector<bool>vis(tot+1,false);
    vector<int>fail(tot+1,0),nxt(tot+1,0);

    auto add=[&](int pos)
    {
        ++fail[pos];
        if(fail[pos]>=(int)op[pos].aft.size()) nxt[pos]=INF;
        else nxt[pos]=op[pos].aft[fail[pos]];
    };

    for(int i=1;i<=n;i++)
    {
        int now=0;

        for(auto &cur:s[i])
        {
            int p=cur-'a';
            now=op[now].nxt[p];
            
            if(!vis[now])
            {
                vis[now]=true;
                ++ans;
                ++use;
            }
            add(now);
        }

        q.push({nxt[now],now});

        while(q.size()&&use>m)
        {
            auto [timer,now]=q.top();q.pop();
            if(!vis[now]) continue;

            bool ok=true;
            for(int i=0;i<26;i++)
                if(op[now].nxt[i]&&vis[op[now].nxt[i]])
                {
                    ok=false;
                    break;
                }

            if(!ok) continue;

            vis[now]=false;
            --use;
            int fa=op[now].fa;
            if(fa) q.push({nxt[fa],fa});
        }
    }

    cout<<ans<<endl;
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