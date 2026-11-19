#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=60;

char s[MAX];

int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1),cnt=0;
    for(int i=1;i<=len;i++)
        if(s[i]=='2') ++cnt;
    double ans;
    if(s[1]=='-') ans=(double)cnt/(len-1)*1.5;
    else ans=(double)cnt/len;
    if((s[len]-'0')%2==0) ans*=2;
    printf("%.2lf%%",ans*100);
    return 0;
}