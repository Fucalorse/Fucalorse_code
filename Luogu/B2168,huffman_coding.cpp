#include <bits/stdc++.h>
using namespace std;

#define LL long long

struct qwq
{
    int id;
    LL val;
    qwq *l,*r;
    qwq(int i,LL k,qwq *a,qwq *b):id(i),val(k),l(a),r(b){}
};

struct cmp
{
    bool operator()(const qwq *a,const qwq *b)
    {
        return a->val>b->val;
    }
};

int n;
priority_queue<qwq*,vector<qwq*>,cmp>q;
vector<string>op;
unordered_map<int,string>f;

void dfs(qwq *pos,string s)
{
    if(pos->id)
    {
        if(s.empty()) s='0';
        f[pos->id]=s;
        return;
    }
    dfs(pos->l,s+'0');
    dfs(pos->r,s+'1');
}

void clear(qwq *pos)
{
    if(!pos) return;
    queue<qwq*>q;
    q.push(pos);
    while(q.size())
    {
        qwq *cur=q.front();q.pop();
        if(cur->l) q.push(cur->l);
        if(cur->r) q.push(cur->r);
        delete(cur);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    op.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        LL val;
        cin>>op[i]>>val;
        q.push(new qwq(i,val,nullptr,nullptr));
    }
    while(q.size()>1)
    {
        qwq *a=q.top();q.pop();
        qwq *b=q.top();q.pop();
        q.push(new qwq(0,a->val+b->val,a,b));
    }
    dfs(q.top(),"");
    for(int i=1;i<=n;i++)
        cout<<op[i]<<' '<<f[i]<<'\n';
    clear(q.top());
    return 0;
}