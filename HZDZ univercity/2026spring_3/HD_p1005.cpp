#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int LEN=38;

int t,n,q;
LL f[LEN+5],g[LEN+5];

void create()
{
    g[0]=1;
    for(int i=1;i<=LEN;i++)
        g[i]=g[i-1]*3;
}

LL cal(LL a,LL b)
{
    LL ans=0;
    int i=0;
    while(a&&b)
    {
        int now=(a%3+b%3)%3;
        if(now) ans+=g[i]*now;
        if(a) a/=3;
        if(b) b/=3;
        ++i;
    }
    return ans;
}

void update(LL x)
{
    for(int i=LEN;i>=0;i--)
    {
        LL p=x/g[i];
        if(p)
        {
            if(!f[i])
            {
                if(p==1) f[i]=x;
                else f[i]=cal(x,x);
                return;
            }
            if(p==1) x=cal(x,cal(f[i],f[i]));
            else x=cal(x,f[i]);
        }
    }
}

bool dis(LL x)
{
    for(int i=LEN;i>=0;i--)
    {
        LL p=x/g[i];
        if(p)
        {
            if(f[i])
            {
                if(p==1) x=cal(x,cal(f[i],f[i]));
                else x=cal(x,f[i]);
            }
            else return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    create();
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++)
        {
            LL x;
            cin>>x;
            update(x);
        }
        while(q--)
        {
            LL s;
            cin>>s;
            if(dis(s)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}