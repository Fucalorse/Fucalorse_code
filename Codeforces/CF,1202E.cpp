#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=26,MOD=1e9+7,INF=2e9;

struct peach
{
    private:
        struct qwq
        {
            int nxt[LEN],fail;
            LL sum;
            qwq()
            {
                memset(nxt,0,sizeof(nxt));
                fail=0;
                sum=0;
            }
        };

        int tot;
        vector<qwq>op;
    public:
        peach()
        {
            tot=0;
            op.assign(MAX,qwq{});
        }

        void update(const string &s)
        {
            int now=0;

            for(auto &cur:s)
            {
                int p=cur-'a';
                if(!op[now].nxt[p]) op[now].nxt[p]=++tot;
                now=op[now].nxt[p];
            }

            ++op[now].sum;
        }

        void create()
        {
            queue<int>q;
            for(int i=0;i<LEN;i++)
                if(op[0].nxt[i]) q.push(op[0].nxt[i]);

            while(q.size())
            {
                int cur=q.front();q.pop();
                op[cur].sum+=op[op[cur].fail].sum;

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
            // for(int i=1;i<=tot;i++)
            //     cout<<op[i].sum<<' ';
            // cout<<endl<<endl;
        }

        vector<LL> fucalorse(const string &s)
        {
            vector<LL>f(s.size()+1,0LL);

            int now=0;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                now=op[now].nxt[p];
                f[i+1]+=op[now].sum;
            }

            return f;
        }
};

int n;
string t,s[MAX];

void solve()
{
    cin>>t>>n;
    
    peach pre_fu,suf_fu;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        pre_fu.update(s[i]);
        reverse(s[i].begin(),s[i].end());
        suf_fu.update(s[i]);
    }

    pre_fu.create();
    suf_fu.create();
    vector<LL>pre=pre_fu.fucalorse(t);
    reverse(t.begin(),t.end());
    vector<LL>suf=suf_fu.fucalorse(t);

    // for(int i=1;i<=(int)t.size();i++)
    //     cout<<pre[i]<<' ';
    // cout<<endl;
    // for(int i=1;i<=(int)t.size();i++)
    //     cout<<suf[i]<<' ';
    // cout<<endl;

    int m=t.size();
    LL ans=0;
    for(int i=1;i<m;i++)
    {
        LL now=pre[i]*suf[m-i];
        ans+=now;
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