#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

char s[MAX];
int a[MAX],x,qwq=0;

int main()
{
    scanf(" %[^\n]%*c%d",s+1,&x);
    int len=strlen(s+1),num=0;
    for(int i=1;i<=len;i++)
    {
        if(isdigit(s[i])) num=num*10+s[i]-'0';
        else a[++qwq]=num,num=0;
    }
    a[++qwq]=num;
    for(int i=1;i<=qwq;i++)
        for(int j=i+1;j<=qwq;j++)
            if(a[i]+a[j]==x)
            {
                printf("%d %d\n",a[i],a[j]);
                return 0;
            }
    return 0;
}