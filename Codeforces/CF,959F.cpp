#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,MOD=1e9+7,INF=2e9;

LL cal(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }

    return ans;
}

struct qwq
{
    int l,x,id;
    bool operator<(const qwq &a)const { return l<a.l; }
}op[MAX];

int n,q;
int a[MAX],f[LEN+3];
LL ans[MAX];

void clear()
{
    for(int i=0;i<=LEN;i++)
        f[i]=0;
}

bool update(int x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                return true;
            }

            x^=f[i];
        }

    return false;
}

bool check(int x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i]) return true;

            x^=f[i];
        }

    return false;
}

void solve()
{
    cin>>n>>q;clear();

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=q;i++)
    {
        cin>>op[i].l>>op[i].x;
        op[i].id=i;
    }

    sort(op+1,op+q+1);

    int r=0;
    for(int i=1,pos=1;i<=q;i++)
    {
        auto &[l,x,id]=op[i];
        while(pos<=l)
        {
            if(update(a[pos])) r++;
            pos++;
        }
        
        if(check(x)) ans[id]=0;
        else ans[id]=cal(2LL,l-r);
    }

    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}