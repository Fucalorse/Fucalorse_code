#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=17,inf=2e9;

struct fountain
{
    int d,c;
}num[MAX];

struct qwq
{
    int nxt,s;
}f[MAX][LEN+2];

int n,q;

struct fucalorse
{
    void monotonous()
    {
        stack<int>op;
        for(int i=1;i<=n;i++)
        {
            while(op.size()&&num[i].d>num[op.top()].d)
            {
                f[op.top()][0].nxt=i;
                f[op.top()][0].s=num[i].c;
                op.pop();
            }
            op.push(i);
        }
        while(op.size())
        {
            f[op.top()][0].nxt=0;
            op.pop();
        }
    }
    void create()
    {
        monotonous();
        for(int k=1;(1<<k)<=n;k++)
            for(int i=1;i+(1<<k)<=n;i++)
            {
                f[i][k].nxt=f[f[i][k-1].nxt][k-1].nxt;
                f[i][k].s=f[i][k-1].s+f[f[i][k-1].nxt][k-1].s;
            }
    }
    int query(int r,int v)
    {
        if(v<=num[r].c) return r;
        v-=num[r].c;
        for(int k=LEN;k>=0;k--)
        {
            if(f[r][k].nxt&&f[r][k].s<v)
            {
                v-=f[r][k].s;
                r=f[r][k].nxt;
            }
        }
        return f[r][0].nxt;
    }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>num[i].d>>num[i].c;
    fu.create();
    while(q--)
    {
        int r,v;
        cin>>r>>v;
        cout<<fu.query(r,v)<<'\n';
    }
    return 0;
}