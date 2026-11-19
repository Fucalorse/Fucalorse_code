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

struct qwq
{
    qwq *op[2];
    int exist,cnt;
    qwq() { op[0]=op[1]=nullptr;exist=cnt=0; }
};

struct fucalorse
{
    qwq *root=new qwq;
    void update(vector<int>&op)
    {
        qwq *now=root;
        for(auto p:op)
        {
            if(!now->op[p]) now->op[p]=new qwq;
            now=now->op[p];
            now->cnt++;
        }
        now->exist++;
    }
    int query(vector<int>&op)
    {
        qwq *now=root;
        int ans=0;
        for(auto p:op)
        {
            if(!now->op[p]) return ans;
            now=now->op[p];
            ans+=now->exist;
        }
        return ans+now->cnt-now->exist;
    }
}fu;

int main()
{
    int n=read(),q=read();
    for(int i=1;i<=n;i++)
    {
        int len=read();
        vector<int>op;
        while(len--) op.push_back(read());
        fu.update(op);
    }
    for(int i=1;i<=q;i++)
    {
        int len=read();
        vector<int>op;
        while(len--) op.push_back(read());
        printf("%d\n",fu.query(op));
    }
    return 0;
}