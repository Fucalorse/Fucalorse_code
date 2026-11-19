#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

char now[]=".com";

int T;
char s[MAX];

bool check_total(char c) { return isupper(c)||islower(c)||isdigit(c)||c=='_'||c=='@'||c=='.'; }

bool check_pre_suf(char c) { return isupper(c)||islower(c)||isdigit(c); }

void solve()
{
    scanf(" %s",s+1);

    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if(!check_total(s[i]))
        {
            printf("NO\n");
            return;
        }

        if(s[i]=='@')
        {
            if(!check_pre_suf(s[i-1])||!check_pre_suf(s[i+1]))
            {
                printf("NO\n");
                return;
            }
        }
        else if(s[i]=='.')
        {
            if(len-i+1!=4)
            {
                printf("NO\n");
                return;
            }

            if(strncmp(s+i,now,4))
            {
                printf("NO\n");
                return;
            }
        }
    }

    printf("YES\n");
}

int main()
{
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}