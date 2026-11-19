#include <bits/stdc++.h>
using namespace std;

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
    private:
        priority_queue<int>maxn;
        priority_queue<int,vector<int>,greater<int>>minn;
        void maintain(const size_t &now)
        {
            if(minn.size()<now)
            {
                minn.push(maxn.top());
                maxn.pop();
            }
            else if(minn.size()>now)
            {
                maxn.push(minn.top());
                minn.pop();
            }
        }
    public:
        void push(const int &n,const size_t &now)
        {
            if(maxn.empty()) minn.push(n);
            else
            {
                if(n>minn.top()) minn.push(n);
                else maxn.push(n);
            }
            maintain(now);
        }
        int get() { return minn.top(); }
}fu;

int main()
{
    int n=read(),w=read();
    for(int i=1;i<=n;i++)
    {
        int a=read();
        size_t now=max(1,i*w/100);
        fu.push(a,now);
        printf("%d ",fu.get());
    }
    return 0;
}