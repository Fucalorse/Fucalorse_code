#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long

const ULL p=31;

int n;
string s;

int main()
{
    cin>>n>>s;
    int maxn=0;
    ULL pre=0,aft=0,x=1;
    for(int i=0;i<n-1;i++)
    {
        int a=s[i]-'a'+1,b=s[n-i-1]-'a'+1;
        pre=pre*p+a;
        aft+=x*b;
        x*=p;
        if(pre==aft) maxn=i+1;
    }
    cout<<n-maxn<<'\n';
    return 0;
}