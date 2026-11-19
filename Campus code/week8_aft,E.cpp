#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n,qwq=0;
int op[MAX];
char s[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf(" %s",s);
        if(s[1]=='o')
        {
            if(!qwq) printf("empty\n");
            else printf("%d",op[qwq]),--qwq;
        }
        else
        {
            int val;
            scanf("%d",&val);
            op[++qwq]=val;
        }
    }
    return 0;
}