#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define  MAX 100090

int st,ed;
char s[MAX];

bool dis()
{
    int len=strlen(s+1);
    if(ed>len) ed=len;
    int mid=(ed-st)>>1;
    for(int i=0;i<=mid;i++)
        if(s[st+i]!=s[ed-i])
        {
            // printf("%d %d\n",st+i,ed-i);
            return false;
        }
    return true;
}

int main()
{
    scanf("i=%d,j=%d %s",&st,&ed,s+1);
    if(dis()) printf("Yes");
    else printf("No");
    return 0;
}