#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e6+90,mod=1e9+7;

int n;
int f[MAX],op[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    f[1]=1;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(size_t i=1,j=0;i<s.size();i++)
        {
            while(j&&s[i]!=s[j]) j=op[j];
            if(s[i]==s[j]) j++;
            op[i+1]=j;
            f[i+1]=f[j]+1;
        }
        LL total=1;
        for(size_t i=1,j=0;i<s.size();i++)
        {
            while(j&&s[i]!=s[j]) j=op[j];
            if(s[i]==s[j]) j++;
            while((j<<1)>i+1) j=op[j];
            total=total*(f[j]+1)%mod;
        }
        printf("%lld\n",total);
    }
    return 0;
}