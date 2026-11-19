#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=2e5+90,LEN=18,inf=2e9;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int t,n,q;
int a[MAX],b[MAX],g[MAX],nxt[MAX];

template <typename T,typename mergefunc>
struct peach
{
    private:
        vector<vector<T>>f;
        mergefunc cal;
        int size,K;
    public:
        peach(const T *num,const int &n,mergefunc merge):cal(merge)
        {
            size=n,K=log2(n);
            f.assign(size+5,vector<T>(K+3,0));
            for(int i=1;i<=size;i++)
                f[i][0]=num[i];
            for(int k=1;(1<<k)<=size;k++)
            {
                int s=1<<(k-1);
                for(int i=1;i+(1<<k)-1<=size;i++)
                    f[i][k]=cal(f[i][k-1],f[i+s][k-1]);
            }
        }
        T query(const int &st,const int &ed)
        {
            int k=log2(ed-st+1);
            return cal(f[st][k],f[ed-(1<<k)+1][k]);
        }
        int get(const int &x,const int &ed)
        {
            int pos=x;
            for(int k=K;k>=0;k--)
            {
                int aft=pos+(1<<k);
                if(aft<=ed&&query(pos,ed)==query(aft,ed)) pos=aft;
            }
            return pos;
        }
};

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    auto cmp1=[] (int a,int b) { return gcd(a,b); };
    auto cmp2=[] (int a,int b) { return max(a,b); };
    peach<int,decltype(cmp1)>f(a,n,cmp1);
    peach<int,decltype(cmp2)>g(b,n,cmp2);
    while(q--)
    {
        int st,ed,now=0,ans=0;
        cin>>st>>ed;
        for(int l=st,r;l<=ed;l=r+1)
        {
            r=f.get(l,ed);
            // cout<<l<<' '<<r<<endl;
            int dx=f.query(l,ed),maxn=g.query(l,r),cnt=0;
            if(maxn-now>0)
            {
                cnt=(maxn-now-1)/dx+1;
                now+=cnt*dx;
                // cout<<cnt<<' '<<dx<<endl;
            }
            ans+=cnt;
        }
        cout<<ans<<endl;
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}