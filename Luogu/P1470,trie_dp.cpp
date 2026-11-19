#include <bits/stdc++.h>
using namespace std;

const int MAX=26,LEN=2e5+90;

struct qwq
{
    qwq *op[MAX];
    bool exist;
    qwq() { memset(op,0,sizeof op),exist=false; }
};

bool f[LEN];

struct fucalorse
{
    qwq *root=new qwq;
    void update(const string &s)
    {
        qwq *now=root;
        for(int i=s.size()-1;i>=0;i--)
        {
            int p=s[i]-'A';
            if(!now->op[p]) now->op[p]=new qwq;
            now=now->op[p];
        }
        now->exist=true;
    }
    void query(const string &s,const int &x)
    {
        qwq *now=root;
        for(int i=x-1;i>=0;i--)
        {
            int p=s[i]-'A';
            if(!now->op[p]) return;
            now=now->op[p];
            if(now->exist&&f[i])
            {
                f[x]=true;
                return;
            }
        }
    }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    string s="",p;
    while(cin>>p)
    {
        if(p==".") break;
        fu.update(p);
    }
    while(cin>>p) s+=p;
    f[0]=true;
    int ans=0;
    for(size_t i=0;i<s.size();i++)
    {
        int x=i+1;
        fu.query(s,x);
        if(f[x]) ans=x;
    }
    cout<<ans<<'\n';
    return 0;
}