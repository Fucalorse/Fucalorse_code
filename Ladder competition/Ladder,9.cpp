#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'

const int MAX=150;

LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

LL lcm(LL a,LL b) { return a/gcd(a,b)*b; }

struct qwq
{
    LL x,y;
};

int n;
int a[MAX];

int main()
{
    scanf("%d",&n);
    qwq pre={0,1},now;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld/%lld",&now.x,&now.y);
        LL z=lcm(pre.y,now.y);
        LL ans=z/pre.y*pre.x+z/now.y*now.x;
        LL r=gcd(llabs(z),llabs(ans));
        pre={ans/r,z/r};
    }
    if(!pre.x)
    {
        printf("0");
        return 0;
    }
    LL m=pre.x/pre.y;
    pre.x%=pre.y;
    if(m) printf("%lld",m);
    if(m&&pre.x) printf(" ");
    if(pre.x) printf("%lld/%lld",pre.x,pre.y);
    return 0;
}