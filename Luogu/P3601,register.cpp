#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long

const ULL mod=666623333;

vector<ULL>op;
void oula(ULL n)
{
    size_t size=n/8+1;
    unsigned char f[size];
    memset(f,0xff,sizeof f);
    for(ULL i=2;i<=n;i++)
    {
        if(f[i/8]&(1<<(i%8))) op.push_back(i);
        for(size_t j=0;j<op.size()&&op[j]*i<=n;j++)
        {
            ULL now=op[j]*i;
            f[now/8]&=~(1<<(now%8));
            if(i%op[j]==0) break;
        }
    }
}

ULL l,r;
vector<ULL>ans,num;

ULL cal()
{
    oula((ULL)sqrt(r));
    if(l==1) l=2;
    ans.resize(r-l+1),num.resize(r-l+1);
    for(ULL i=l;i<=r;i++)
    {
        size_t p=i-l;
        ans[p]=num[p]=i;
    }
    for(auto i:op)
    {
        ULL st=(l+i-1)/i*i;
        for(ULL j=st;j<=r;j+=i)
        {
            size_t p=j-l;
            while(num[p]%i==0) num[p]/=i;
            ans[p]-=ans[p]/i;
        }
    }
    ULL total=0;
    for(ULL i=l;i<=r;i++)
    {
        size_t p=i-l;
        if(num[p]>1) ans[p]-=ans[p]/num[p];
        total=(total+i-ans[p])%mod;
    }
    return total;
}

int main()
{
    cin>>l>>r;
    cout<<cal()<<endl;
    return 0;
}