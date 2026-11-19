#include <bits/stdc++.h>
using namespace std;

const int MAX=26;

struct qwq
{
    qwq *op[MAX];
    bool exist;
    qwq() { memset(op,0,sizeof op);exist=false; }
};

struct tree
{
    qwq *root;
    tree() { root=new qwq; }
    void insert(const string &s)
    {
        qwq *now=root;
        for(size_t i=0;i<s.size();i++)
        {
            int p=s[i]-'a';
            if(!now->op[p]) now->op[p]=new qwq;
            now=now->op[p];
        }
        now->exist=true;
    }
    int query(const string &s)
    {
        qwq *now=root;
        int ans=0;
        for(size_t i=0;i<s.size();i++)
        {
            int p=s[i]-'a';
            if(!now->op[p]) return ans;
            now=now->op[p];
            ans+=now->exist;
        }
        return ans;
    }
}fu;

int n;
vector<string>op;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    op.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>op[i];
        fu.insert(op[i]);
    }
    int maxn=1;
    for(auto now:op)
        maxn=max(maxn,fu.query(now));
    cout<<maxn<<'\n';
    return 0;
}