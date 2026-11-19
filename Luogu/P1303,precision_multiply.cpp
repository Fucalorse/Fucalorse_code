#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

string s1,s2;
int a[MAX],b[MAX],op[MAX],len1,len2;

int cal()
{
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
            op[i+j]+=a[i]*b[j];
    int len=max(len1,len2);
    for(int i=0;i<len;i++)
    {
        op[i+1]+=op[i]/10;
        op[i]%=10;
        if(op[len]) len++;
    }
    return len;
}

int main()
{
    cin>>s1>>s2;
    len1=s1.size(),len2=s2.size();
    if((len1==1&&s1[0]=='0')||(len2==1&&s2[0]=='0'))
    {
        cout<<0<<'\n';
        exit(0);
    }
    for(int i=len1-1;i>=0;i--)
        a[len1-i-1]=s1[i]-'0';
    for(int i=len2-1;i>=0;i--)
        b[len2-i-1]=s2[i]-'0';
    int len=cal();
    for(int i=len-1;i>=0;i--)
        cout<<op[i];
    cout<<'\n';
    return 0;
}