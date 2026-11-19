#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 1e9
#define LL long long

int T;
int num[MAX];
char s[MAX],op[MAX];

int cal(int a,int b,char c)
{
    if(c=='+') return a+b;
    else if(c=='-') return a-b;
    else if(c=='*') return a*b;
    else return a/b;
}

int get(char c)
{
    if(c=='+'||c=='-') return 1;
    else if(c=='*'||c=='/') return 2;
    else return 0;
}

void solve()
{
    scanf(" %s",s+1);

    int qwq=0,tot=0,len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if(isdigit(s[i]))
        {
            int now=0;
            while(i<=len&&isdigit(s[i]))
            {
                now=now*10+s[i]-'0';
                i++;
            }
            num[++qwq]=now;
            --i;
        }
        else if(s[i]=='(') op[++tot]=s[i];
        else if(s[i]==')')
        {
            while(tot&&op[tot]!='(')
            {
                int b=num[qwq--];
                int a=num[qwq--];
                char c=op[tot--];
                
                num[++qwq]=cal(a,b,c);
            }
            --tot;
        }
        else
        {
            while(tot&&get(op[tot])>=get(s[i]))
            {
                int b=num[qwq--];
                int a=num[qwq--];
                char c=op[tot--];

                num[++qwq]=cal(a,b,c);
            }
            op[++tot]=s[i];
        }
    }

    while(tot)
    {
        int b=num[qwq--];
        int a=num[qwq--];
        char c=op[tot--];

        num[++qwq]=cal(a,b,c);
    }

    printf("%d\n",num[1]);
}

int main()
{
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}