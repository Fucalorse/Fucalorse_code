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
            fa.assign(n+5,0);
            for(int i=0;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
};

struct ovo
{
    int u,v;
}a[MAX],b[MAX];

int t,n,m1,m2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m1>>m2;
        peach f(n),g(n);
        for(int i=1;i<=m1;i++)
            cin>>a[i].u>>a[i].v;
        int cf=n,cg=n,cnt=0;
        for(int i=1;i<=m2;i++)
        {
            cin>>b[i].u>>b[i].v;
            int x=g.find(b[i].u),y=g.find(b[i].v);
            if(x!=y)
            {
                g.combine(x,y);
                --cg;
            }
        }
        for(int i=1;i<=m1;i++)
        {
            int x=g.find(a[i].u),y=g.find(a[i].v);
            if(x!=y) ++cnt;
            else
            {
                int px=f.find(a[i].u),py=f.find(a[i].v);
                if(px!=py)
                {
                    f.combine(px,py);
                    --cf;
                }
            }
        }
        cout<<cnt+cf-cg<<endl;
    }
    return 0;
}