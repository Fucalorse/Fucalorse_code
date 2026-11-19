#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

char s[MAX];

void solve()
{
    scanf(" %[^\n]%*c",s+1);
    int n=strlen(s+1)-1;
    for(int i=1;i<=n;)
    {
        if(s[i]=='M')
        {
            printf("Monday\n");
            i++;
        }
        else if(s[i]=='W')
        {
            printf("Wednesday\n");
            i++;
        }
        else if(s[i]=='F')
        {
            printf("Friday\n");
            i++;
        }
        else if(s[i]=='T')
        {
            if(s[i+1]=='u')
            {
                printf("Tuesday\n");
                i+=2;
            }
            else if(s[i+1]=='h')
            {
                printf("Thursday\n");
                i+=2;
            }
            else
            {
                printf("Wrong data\n");
                i++;
            }
        }
        else if(s[i]=='S')
        {
            if(s[i+1]=='a')
            {
                printf("Saturday\n");
                i+=2;
            }
            else if(s[i+1]=='u')
            {
                printf("Sunday\n");
                i+=2;
            }
            else
            {
                printf("Wrong data\n");
                i++;
            }
        }
        else
        {
            printf("Wrong data\n");
            i++;           
        }
    }
}

int main()
{
    solve();
    return 0;
}