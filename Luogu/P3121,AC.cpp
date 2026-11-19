#include <bits/stdc++.h>
using namespace std;

const int MAX=26,LEN=1e5+90;

int n;
int id[LEN],st[LEN],cnt=0;
string s[LEN];

struct fucalorse
{
    private:
        struct tree
        {
            int nxt[MAX],fail,len;
        }op[LEN];
        int qwq;
    public:
        fucalorse() { qwq=0; }
        void update(const string &s)
        {
            int now=0;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                if(!op[now].nxt[p]) op[now].nxt[p]=++qwq;
                now=op[now].nxt[p];
            }
            op[now].len=s.size();
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
                st[++cnt]=now;
                id[cnt]=i;
                if(op[now].len)
                {
                    cnt-=op[now].len;
                    now=st[cnt];
                }
            }
        }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>s[0]>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        fu.update(s[i]);
    }
    fu.bfs();
    fu.query(s[0]);
    for(int i=1;i<=cnt;i++)
        cout<<s[0][id[i]];
    cout<<'\n';
    return 0;
}