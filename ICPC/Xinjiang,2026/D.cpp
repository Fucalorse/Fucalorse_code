#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,inf=2e9;

struct Trie
{
    private:
        struct qwq
        {
            qwq *op[3];
            int cnt;
            qwq()
            {
                memset(op,0,sizeof(op));
                cnt=0;
            }
        };

        vector<qwq*>ver;

        qwq *clone(qwq *old)
        {
            qwq *now=new qwq;
            
            if(old)
            {
                for(int i=0;i<=2;i++)
                    if(old->op[i]) now->op[i]=old->op[i];

                now->cnt=old->cnt;
            }

            return now;
        }
    public:
        Trie() { ver.push_back(new qwq); }

        void update(const string &s)
        {
            qwq *pre=ver.back(),*now=clone(ver.back());
            ver.push_back(now);

            for(auto &cur:s)
            {
                int p=cur-'0';

                qwq *old=pre?pre->op[p]:nullptr;
                qwq *aft=clone(old);

                now->op[p]=aft;
                aft->cnt++;

                now=aft;
                if(pre) pre=pre->op[p];
            }
        }

        int find_path(const string &s,int pos)
        {
            qwq *now=ver[pos];
            int ans=0;

            for(auto &cur:s)
            {
                int p=cur-'0';

                if(now&&now->op[p]) ans+=now->op[p]->cnt;
                else break;

                if(now) now=now->op[p];
            }

            return ans;
        }

        int query(const string &s,int l,int r) { return find_path(s,r)-find_path(s,l-1); }
};

int T,n,q;
string str[MAX];

void solve()
{
    cin>>n>>q;

    Trie fu;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];

        fu.update(str[i]);
    }

    while(q--)
    {
        string s;
        int l,r;

        cin>>l>>r>>s;

        cout<<fu.query(s,l,r)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}

// g++ D.cpp -O2 -o out.exe && out.exe < in.txt