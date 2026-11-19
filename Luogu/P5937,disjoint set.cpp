#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90,LEN=5090;

struct fucalorse
{
    int fa[MAX];
    fucalorse()
    {
        for(int i=0;i<MAX;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        if(x!=fa[x])
            fa[x]=find(fa[x]);
        return fa[x];
    }
    void combine(int x,int y) { fa[find(x)]=find(y); }
}fu;

struct qwq
{
    int l,r,k;
}op[LEN];

int n,m,cnt=0;
unordered_map<int,int>f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int st,ed;
        string s;
        cin>>st>>ed>>s;
        if(!f.count(st-1)) f[st-1]=++cnt;
        if(!f.count(ed)) f[ed]=++cnt;
        op[i].l=st-1,op[i].r=ed;
        if(s[0]=='e') op[i].k=1;
        else op[i].k=0;
    }
    for(int i=1;i<=m;i++)
    {
        int x=f[op[i].l],y=f[op[i].r];
        if(op[i].k==1)
        {
            if(fu.find(x)==fu.find(y+cnt))
            {
                cout<<i-1<<endl;
                exit(0);
            }
            fu.combine(x,y),fu.combine(x+cnt,y+cnt);
        }
        else
        {
            if(fu.find(x)==fu.find(y))
            {
                cout<<i-1<<endl;
                exit(0);
            }
            fu.combine(x,y+cnt),fu.combine(y,x+cnt);
        }
    }
    cout<<m<<endl;
    return 0;
}