#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,MOD=1e9+7,LEN=5e5;
const LL INF=1e18;

struct peach
{
    private:
        vector<int>fa;
    public:
        peach(int n)
        {
            fa.assign(n+1,0);
            for(int i=1;i<=n;i++)
                fa[i]=i;
        }

        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }

        void combine(int x,int y) { fa[find(x)]=find(y); }
};

struct qwq
{
    LL val;
    int id;
    bool operator<(const qwq &a)const { return val<a.val; }
}op[MAX];

int T,n;
LL k;
LL a[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=k;
        op[i]={a[i],i};
    }

    sort(op+1,op+n+1);

    vector<int>first(n+3,n+1);
    vector<LL>num(n+1);
    for(int i=1;i<=n;i++)
        num[i]=op[i].val;

    for(int i=1;i<=n;i++)
        first[i]=lower_bound(num.begin()+1,num.end(),k-num[i])-num.begin();

    vector<int>pre(n+3,0),nxt(n+3,0);
    for(int i=0;i<=n+1;i++)
    {
        pre[i]=max(0,i-1);
        nxt[i]=min(i+1,n+1);
    }

    LL ans=0;
    int cnt_comb=n;
    peach fu(n);
    vector<int>head(n+1,0),belong(n+1,0);
    vector<LL>best_w(n+1,0);
    vector<int>best_u(n+1,0),best_v(n+1,0),roots,nxt_comb(n+1);
    while(cnt_comb>1)
    {
        fill(head.begin()+1,head.end(),0);
        roots.clear();

        for(int i=1;i<=n;i++)
        {
            int root=fu.find(i);

            belong[i]=root;
            if(!head[root]) roots.push_back(root);

            nxt_comb[i]=head[root];
            head[root]=i;
        }

        for(auto &root:roots)
        {
            best_w[root]=INF;
            best_u[root]=best_v[root]=0;

            for(int i=head[root];i;i=nxt_comb[i])
            {
                nxt[pre[i]]=nxt[i];
                pre[nxt[i]]=pre[i];
            }

            auto update=[&](int x,int y)
            {
                if(y<1||y>n) return;

                LL now=(op[x].val+op[y].val)%k;

                if(now<best_w[root])
                {
                    best_w[root]=now;
                    best_u[root]=x;
                    best_v[root]=y;
                }
            };

            for(int i=head[root];i;i=nxt_comb[i])
            {
                update(i,nxt[0]);

                int suf=first[i];

                if(suf<=n)
                {
                    if(belong[suf]==root) suf=nxt[suf];

                    update(i,suf);
                }
            }

            for(int i=head[root];i;i=nxt_comb[i])
            {
                nxt[pre[i]]=i;
                pre[nxt[i]]=i;
            }
        }

        for(auto &root:roots)
        {
            if(best_u[root]&&fu.find(best_u[root])!=fu.find(best_v[root]))
            {
                fu.combine(best_u[root],best_v[root]);
                ans+=best_w[root];
                --cnt_comb;
                // printf("12");
            }
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}