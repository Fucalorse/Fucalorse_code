#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=26,MOD=998244353;
const LL INF=1e18;

int n,q;
int rev[MAX],string_len[MAX];
LL a[MAX],f[MAX],g[MAX],pre[MAX],suf[MAX];
string t[MAX],s;

struct peach
{
    private:
        struct qwq
        {
            int nxt[LEN],fail;
            int id;
            qwq()
            {
                fail=id=0;
                memset(nxt,0,sizeof(nxt));
            }
        };

        int tot;
        vector<qwq>op;
        vector<int>fa;
    public:
        peach(int _n)
        {
            tot=0;
            op.assign(_n+5,qwq{});
            fa.assign(_n+5,0);
        }

        void update(const string &s,const int &pos)
        {
            int now=0;

            for(auto &cur:s)
            {
                int p=cur-'a';
                if(!op[now].nxt[p]) op[now].nxt[p]=++tot;
                now=op[now].nxt[p];
            }

            if(!op[now].id) op[now].id=pos;
            rev[pos]=op[now].id;
        }

        void create()
        {
            queue<int>q;
            for(int i=0;i<LEN;i++)
                if(op[0].nxt[i]) q.push(op[0].nxt[i]);

            while(q.size())
            {
                int cur=q.front();q.pop();

                int pre=op[cur].fail;
                if(op[pre].id) fa[cur]=pre;
                else fa[cur]=fa[pre];

                for(int i=0;i<LEN;i++)
                {
                    if(op[cur].nxt[i])
                    {
                        op[op[cur].nxt[i]].fail=op[op[cur].fail].nxt[i];
                        q.push(op[cur].nxt[i]);
                    }
                    else op[cur].nxt[i]=op[op[cur].fail].nxt[i];
                }
            }
        }

        vector<vector<int>> query(const string &s)
        {
            int now=0;
            vector<vector<int>>rest(q+1);

            for(int i=1;i<=q;i++)
                rest[i].push_back(0);

            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                now=op[now].nxt[p];

                for(int cur=now;cur;cur=fa[cur])
                    if(op[cur].id) rest[op[cur].id].push_back(i+1);
            }

            for(int i=1;i<=q;i++)
                rest[i].push_back(n+1);

            return rest;
        }
};

void solve()
{
    cin>>n>>q>>s;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    for(int i=1;i<=q;i++)
        cin>>t[i];

    pre[0]=0,suf[n+1]=-INF;
    for(int i=1;i<=n;i++)
    {
        g[i]=(g[i-1]+f[i])%MOD;
        pre[i]=min(pre[i-1],f[i]);
    }
    for(int i=n;i>=1;i--)
        suf[i]=max(suf[i+1],f[i]);

    peach fu(MAX);
    for(int i=1;i<=q;i++)
    {
        fu.update(t[i],i);
        string_len[i]=(int)t[i].size();
    }
    fu.create();

    vector<vector<int>>rest=fu.query(s);
    vector<LL>sum(q+1,0),maxn(q+1,-INF);
    for(int i=1;i<=q;i++)
    {
        auto &op=rest[i];
        if((int)op.size()==2) continue;

        int len=string_len[i];
        for(int j=1;j<(int)op.size()-1;j++)
        {
            int x=op[j]-len+1,y=op[j],z=op[j+1]-1;
            // cout<<x<<' '<<y<<' '<<z<<endl;

            LL min_pre=pre[x-1],suf_max=suf[y];
            maxn[i]=max(maxn[i],suf_max-min_pre);

            LL now=(g[z]-g[y-1]+MOD)*x%MOD-(z-y+1)*g[x-1]%MOD;
            sum[i]=(sum[i]+now%MOD+MOD)%MOD;
        }
    }

    for(int i=1;i<=q;i++)
        cout<<maxn[rev[i]]<<' '<<sum[rev[i]]<<endl;
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