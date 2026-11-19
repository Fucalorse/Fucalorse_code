#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct fucalorse
{
    private:
        int n;
        vector<LL>op;
        vector<int>col;

        void modify(int id,int x)
        {
            if(x+1<=n&&col[x]!=col[x+1]) op[id]=1LL*x*(n-x);
            else op[id]=0;
        }

        void create(int l,int r,int id)
        {
            if(l==r)
            {
                modify(id,l);
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);

            op[id]=op[hl]+op[hr];
        }

        void dfs(int l,int r,int id,const int &x)
        {
            if(l==r)
            {
                modify(id,x);
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x);
            else dfs(mid+1,r,hr,x);

            op[id]=op[hl]+op[hr];
        }
    public:
        fucalorse(int _n,const string &s)
        {
            n=_n;
            op.assign((n+90)<<2,0LL);
            col.assign(n+3,0);

            for(int i=1;i<=n;i++)
                col[i]=s[i]-'0';
            create(1,n,1);
        }

        void update(int x)
        {
            col[x]^=1;
            dfs(1,n,1,x);
            if(x-1>=1) dfs(1,n,1,x-1);
        }

        LL debut() { return op[1]; }
};

int n,q;
string s;

void solve()
{
    cin>>n>>q>>s;s=' '+s;

    LL c0=0,c1=0;
    fucalorse fu(n,s);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') ++c0;
        else ++c1;
    }

    auto cal=[&]()
    {
        LL con1=fu.debut(),con2=c0*c1;
        // cout<<"["<<con1<<' '<<con2<<"]"<<endl;
        return (con1+con2)>>1;
    };

    cout<<cal()<<' ';
    while(q--)
    {
        int pos;
        cin>>pos;

        fu.update(pos);
        if(s[pos]=='0')
        {
            s[pos]='1';
            --c0;
            ++c1;
        }
        else
        {
            s[pos]='0';
            --c1;
            ++c0;
        }

        cout<<cal()<<' ';
    }

    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}