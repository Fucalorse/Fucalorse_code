#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

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

int n;
int num[MAX];
vector<LL>op;
queue<LL>q;

int main()
{
    n=read();
    int minn=1e9,maxn=0;
    for(int i=0;i<n;i++)
    {
        int a=read();
        num[a]++;
        if(a<minn) minn=a;
        if(a>maxn) maxn=a;
    }
    for(int i=minn;i<=maxn;i++)
        while(num[i]) op.push_back(i),num[i]--;
    LL total=0;
    for(size_t i=0;n-i+q.size()>1;)
    {
        LL a,b;
        if(q.empty()||(i<n&&op[i]<q.front())) a=op[i++];
        else a=q.front(),q.pop();
        if(q.empty()||(i<n&&op[i]<q.front())) b=op[i++];
        else b=q.front(),q.pop();
        total+=a+b;
        q.push(a+b);
    }
    printf("%lld\n",total);
    return 0;
}