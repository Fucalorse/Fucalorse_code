#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int qwq=0;
char s[MAX],op[MAX];

int get(char c)
{
    if(c=='+'||c=='-') return 1;
    else if(c=='*'||c=='/') return 2;
    else return 0;
}

bool dis(char c) { return c=='+'||c=='-'||c=='*'||c=='/'; }

int main()
{
    scanf("%[^\n]%*c",s+1);
    int len=strlen(s+1);
    bool f=true;
    for(int i=1;i<=len;i++)
    {
        if(isdigit(s[i]))
        {
            int now=0;
            while(i<=len&&isdigit(s[i]))
            {
                now=now*10+s[i]-'0';
                ++i;
            }
            --i;
            if(f) printf("%d",now),f=false;
            else printf(" %d",now);
        }
        else if(s[i]=='(') op[++qwq]=s[i];
        else if(dis(s[i]))
        {
            while(qwq&&get(op[qwq])>=get(s[i]))
            {
                printf(" %c",op[qwq]);
                --qwq;
            }
            op[++qwq]=s[i];
        }
        else
        {
            while(qwq&&op[qwq]!='(')
            {
                printf(" %c",op[qwq]);
                --qwq;
            }
            --qwq;
        }
    }
    while(qwq)
    {
        printf(" %c",op[qwq]);
        --qwq;
    }
    return 0;
}