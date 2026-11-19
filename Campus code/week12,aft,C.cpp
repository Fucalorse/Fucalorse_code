#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int t,n,tar;
int a[MAX];

void solve()
{
    scanf("%d%d",&tar,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        ++ans;
        if(a[mid]==tar) break;
        if(a[mid]<tar) l=mid+1;
        else r=mid-1;
    }
    if(l>r) printf("Not Found\n");
    else printf("%d\n",ans);
}

int main()
{
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}