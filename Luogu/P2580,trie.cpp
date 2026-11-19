#include <bits/stdc++.h>
using namespace std;

const int MAX=26;

struct qwq
{
    qwq *op[MAX];
    bool exist;
    qwq() { memset(op,0,sizeof op),exist=false; }
};

unordered_set<string>vis;

struct fucalorse
{
    qwq *root=new qwq;
    void update(const string &s)
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
    void query(const string &s)
    {
        qwq *now=root;
        for(size_t i=0;i<s.size();i++)
        {
            int p=s[i]-'a';
            if(!now->op[p])
            {
                cout<<"WRONG"<<'\n';
                return;
            }
            now=now->op[p];
        }
        if(now->exist&&!vis.count(s))
        {
            vis.insert(s);
            cout<<"OK"<<'\n';
        }
        else if(!now->exist) cout<<"WRONG"<<'\n';
        else cout<<"REPEAT"<<'\n';
    }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        fu.update(s);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        fu.query(s);
    }
    return 0;
}