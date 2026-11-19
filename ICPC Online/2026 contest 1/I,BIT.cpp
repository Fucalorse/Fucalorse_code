#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e5+10,LEN=26,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    LL cnt,sum;

    qwq operator+(const qwq &a)const { return {cnt+a.cnt,sum+a.sum}; }

    void operator+=(const qwq &b)
    {
        this->cnt+=b.cnt;
        this->sum+=b.sum;
    }

    qwq operator-(const qwq &a)const { return {cnt-a.cnt,sum-a.sum}; }

    void operator-=(const qwq &b)
    {
        this->cnt-=b.cnt;
        this->sum-=b.sum;
    }
};

struct peach
{
    private:
        int n;
        vector<qwq>op;
    public:
        peach(int _n) { n=_n,op.assign(n+3,qwq{}); }

        void update(int pos,LL _cnt,LL _sum)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]+=qwq{_cnt,_sum};
        }

        qwq query(int pos)
        {
            qwq ans={0,0};
            for(int i=pos;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }

        qwq query_range(int l,int r) { return query(r)-query(l-1); }
}bit(MAX);

struct Position
{
    int pos;
    LL cnt,sum;   
}num[MAX];

int tot,timer;
vector<vector<int>>node;
vector<vector<int>>adj;
vector<int>tin,tout;

struct AC
{
    private:
        struct qwq
        {
            int nxt[LEN],fail;
            qwq()
            {
                memset(nxt,0,sizeof(nxt));
                fail=0;
            }
        };

        vector<qwq>op;
    public:
        AC(int _n,int _q)
        {
            tot=timer=0;
            op.assign((_n+10),qwq{});
            node.assign(_q+1,vector<int>{});
        }

        void update(const string &s,const int &query_id)
        {
            int now=0;
            for(auto &cur:s)
            {
                int p=cur-'a';
                if(!op[now].nxt[p]) op[now].nxt[p]=++tot;
                now=op[now].nxt[p];
                node[query_id].push_back(now);
            }
        }

        void dfs(int ch,int fa)
        {
            tin[ch]=++timer;
            
            for(auto &to:adj[ch])
            {
                if(to==fa) continue;
                dfs(to,ch);
            }

            tout[ch]=timer;
        }

        void create()
        {
            queue<int>q;
            adj.assign(tot+1,vector<int>{});
            tin.assign(tot+1,0);
            tout.assign(tot+1,0);

            for(int i=0;i<LEN;i++)
                if(op[0].nxt[i])
                {
                    q.push(op[0].nxt[i]);
                    adj[0].push_back(op[0].nxt[i]);
                }

            while(q.size())
            {
                int cur=q.front();q.pop();

                for(int i=0;i<LEN;i++)
                {
                    if(op[cur].nxt[i])
                    {
                        op[op[cur].nxt[i]].fail=op[op[cur].fail].nxt[i];
                        adj[op[op[cur].nxt[i]].fail].push_back(op[cur].nxt[i]);
                        q.push(op[cur].nxt[i]);
                    }
                    else op[cur].nxt[i]=op[op[cur].fail].nxt[i];
                }
            }

            dfs(0,-1);
        }

        void query(const string &s)
        {
            int now=0;

            for(int i=0;i<(int)s.size();i++)
            {
                int p=s[i]-'a';
                now=op[now].nxt[p];
                num[i+1]={tin[now],1LL,i+1};
            }
        }
};

int q,P=0;
string t;
int a[MAX],ans[MAX];
LL b[MAX];

bool check(int id,int x,const LL &target)
{
    i128 ans=0;
    for(auto &cur:node[id])
    {
        auto [cnt,sum]=bit.query_range(tin[cur],tout[cur]);
        i128 now=(i128)(x+1)*cnt-sum;
        ans+=now;
        if(ans>=target) return true;
    }
    return ans>=target;
}

void dfs(int l,int r,vector<int>op)
{
    if(op.empty()) return;

    if(l>=r)
    {
        for(auto &cur:op)
            ans[cur]=l>(int)t.size()?-1:l;
        return;
    }

    int mid=(l+r)>>1;
    vector<int>left_node,right_node;

    while(P<mid)
    {
        ++P;
        const auto &[pos,cnt,sum]=num[P];
        bit.update(pos,cnt,sum);
    }

    while(P>mid)
    {
        const auto &[pos,cnt,sum]=num[P];
        bit.update(pos,-cnt,-sum);
        --P;
    }

    for(auto &cur:op)
    {
        if(check(cur,mid,b[cur])) left_node.push_back(cur);
        else right_node.push_back(cur);
    }

    dfs(l,mid,move(left_node));
    dfs(mid+1,r,move(right_node));
}

void solve()
{
    cin>>t>>q;

    AC fu(MAX,q);
    for(int i=1;i<=q;i++)
    {
        cin>>a[i]>>b[i];
        
        for(int j=1;j<=a[i];j++)
        {
            string s;
            cin>>s;
            fu.update(s,i);
        }
    }

    fu.create();
    fu.query(t);

    vector<int>op;
    for(int i=1;i<=q;i++)
        op.push_back(i);
        
    dfs(1,(int)t.size()+1,op);

    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
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