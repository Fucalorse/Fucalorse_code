#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=12,G=3,MOD=998244353,INF=2e9;

struct peach
{
    private:
        vector<int>fa;
    public:
        peach(int _n)
        {
            fa.assign(_n+1,0);
            for(int i=1;i<=_n;i++)
                fa[i]=i;
        }

        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }

        bool merge(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py) return false;
            fa[px]=py;
            return true;
        }
};

int n,q;

void dfs(int mask,const int &u,const int &v,vector<peach>& fu)
{
    if(!fu[mask].merge(u,v)) return;

    for(int x=mask;x;x-=x&-x)
    {
        int bit=x&-x;
        dfs(mask^bit,u,v,fu);
    }
}

void solve()
{
    cin>>n>>q;

    LL ans=0;
    vector<peach>fu(1<<LEN,peach(n));

    while(q--)
    {
        char opt;
        cin>>opt;

        if(opt=='+')
        {
            int u,v,val;
            cin>>u>>v>>val;

            dfs(val,u,v,fu);
        }
        else
        {
            int u,v;
            cin>>u>>v;

            if(fu[0].find(u)!=fu[0].find(v))
            {
                --ans;
                continue;
            }

            int mask=0;
            for(int k=LEN-1;k>=0;k--)
            {
                int now=mask|(1<<k);
                if(fu[now].find(u)==fu[now].find(v)) mask=now;
            }

            ans+=mask;
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