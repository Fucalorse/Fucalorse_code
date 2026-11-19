#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,timer,m;
int vis[MAX];

int ask(const vector<int>& op)
{
    int len=m-op.size();
    cout<<"? "<<len<<' ';

    ++timer;
    for(auto &cur:op)
        vis[cur]=timer;
    for(int i=1;i<=m;i++)
        if(vis[i]!=timer) cout<<i<<' ';
    cout<<endl<<flush;

    int cnt;
    cin>>cnt;
    return len-cnt;
}

pair<vector<int>,vector<int>> split(const vector<int>& op)
{
    int len=(int)op.size(),mid=len>>1;
    vector<int>left,right;

    for(int i=0;i<mid;i++)
        left.push_back(op[i]);

    for(int i=mid;i<len;i++)
        right.push_back(op[i]);

    return {move(left),move(right)};
}

void print(const vector<int>& op)
{
    for(auto &cur:op)
        cout<<cur<<' ';
    cout<<endl;
}

void solve()
{
    cin>>n;

    m=n<<1|1;
    vector<int>ans;

    auto dfs=[&](auto &&self,vector<int>op)->void
    {
        if((int)op.size()==1)
        {
            ans.push_back(op.front());
            return;
        }

        auto [left,right]=split(op);
        int col=ask(left);
        if(col%2==0) self(self,left);
        else self(self,right);
    };

    for(int round=1;round<=3;++round)
    {
        vector<int>pos;
        for(int i=1;i<=m;i++)
        {
            bool ok=true;
            for(auto &cur:ans)
                if(i==cur)
                {
                    ok=false;
                    break;
                }

            if(ok) pos.push_back(i);
        }

        dfs(dfs,pos);
    }

    cout<<"! "<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl<<flush;
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