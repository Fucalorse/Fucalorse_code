#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

struct qwq
{
    int V,l,r;
    bool operator<(const qwq &a)const { return l<a.l; }
};

int T,n;
bool ok;
int fa[MAX],a[MAX],maxn[MAX],minn[MAX];

void dfs(int ch,int fa,vector<vector<int>>& p)
{
    maxn[ch]=-INF,minn[ch]=INF;
    if(p[ch].empty()) maxn[ch]=minn[ch]=a[ch];

    vector<qwq>op;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,p);

        op.push_back({to,minn[to],maxn[to]});

        maxn[ch]=max(maxn[ch],maxn[to]);
        minn[ch]=min(minn[ch],minn[to]);
    }

    if(!ok) return;

    sort(op.begin(),op.end());
    for(size_t i=1;i<op.size();i++)
        if(op[i-1].r+1!=op[i].l)
        {
            ok=false;
            break;
        }

    size_t pos=op.size();
    int cnt=0;
    for(size_t i=1;i<op.size();i++)
        if(op[i-1].V>op[i].V)
        {
            pos=i-1;
            ++cnt;
        }

    if(pos==op.size()) return;
    if(op.front().V<op.back().V||cnt>1) ok=false;
}

void solve()
{
    cin>>n;

    vector<vector<int>>p(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>fa[i];
        p[fa[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)
        cin>>a[i];

    ok=true;
    dfs(1,0,p);

    cout<<(ok?"YES":"NO")<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}