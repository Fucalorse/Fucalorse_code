#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9;

struct Splay
{
    private:
        struct qwq
        {
            int fa,ch[2];
            int cnt,val,size;
        };
        int tot,root;
        vector<qwq>op;

        void maintain(int pos)
        {
            if(!pos) return;
            op[pos].size=op[op[pos].ch[0]].size+op[op[pos].ch[1]].size+op[pos].cnt;
        }

        int get(int pos) { return pos==op[op[pos].fa].ch[1]; }

        void rotate(int x)
        {
            int y=op[x].fa,z=op[y].fa;

            int k=get(x),w=op[x].ch[k^1];

            if(z) op[z].ch[get(y)]=x;
            op[x].fa=z;

            op[y].ch[k]=w;
            if(w) op[w].fa=y;
            op[x].ch[k^1]=y;
            op[y].fa=x;

            maintain(y);
            maintain(x);
        }

        void splay(int x,int goal=0)
        {
            while(op[x].fa!=goal)
            {
                int y=op[x].fa,z=op[y].fa;

                if(z!=goal)
                {
                    if(get(x)==get(y)) rotate(y);
                    else rotate(x);
                }

                rotate(x);
            }

            if(!goal) root=x;
        }

        void insert(int val)
        {
            if(!root)
            {
                root=++tot;
                op[root]={0,{0,0},1,val,1};
                return;
            }

            int cur=root;
            int fa=0;
            while(cur)
            {
                if(op[cur].val==val)
                {
                    op[cur].cnt++;
                    maintain(cur);
                    splay(cur);
                    return;
                }

                fa=cur;
                cur=op[cur].ch[val>op[cur].val];
            }

            int x=++tot;
            op[x].fa=fa;
            op[x].val=val;
            op[x].cnt=op[x].size=1;

            op[fa].ch[val>op[fa].val]=x;

            splay(x);
        }
    public:
        Splay(int n)
        {
            tot=root=0;
            op.assign(n+3,{0,{0,0},0,0,0});
        }
        void update(int val) { insert(val); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    Splay fu(10000);
    fu.update(1);

    return 0;
}