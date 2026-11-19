#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define LL long long
#define MAX 100090

char s[MAX];

int main()
{
    while(scanf(" %s",s+1)==1)
    {
        int len=strlen(s+1),st=0,qwq=0; 
        bool f=false;
        for(int i=1;i<=len;i++)
        {
            if(isdigit(s[i]))
            {
                if(!st) st=i,qwq=1,f=true;
                else ++qwq;
            }
            else if(f)
            {
                int ed=st+qwq-1;
                for(;s[st]=='0'&&st<ed;st++);
                for(int i=st;i<=ed;i++)
                    printf("%c",s[i]);
                printf("    ");
                f=false;
                st=qwq=0;
            }
        }
        if(f)
        {
            int ed=st+qwq-1;
            for(;s[st]=='0'&&st<ed;st++);
            for(int i=st;i<=ed;i++)
                printf("%c",s[i]);
            printf("    ");
        }
    }
    return 0;
}