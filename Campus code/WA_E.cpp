#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int n,op[100010],qwq=0;

int main()
{
    char c;
    while(scanf("%d",&n)!=1)
        scanf("%c",&c);
    c=getchar();
    while(c!='\n'&&c!=EOF) c=getchar();
    for(int i=1;i<=n;i++)
        scanf("%d",op+i);
    for(int i=2;i<=n;i++)
    {
        if(i*i-op[i-1]!=op[i])
        {
            printf("false");
            return 0;
        }
    }
    printf("true");
    return 0;
}