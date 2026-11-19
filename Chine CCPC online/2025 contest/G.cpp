#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,MOD=1e9+7,LEN=5e5;

struct discrete
{
    private:
        vector<int>num;
    public:
        void add(int n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int size() { return num.size(); }
};

struct Query
{
    int x,y,id;
}op[MAX];

struct qwq
{
    int y,id;
    bool swapped;
};

int n,q;
int a[MAX];
LL ans[MAX];

void solve()
{
    cin>>n>>q;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dis.add(a[i]);
    }

    for(int i=1;i<=q;i++)
    {
        cin>>op[i].x>>op[i].y;
        op[i].id=i;
        dis.add(op[i].x),dis.add(op[i].y);
    }

    dis.create();
    int m=dis.size(),B=sqrt(n);
    vector<int>cnt(m+1,0);
    for(int i=1;i<=n;i++)
    {
        a[i]=dis.find(a[i]);
        ++cnt[a[i]];
    }

    for(int i=1;i<=q;i++)
    {
        op[i].x=dis.find(op[i].x);
        op[i].y=dis.find(op[i].y);
    }

    vector<vector<qwq>>big(m+1);
    vector<vector<int>>pos(m+1);
    vector<Query>small;
    for(int i=1;i<=q;i++)
    {
        if(cnt[op[i].x]>B) big[op[i].x].push_back({op[i].y,op[i].id,false});
        else if(cnt[op[i].y]>B) big[op[i].y].push_back({op[i].x,op[i].id,true});
        else
        {
            if(op[i].x!=op[i].y) small.push_back(op[i]);
            else
            {
                LL now=cnt[op[i].x];
                ans[op[i].id]=1LL*now*(now-1)/2;
            }
        }
    }

    for(int i=1;i<=n;i++)
        if(cnt[a[i]]<=B) pos[a[i]].push_back(i);

    vector<LL>pre(m+1,0);
    for(int x=1;x<=m;++x)
    {
        if(big[x].empty()) continue;

        LL total=0;
        fill(pre.begin(),pre.end(),0);
        for(int i=1;i<=n;i++)
        {
            pre[a[i]]+=total;
            if(x==a[i]) ++total;
        }

        for(auto &[y,id,swapped]:big[x])
        {
            if(swapped)
            {
                LL now=1LL*cnt[x]*cnt[y]-pre[y];
                ans[id]=now;
            }
            else ans[id]=pre[y];
        }
    }

    for(auto &[x,y,id]:small)
    {
        vector<int> &a=pos[x],&b=pos[y];

        int lena=a.size(),lenb=b.size();
        for(int i=0,j=0;i<lena;i++)
        {
            while(j<lenb&&b[j]<=a[i]) ++j;
            ans[id]+=1LL*lenb-j;
        }
    }

    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    
    solve();

    return 0;
}