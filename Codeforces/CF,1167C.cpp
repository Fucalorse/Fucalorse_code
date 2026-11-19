#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=5e5+90;

struct peach
{
    private:
        int fa[MAX];
        int sz[MAX];
    public:
        peach(int n)
        {
            for(int i=0;i<=n;i++)
                fa[i]=i,sz[i]=1;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py) return;
            fa[px]=py;
            sz[py]+=sz[px];
        }
        int get(int x) { return sz[find(x)]; }
}fu(MAX);

int n,m,k;
int a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>a[j];
        for(int j=2;j<=k;j++)
            fu.combine(a[j-1],a[j]);
    }
    for(int i=1;i<=n;i++)
        cout<<fu.get(i)<<' ';
    cout<<endl;
    return 0;
}