#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

char s[MAX];
int cnt[MAX];

int main()
{
    scanf(" %s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        int x=s[i];
        cnt[x]++;
    }
    for(int i=1;i<=len;i++)
    {
        int x=s[i];
        if(cnt[x]==1)
        {
            printf("%c\n",s[i]);
            break;
        }
    }
    return 0;
}