#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int n) { size=n,op.assign(n+5,0); }
        void update(int n,int k)
        {
            for(int i=n;i<=size;i+=i&-i)
                op[i]^=k;
        }
        int query(int n)
        {
            int ans=0;
            for(int i=n;i;i-=i&-i)
                ans^=op[i];
            return ans;
        }
};

int n,q;
int a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    peach f(n),g(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i&1) f.update(i,a[i]);
        else g.update(i,a[i]);
    }
    while(q--)
    {
        int p;
        cin>>p;
        if(p==1)
        {
            int x,k;
            cin>>x>>k;
            if(x&1) f.update(x,a[x]^k);
            else g.update(x,a[x]^k);
            a[x]=k;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            if((r-l+1)&1)
            {
                int ans;
                if(l&1) ans=f.query(r)^f.query(l-1);
                else ans=g.query(r)^g.query(l-1);
                // cout<<f.query(r)<<' '<<f.query(l-1)<<endl;
                cout<<ans<<endl;
            }
            else cout<<0<<endl;
        }
    }
    return 0;
}