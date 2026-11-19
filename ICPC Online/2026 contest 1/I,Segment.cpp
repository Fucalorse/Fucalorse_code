#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
using ovo = pair<LL,LL>;
const int MAX=2e5+10,LEN=26,G=3,MOD=998244353,INF=2e9;

namespace fucalorse
{
    ovo operator+(const ovo &a,const ovo &b) { return {a.first+b.first,a.second+b.second}; }

    void operator+=(ovo &a,const ovo &b)
    {
        a.first+=b.first;
        a.second+=b.second;
    }

    ovo operator-(const ovo &a,const ovo &b) { return {a.first-b.first,a.second-b.second}; }

    void operator-=(ovo &a,const ovo &b)
    {
        a.first-=b.first;
        a.second-=b.second;
    }
}

using namespace fucalorse;

struct Segment
{
    private:
        struct qwq
        {
            LL cnt,sum;
            int l,r;
        };

        int tot,n;
        vector<int>root;
        vector<qwq>op;

        int dfs(int pre,int l,int r,const int &x,const LL &_cnt,const LL &_sum)
        {
            int cur=++tot;

            op[cur]=op[pre];
            op[cur].cnt+=_cnt;
            op[cur].sum+=_sum;

            if(l==r) return cur;

            int mid=(l+r)>>1;
            if(x<=mid) op[cur].l=dfs(op[pre].l,l,mid,x,_cnt,_sum);
            else op[cur].r=dfs(op[pre].r,mid+1,r,x,_cnt,_sum);

            return cur;
        }

        ovo query(int pre,int cur,int l,int r,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {0,0};
            if(st<=l&&r<=ed) return ovo{op[cur].cnt,op[cur].sum}-ovo{op[pre].cnt,op[pre].sum};

            int mid=(l+r)>>1;
            return query(op[pre].l,op[cur].l,l,mid,st,ed)+
            query(op[pre].r,op[cur].r,mid+1,r,st,ed);
        }
    public:
        void initial(int _n,int _version)
        {
            n=_n,tot=0;
            
            int depth=0;
            while((1<<depth)<n) ++depth;

            op.assign((_version+10)*(depth+1)+1,qwq{});
            root.assign(_version+1,0);

            root[0]=0;
            op[0]={0,0,0,0};
        }

        void update(int pos,int x,LL _cnt,LL _sum) { root[pos]=dfs(root[pos-1],1,n,x,_cnt,_sum); }

        ovo get(int pre,int cur,int st,int ed) { return query(root[pre],root[cur],1,n,st,ed); }
};

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

        int tot,timer;
        vector<qwq>op;
        vector<vector<int>>node;
        vector<vector<int>>adj;
        vector<int>tin,tout;
        Segment fu;
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

        void update_to_segment(const string &s)
        {
            int now=0;
            fu.initial(timer,(int)s.size());

            for(int i=0;i<(int)s.size();i++)
            {
                int p=s[i]-'a';
                now=op[now].nxt[p];
                fu.update(i+1,tin[now],1LL,i+1);
            }
        }

        bool check(int id,int x,const LL &target)
        {
            i128 ans=0;
            for(auto &cur:node[id])
            {
                auto [cnt,sum]=fu.get(0,x,tin[cur],tout[cur]);
                i128 now=(i128)cnt*(x+1)-sum;
                ans+=now;

                if(ans>=target) return true;
            }
            return ans>=target;
        }
};

//first -> cnt
//second -> sum

int q;
string t;
int a[MAX],ans[MAX];
LL b[MAX];

void dfs(vector<int>op,int l,int r,AC &fu)
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

    for(auto &id:op)
    {
        if(fu.check(id,mid,b[id])) left_node.push_back(id);
        else right_node.push_back(id);
    }

    dfs(move(left_node),l,mid,fu);
    dfs(move(right_node),mid+1,r,fu);
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
    fu.update_to_segment(t);

    vector<int>op;
    for(int i=1;i<=q;i++)
        op.push_back(i);

    dfs(op,1,(int)t.size()+1,fu);

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