#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=2e5+90;

struct peach
{
    private:
        int fa[MAX];
        bool vis[MAX];
    public:
        peach(int n)
        {
            for(int i=0;i<=n+1;i++)
                fa[i]=i,vis[i]=false;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void add(int x) { vis[x]=true; }
        bool is_pressed(int x) { return vis[find(x)]; }
        void combine(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py) return;
            fa[px]=py;
            if(vis[px]||vis[py]) vis[px]=vis[py]=true;
        }
};

struct qwq
{
    int id,val;
    bool operator<(const qwq &a)const { return val>a.val; }
}op[MAX];

int t,n;
int a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int cnt=0;
        for(int l=1,r=1;l<=n;l=r)
        {
            while(r<=n&&a[l]==a[r]) r++;
            ++cnt;
            op[cnt]={cnt,a[l]};
        }
        peach fu(cnt);
        sort(op+1,op+cnt+1);
        int ans=0;
        for(int i=1;i<=cnt;i++)
        {
            int x=op[i].id;
            bool left=fu.is_pressed(x-1),right=fu.is_pressed(x+1);
            if(left||right)
            {
                if(left) fu.combine(x-1,x);
                if(right) fu.combine(x,x+1);
            }
            else fu.add(x),++ans;
            // cout<<x<<' '<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}