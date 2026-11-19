#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

struct fucalorse
{
    int op[MAX+90];
    int lowbit(int n) { return n&-n; }
    void update(int n,const int &k)
    {
        while(n<=MAX)
        {
            op[n]+=k;
            n+=lowbit(n);
        }
    }
    int query(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=op[n];
            n-=lowbit(n);
        }
        return ans;
    }
}ful,fur;

int n;
vector<int>op;

int main()
{
    n=read();
    int maxn=0;
    for(int i=0;i<n;i++)
    {
        op.push_back(read());
        fur.update(op[i],1);
        if(op[i]>maxn) maxn=op[i];
    }
    LL total=0;
    for(auto i:op)
    {
        ful.update(i,1);
        fur.update(i,-1);
        int l=ful.query(i-1),r=fur.query(maxn)-fur.query(i);
        total+=l*r;
    }
    printf("%lld\n",total);
    return 0;
}