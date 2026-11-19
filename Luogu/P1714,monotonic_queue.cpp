#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+90;

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

int n,k;
int f[MAX];
deque<int>q;

int main()
{
    n=read(),k=read();
    int ans=-1e9;
    q.push_back(0);
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+read();
        while(q.size()&&f[i]<f[q.back()])  q.pop_back();
        while(q.size()&&q.front()<=i-k-1) q.pop_front();
        if(q.empty()) ans=max(ans,f[i]-f[i-1]);
        else ans=max(ans,f[i]-f[q.front()]);
        q.push_back(i);
    }
    printf("%d\n",ans);
    return 0;
}