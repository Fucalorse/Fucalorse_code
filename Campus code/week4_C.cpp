#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define LL long long
#define MAX 100090
#define inf -1e17

double cal(double ans,double now,char s)
{
    if(ans==inf) return now;
    if(s=='+') return ans+now;
    else if(s=='-') return ans-now;
    else if(s=='*') return ans*now;
    else
    {
        if(!now) return 0;
        else return ans/now;
    }
}

double dfs()
{
    double ans=inf;
    char s;
    scanf(" %c",&s);
    // printf("%c %lld\n",s,ans);
    char c=getchar();
    while(1)
    {
        if(c==' ')
        {
            c=getchar();
            continue;
        }
        if(isdigit(c))
        {
            LL num=0;
            while(c>='0'&&c<='9')
            {
                num=num*10+c-'0';
                c=getchar();
            }
            ans=cal(ans,(double)num,s);
            // printf("%lld %lld\n",num,ans);
        }
        else if(c=='(')
        {
            ans=cal(ans,dfs(),s);
            c=getchar();
        }
        else if(c==')') break;
    }
    return ans;
}

int main()
{
    char c;
    scanf(" %c",&c);
    double ans=dfs();
    if(ans<0) ans-=0.5;
    else ans+=0.5;
    printf("%lld",(LL)ans);
    return 0;
}