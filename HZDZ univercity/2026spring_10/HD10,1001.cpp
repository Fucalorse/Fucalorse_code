#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128

i128 read()
{
    i128 ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

int t;
i128 n,m,a,b;

i128 min(i128 a,i128 b) { return a<b?a:b; }

void solve()
{
    a=read(),b=read(),n=read(),m=read();
    i128 now=(n/m)*(n/m);
    if(min(a,b)<now) printf("NO\n");
    else printf("YES\n");
}

int main()
{
    t=read();
    while(t--) solve();
    return 0;
}