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
    int size;
    vector<int>op;
    fucalorse(int n)
    {
        size=n;
        op.resize(n+10,0);
    }
    int lowbit(int n) { return n&-n; }
    void update(int n)
    {
        while(n<=size)
        {
            op[n]++;
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
};

struct qwq
{
    int val,id;
    bool operator<(const qwq &a)const { return val<a.val; }
};
vector<qwq>op;

int main()
{
    int n=read();
    fucalorse fu(n);
    for(int i=1;i<=n;i++)
        op.push_back({read(),i});
    sort(op.begin(),op.end());
    int len=op.size(),ans=1;
    for(int i=0;i<len;i++)
    {
        fu.update(op[i].id);
        ans=max(ans,i+1-fu.query(i+1));
    }
    printf("%d\n",ans);
    return 0;
}