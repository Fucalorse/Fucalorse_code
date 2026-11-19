#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

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

        void combine(int x,int y) { fa[x]=y; }
};

struct qwq
{
    int l,r;
    bool operator<(const qwq &a)const { return r<a.r; }
}op[MAX];

int T,n,m;

void solve()
{
    cin>>m>>n;

    for(int i=1;i<=m;i++)
        cin>>op[i].l>>op[i].r;
    
    sort(op+1,op+m+1);

    // for(int i=1;i<=m;i++)
    //     cout<<op[i].l<<' '<<op[i].r<<endl;
    // cout<<endl;

    int tot=0,total=n;
    peach fu(2*m);
    unordered_map<int,int>f,ref;

    auto update=[&](int x)
    {
        if(!f.count(x))
        {
            f[x]=++tot;
            ref[tot]=x;
        }
    };

    for(int i=1;i<=m;i++)
    {
        auto [l,r]=op[i];
        if(l==r) continue;

        update(l),update(l+1);

        int pl=fu.find(f[l]),pr=fu.find(f[l+1]);
        if(pl==pr)
        {
            int pos=ref[pl];
            if(pos<r)
            {
                update(pos),update(pos+1);
                int now_l=fu.find(f[pos]),now_r=fu.find(f[pos+1]);
                fu.combine(now_l,now_r);
                --total;
            }
        }
        else
        {
            fu.combine(pl,pr);
            --total;
        }
        // cout<<total<<endl;
    }

    cout<<total<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}