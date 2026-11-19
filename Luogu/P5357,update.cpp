#include <bits/stdc++.h>
using namespace std;

const int MAX=26,LEN=2e5+90;

int n;
string s;
int num[LEN],ans[LEN],indeg[LEN];

struct fucalorse
{
    private:
        struct tree
        {
            int nxt[MAX],fail;
            int id,cnt;
        }op[LEN];
        int qwq;
    public:
        fucalorse() { qwq=0; }
        void update(const string &s,const int &x)
        {
            int now=0;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                if(!op[now].nxt[p]) op[now].nxt[p]=++qwq;
                now=op[now].nxt[p];
            }
            if(!op[now].id) op[now].id=x;
            num[x]=op[now].id;
        }
        void bfs()
        {
            queue<int>q;
            for(int i=0;i<MAX;i++)
            {
                if(op[0].nxt[i])
                {
                    op[0].fail=0;
                    q.push(op[0].nxt[i]);
                }
                else op[0].nxt[i]=0;
            }
            while(q.size())
            {
                int cur=q.front();q.pop();
                for(int i=0;i<MAX;i++)
                {
                    if(op[cur].nxt[i])
                    {
                        op[op[cur].nxt[i]].fail=op[op[cur].fail].nxt[i];
                        indeg[op[op[cur].nxt[i]].fail]++;
                        q.push(op[cur].nxt[i]);
                    }
                    else op[cur].nxt[i]=op[op[cur].fail].nxt[i];
                }
            }
        }
        void query(const string &s)
        {
            int now=0;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                now=op[now].nxt[p];
                op[now].cnt++;
            }
        }
        void find()
        {
            queue<int>q;
            for(int i=0;i<=qwq;i++)
                if(indeg[i]==0) q.push(i);
            while(q.size())
            {
                int cur=q.front();q.pop();
                ans[op[cur].id]=op[cur].cnt;
                int to=op[cur].fail;
                op[to].cnt+=op[cur].cnt;
                if(--indeg[to]==0) q.push(to);
            }
        }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        fu.update(s,i);
    }
    fu.bfs();
    cin>>s;
    fu.query(s);
    fu.find();
    for(int i=1;i<=n;i++)
        cout<<ans[num[i]]<<'\n';
    return 0;
}