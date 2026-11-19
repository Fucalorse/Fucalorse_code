#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

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

struct peach
{
    private:
        struct qwq
        {
            int l,r;
        }op[MAX];
    public:
        void create(int n)
        {
            for(int i=1;i<=n;i++)
                op[i]={i-1,i+1};
            op[0].l=0,op[n].r=0;
        }
        pair<int,int> remove(const int &i,const int &j)
        {
            op[op[i].l].r=op[j].r;
            op[op[j].r].l=op[i].l;
            return {op[i].l,op[j].r};
        }
}fu;

struct qwq
{
    int pa,pb;
    bool operator<(const qwq &a)const { return pa<a.pa; }
};

int n;
int num[MAX],id[MAX];
bool vis[MAX];
priority_queue<qwq>q;

int main()
{
    n=read();
    fu.create(n);
    for(int i=1;i<=n;i++)
    {
        num[i]=read();
        id[num[i]]=i;
        if(i>1) q.push({num[i-1],num[i]});
    }
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[id[cur.pa]]||vis[id[cur.pb]]) continue;
        vis[id[cur.pa]]=vis[id[cur.pb]]=true;
        printf("%d %d ",cur.pa,cur.pb);
        auto now=fu.remove(id[cur.pa],id[cur.pb]);
        if(now.first&&now.second) q.push({num[now.first],num[now.second]});
    }
    return 0;
}