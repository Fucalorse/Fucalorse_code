#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=26;

int n;
vector<string>op;

struct trie
{
    private:
        struct tree
        {
            int nxt[LEN];
            LL cnt;
        }op[MAX];
        int qwq=0;

    public:
        void update(const string &s)
        {
            int now=0;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                if(!op[now].nxt[p]) op[now].nxt[p]=++qwq;
                now=op[now].nxt[p];
                op[now].cnt++;
            }
        }
        int query(const string &s)
        {
            int ans=0,now=0;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                if(!op[now].nxt[p]) return ans;
                now=op[now].nxt[p];
                ans+=op[now].cnt;
            }
            return ans;
        }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n*2;i++)
    {
        string s;
        cin>>s;
        op.push_back(s);
    }
    sort(op.begin(),op.end());
    for(size_t i=0;i<op.size();i++)
        if(i&1) fu.update(op[i]);
    LL ans=0;
    for(size_t i=0;i<op.size();i++)
        if(i%2==0) ans+=fu.query(op[i]);
    cout<<ans<<endl;
    return 0;
}