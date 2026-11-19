#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int l,r;

int main()
{
    scanf("%d%d",&l,&r);
    int ans=0;
    for(int i=l,cnt=1;i<=r;++i,++cnt)
    {
        printf("%5d",i);
        ans+=i;
        if(cnt%5==0) printf("\n");
    }
    if((r-l+1)%5!=0) printf("\n");
    printf("Sum = %d\n",ans);
    return 0;
}