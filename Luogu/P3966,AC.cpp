#include <bits/stdc++.h>
using namespace std;

const int MAX=26,LEN=1e6+90;

int n;
int id[LEN],indeg[LEN];
string s[LEN];

struct fucalorse
{
    private:
        struct tree
        {
            int nxt[MAX],fail,cnt;
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
                op[now].cnt++;
            }
            id[x]=now;
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
        void query()
        {
            queue<int>q;
            for(int i=1;i<=qwq;i++)
                if(indeg[i]==0) q.push(i);
            while(q.size())
            {
                int cur=q.front();q.pop();
                int to=op[cur].fail;
                op[to].cnt+=op[cur].cnt;
                if(--indeg[to]==0) q.push(to);
            }
        }
        void applause()
        {
            for(int i=1;i<=n;i++)
                cout<<op[id[i]].cnt<<'\n';
        }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        fu.update(s[i],i);
    }
    fu.bfs();
    fu.query();
    fu.applause();
    return 0;
}