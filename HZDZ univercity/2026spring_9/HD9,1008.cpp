#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128_t
const int MAX=5e5+90;

int t,n;
LL a[MAX];

void print(i128 n)
{
    if(!n) return;
    print(n/10);
    putchar(n%10+'0');
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1,greater<LL>());
    i128 ans=0,now=a[1];
    for(int i=2;i<=n;i++)
    {
        ans+=now;
        now+=a[i];
    }
    if(n==1) printf("0");
    else print(ans);
    printf("\n");
}

int main()
{
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}