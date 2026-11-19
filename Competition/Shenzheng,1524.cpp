#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,mod=998244353;

struct discrete
{
    private:
        vector<LL>num;
    public:
        void add(LL n) { num.push_back(n); }
        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }
        int find(LL n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }
        int size() { return num.size(); }
}fu;

int n;
LL a[MAX],dp[MAX];
vector<int>p[MAX];

struct peach
{
    private:
        struct tree
        {
            int l,r,cnt;
            LL sum;
        }op[MAX<<5];
        int root[MAX],qwq=0;

        void dfs(int &pos,int l,int r,const int &p,const LL &k)
        {
            if(!pos) pos=++qwq;
            op[pos].sum+=k;
            op[pos].cnt++;
            if(l==r) return;
            int mid=(l+r)>>1;
            if(p<=mid) dfs(op[pos].l,l,mid,p,k);
            else dfs(op[pos].r,mid+1,r,p,k);
        }
        int cal(int x,int y,int l,int r,LL &ans)
        {
            if(!x||!y) return x|y;
            if(l==r)
            {
                op[x].cnt+=op[y].cnt;
                op[x].sum+=op[y].sum;
                return x;
            }
            if(op[x].l&&op[y].r)
            {
                ans+=op[op[y].r].sum*op[op[x].l].cnt%mod-op[op[x].l].sum*op[op[y].r].cnt%mod;
                ans=(ans+mod)%mod;
            }
            if(op[x].r&&op[y].l)
            {
                ans+=op[op[x].r].sum*op[op[y].l].cnt%mod-op[op[y].l].sum*op[op[x].r].cnt%mod;
                ans=(ans+mod)%mod;
            }
            int mid=(l+r)>>1;
            op[x].l=cal(op[x].l,op[y].l,l,mid,ans);
            op[x].r=cal(op[x].r,op[y].r,mid+1,r,ans);
            op[x].cnt=op[op[x].l].cnt+op[op[x].r].cnt;
            op[x].sum=op[op[x].l].sum+op[op[x].r].sum;
            return x;
        }
    public:
        void update(int pos,int p,LL k) { dfs(root[pos],1,fu.size(),p,k); }
        LL merge(int x,int y)
        {
            LL ans=0;
            root[x]=cal(root[x],root[y],1,fu.size(),ans);
            return ans%mod;
        }
}fufu;

void dfs(int ch,int fa)
{
    fufu.update(ch,fu.find(a[ch]),a[ch]);
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
        dp[ch]=(dp[ch]+dp[to]+fufu.merge(ch,to))%mod;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fu.add(a[i]);
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.create();
    dfs(1,0);
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int size(64 << 20);  // 64 MB
    __asm__("movq %0, %%rsp\n" :: "r"((char*)malloc(size) + size));
    solve();
    exit(0);
}