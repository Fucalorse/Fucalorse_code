#include <bits/stdc++.h>
using namespace std;

const int MAX=4,LEN=3e5+90;

string s[510],st;
bitset<1010>vis[LEN];
int n,ans=0;

struct fucalorse
{
    private:
        struct tree
        {
            int nxt[MAX],cnt;
        }op[LEN];
        int qwq;
        unordered_map<char,int>f;

    public:
        fucalorse()
        {
            f['A']=0,f['G']=1,f['T']=2,f['C']=3;
            f['?']=4,f['*']=5;
            qwq=0;
        }
        void update(const string &s)
        {
            int now=0;
            for(size_t i=0;i<s.size();i++)
            {
                int p=f[s[i]];
                if(!op[now].nxt[p]) op[now].nxt[p]=++qwq;
                now=op[now].nxt[p];
            }
            op[now].cnt++;
        }
        void dfs(int pos,int now)
        {
            if(vis[now][pos]) return;
            // cout<<pos<<' '<<now<<endl;
            vis[now][pos]=1;
            if(pos==(int)st.size())
            {
                ans+=op[now].cnt;
                op[now].cnt=0;
                return;
            }
            int aft=f[st[pos]];
            if(aft>=0&&aft<=3&&op[now].nxt[aft]) dfs(pos+1,op[now].nxt[aft]);
            else if(aft==4)
            {
                for(int i=0;i<MAX;i++)
                    if(op[now].nxt[i]) dfs(pos+1,op[now].nxt[i]);
            }
            else if(aft==5)
            {
                dfs(pos+1,now);
                for(int i=0;i<MAX;i++)
                    if(op[now].nxt[i])
                    {
                        dfs(pos+1,op[now].nxt[i]);
                        dfs(pos,op[now].nxt[i]);
                    }
            }
        }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>st>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        fu.update(s[i]);
    }
    fu.dfs(0,0);
    cout<<n-ans<<'\n';
    return 0;
}