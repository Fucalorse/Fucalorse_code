#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

int n,qwq=0;
char st[MAX],s[MAX];

int main()
{
    scanf("%d %s",&n,s+1);
    for(int i=1;i<=n;i++)
        if(s[i]!=s[i-1]) st[++qwq]=s[i];
    if(qwq%2==0) printf("2");
    else printf("%d",qwq==1?1:3);
    return 0;
}