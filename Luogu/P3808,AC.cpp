#include <bits/stdc++.h>
using namespace std;

const int MAX=26,LEN=1e6+90;

struct fucalorse
{
    private:
        struct qwq
        {
            qwq *op[MAX],*fail;
            int exist;
            qwq() { memset(op,0,sizeof op),fail=nullptr,exist=0; }
        };
        qwq *root;
    public:
        fucalorse() { root=new qwq; }
        void update(char *s)
        {
            int len=strlen(s);
            qwq *now=root;
            for(int i=0;i<len;i++)
            {
                int p=s[i]-'a';
                if(!now->op[p]) now->op[p]=new qwq;
                now=now->op[p];
            }
            now->exist++;
        }
        void bfs()
        {
            queue<qwq*>q;
            qwq *now=root;
            for(int i=0;i<MAX;i++)
            {
                if(now->op[i])
                {
                    now->op[i]->fail=root;
                    q.push(now->op[i]);
                }
                else now->op[i]=root;
            }
            while(q.size())
            {
                qwq *cur=q.front();q.pop();
                for(int i=0;i<MAX;i++)
                {
                    if(cur->op[i])
                    {
                        cur->op[i]->fail=cur->fail->op[i];
                        q.push(cur->op[i]);
                    }
                    else cur->op[i]=cur->fail->op[i];
                }
            }
        }
        int query(char *s)
        {
            qwq *now=root;
            int len=strlen(s),ans=0;
            for(int i=0;i<len;i++)
            {
                int p=s[i]-'a';
                now=now->op[p];
                for(qwq *cur=now;cur&&cur->exist!=-1;cur=cur->fail)
                {
                    ans+=cur->exist;
                    cur->exist=-1;
                }
            }
            return ans;
        }
}fu;

int n;
char s[LEN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        fu.update(s);
    }
    fu.bfs();
    cin>>s;
    cout<<fu.query(s)<<'\n';
    return 0;
}