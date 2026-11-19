#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n;
int num[MAX],op[MAX];

int main()
{
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        for(int i=1;i<=n;i++)
            scanf("%d",num+i);
        int qwq=0;
        for(int i=1,j=1;i<=n;i++)
        {
            op[++qwq]=i;
            while(qwq&&op[qwq]==num[j])
            {
                qwq--;
                j++;
            }
        }
        if(qwq) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}