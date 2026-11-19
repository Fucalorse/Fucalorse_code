#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int m,n;

void solve()
{
    if((m*n)%2==0) printf("%.2lf\n",(double)m*n);
    else printf("%.2lf\n",(double)m*n-1+sqrt(2));
}

int main()
{
    while(scanf("%d%d",&m,&n)==2) solve();
    return 0;
}