#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 2e9
#define LL long long

char s[MAX];

int main()
{
    while(scanf(" %s",s)==1)
    {
        double ans=atof(s);
        printf("%.2lf\n\n",ans);
    }
    return 0;
}