#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

char s[MAX];
LL op[MAX];

void solve()
{
    int n=strlen(s+1);
    
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(isdigit(s[i])) continue;
        else if(s[i]=='.') ++cnt;
        else
        {
            printf("error\n");
            return;
        }
    }    
    if(cnt!=3)
    {
        printf("error\n");
        return;
    }
    LL a,b,c,d;
    sscanf(s+1,"%lld.%lld.%lld.%lld",&a,&b,&c,&d);
    LL ans=(a<<24)|(b<<16)|(c<<8)|d;
    printf("%lld\n",ans);

    int tot=0;
    while(ans)
    {
        op[++tot]=ans&15;
        ans>>=4;
    }

    for(int i=tot;i>=1;i--)
    {
        if(op[i]<=9) printf("%lld",op[i]);
        else
        {
            char c='a'+op[i]-10;
            printf("%c",c);
        }
    }
    printf("\n");
}

int main()
{
    while(scanf(" %s",s+1)==1) solve();
    return 0;
}