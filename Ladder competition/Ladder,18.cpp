#include <bits/stdc++.h>
using namespace std;

int a,b;
char s[20];

int main()
{
    scanf(" %s",s+1);
    a=(s[1]-'0')*10+(s[2]-'0'),b=(s[4]-'0')*10+(s[5]-'0');
    if(a<12||(a==12&&b==0)) printf("Only %s.  Too early to Dang.\n",s+1);
    else
    {
        int ans=a-12+(b>0?1:0);
        for(int i=1;i<=ans;i++)
            printf("Dang");
    }
    return 0;
}