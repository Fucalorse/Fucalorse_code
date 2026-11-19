#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 2e9
#define LL long long

char s[MAX];

bool dis(char c) { return islower(c)||isupper(c)||isdigit(c); }

void solve()
{
    scanf("%[^\n]%*c",s+1);
    int len=strlen(s+1);
    for(int l=1,r=1;l<=len;l=r+1)
    {
        r=l;
        while(r<=len&&dis(s[r])) r++;
        if(r-l-1>=1)
        {
            for(int i=l;i<r;i++)
                printf("%c",s[i]);
            printf("\n");
        }
    }
}

int main()
{
    solve();
    return 0;
}