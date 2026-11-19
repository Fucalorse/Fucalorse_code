#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,G=3,MOD=998244353,INF=2e9;

struct Trie
{
    private:
        struct qwq
        {
            int nxt[2];
            int cnt;
            qwq()
            {
                nxt[0]=nxt[1]=0;
                cnt=0;
            }
        };

        vector<qwq>op;
    public:
        Trie() { op.emplace_back(); }

        void update(int x)
        {
            int now=0;
            for(int i=LEN;i>=0;i--)
            {
                int p=(x>>i)&1;
                if(!op[now].nxt[p])
                {
                    op.emplace_back();
                    op[now].nxt[p]=(int)op.size()-1;
                }
                now=op[now].nxt[p];
                ++op[now].cnt;
            }
        }

        int query(int x,int k)
        {
            int now=0,ans=0;
            for(int i=LEN;i>=0;i--)
            {
                int p=(x>>i)&1;
                int cnt=op[op[now].nxt[p]].cnt;
                if(k<=cnt) now=op[now].nxt[p];
                else
                {
                    k-=cnt;
                    now=op[now].nxt[p^1];
                    ans|=1<<i;
                }
            }
            return ans;
        }
};

struct qwq
{
    int pos,val,rank;
    bool operator<(const qwq &a)const
    {
        if(val!=a.val) return val>a.val;
        return pos>a.pos;
    }
};

int n,q;

void solve()
{
    cin>>n>>q;

    vector<int>a(n),ans(61,0);
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a.begin(),a.end());
    ans[0]=a.back()-a.front();

    for(int round=1;round<=60;round++)
    {
        Trie fu;
        vector<int>op;
        priority_queue<qwq>q;

        for(int i=0;i<n;i++)
            fu.update(a[i]);
        
        for(int i=0;i<n;i++)
            q.push({i,fu.query(a[i],2),2});

        for(int t=1;t<=2*n;t++)
        {
            auto [pos,val,rank]=q.top();q.pop();

            if(t&1) op.push_back(val);

            if(rank<n) q.push({pos,fu.query(a[pos],rank+1),rank+1});
        }

        sort(op.begin(),op.end());
        ans[round]=op.back()-op.front();
        a=op;
        if(ans[round]==0) break;
    }

    while(q--)
    {
        int x;
        cin>>x;

        if(x>60) cout<<0<<endl;
        else cout<<ans[x]<<endl;
    }
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