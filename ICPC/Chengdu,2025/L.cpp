#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct peach
{
    private:
        struct qwq
        {
            int l,r;
            int a,b;
        };
        vector<qwq>op;
        vector<int>root;
        int tot,size;

        void dfs(int &pos,int l,int r,const int &x,const int &k)
        {
            if(!pos) pos=++tot;
            if(l==r)
            {
                if(k<0) op[pos].b++;
                else op[pos].a++;
                int dx=min(op[pos].a,op[pos].b);
                op[pos].a-=dx,op[pos].b-=dx;
                return;
            }
            int mid=(l+r)>>1;
            if(x<=mid) dfs(op[pos].l,l,mid,x,k);
            else dfs(op[pos].r,mid+1,r,x,k);
            op[pos].a=op[op[pos].l].a+op[op[pos].r].a;
            op[pos].b=op[op[pos].l].b+op[op[pos].r].b;
        }
        int cal(int x,int y,int l,int r)
        {
            if(!x||!y) return x|y;
            if(l==r)
            {
                op[x].a+=op[y].a;
                op[x].b+=op[y].b;
                int dx=min(op[x].a,op[x].b);
                op[x].a-=dx,op[x].b-=dx;
                return x;
            }
            int mid=(l+r)>>1;
            op[x].l=cal(op[x].l,op[y].l,l,mid);
            op[x].r=cal(op[x].r,op[y].r,mid+1,r);
            op[x].a=op[op[x].l].a+op[op[x].r].a;
            op[x].b=op[op[x].l].b+op[op[x].r].b;
            return x;
        }
    public:
        peach(int n)
        {
            op.assign(n*45,{0,0,0,0});
            root.assign(n+5,0);
            tot=0;
            size=n;
        }
        void update(int pos,int x,int k) { dfs(root[pos],1,size,x,k); }
        void merge(int x,int y) { root[x]=cal(root[x],root[y],1,size); }
        pair<int,int> get(int pos) { return {op[root[pos]].a,op[root[pos]].b}; }
};

int T,n;
int a[MAX],b[MAX],ca[MAX],cb[MAX];
bool ok[MAX];
vector<int>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        ca[i]=cb[i]=0;
        ok[i]=false;
    }
}

void dfs(int ch,int fa,peach &fu)
{
    ca[ch]=(a[ch]==0),cb[ch]=(b[ch]==0);
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,fu);
        ca[ch]+=ca[to],cb[ch]+=cb[to];
        fu.merge(ch,to);
    }
    auto [numa,numb]=fu.get(ch);
    // cout<<"::"<<ch<<endl;
    // cout<<ca[ch]<<' '<<cb[ch]<<endl;
    // cout<<numa<<' '<<numb<<endl;
    if(cb[ch]>=numa&&ca[ch]>=numb) ok[ch]=true;
    else ok[ch]=false;
}

void solve()
{
    cin>>n;clear();

    peach fu(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]) fu.update(i,a[i],1);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]) fu.update(i,b[i],-1);
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    dfs(1,0,fu);
    for(int i=1;i<=n;i++)
    {
        if(ok[i]) cout<<1;
        else cout<<0;
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}

// g++ L.cpp -O2 -o out.exe && out.exe < in.txt