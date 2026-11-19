#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int t;
char s[MAX],op[MAX];

bool left(char c) { return c=='('||c=='['||c=='{'; }
bool right(char c) { return c==')'||c==']'||c=='}'; }

bool cal(char a,char b)
{
    if(a=='('&&b==')') return true;
    if(a=='['&&b==']') return true;
    if(a=='{'&&b=='}') return true;
    return false;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",s+1);
        int len=strlen(s+1),qwq=0;
        bool f=true;
        for(int i=1;i<=len;i++)
        {
            if(left(s[i])) op[++qwq]=s[i];
            else if(right(s[i]))
            {
                if(cal(op[qwq],s[i])) --qwq;
                else
                {
                    f=false;
                    break;
                }
            }
        }
        if(f&&!qwq) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}