#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90;

struct peach
{
    private:
        struct qwq
        {
            int maxn,lazy;
        };
        vector<qwq>op;
        int size;

        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                int &k=op[id].lazy;
                op[hl].maxn+=k,op[hl].lazy+=k;
                op[hr].maxn+=k,op[hr].lazy+=k;
                k=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].maxn+=k;
                op[id].lazy+=k;
                return;
            }
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
        }
    public:
        peach(int n) { op.assign((n+10)<<4,{0,0}),size=n; }
        void update(const int &st,const int &ed,const int &k)
        {
            dfs(1,size,1,st,ed,k);
        }
        int get() { return op[1].maxn; }
};

int t,n,k;
int a[MAX],b[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i];
        peach fu(n);
        int ans=0;
        for(int l=1,r=1;r<=n;r++)
        {
            fu.update(a[r],b[r],1);
            while(fu.get()>k&&l<r)
            {
                fu.update(a[l],b[l],-1);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}