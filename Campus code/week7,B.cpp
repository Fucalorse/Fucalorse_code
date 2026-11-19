#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n,qwq=0;
int op[MAX];

int cal(int x)
{
    int cnt=0;
    while(x)
    {
        int now=x%10;
        if(now==1) ++cnt;
        x/=10;
    }
    return cnt;
}

int main()
{
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int now=cal(i);
        ans+=now;
        if(now) op[++qwq]=i;
    }
    printf("%d\n",ans);
    for(int i=qwq;i>=1;i--)
    {
        if(i!=qwq) printf(" ");
        printf("%d",op[i]);
    }
    return 0;
}