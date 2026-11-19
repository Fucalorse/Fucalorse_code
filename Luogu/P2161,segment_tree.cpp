#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5;

int q,total=0;
bool vis[(MAX+10)<<1];
struct fucalorse
{
    private:
        struct tree
        {
            int col,lazy;
        }op[(MAX+90)<<2];
        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl].col=op[hl].lazy=op[id].lazy;
                op[hr].col=op[hr].lazy=op[id].lazy;
                op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].col=op[id].lazy=k;
                return;
            }
            down(id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            if(op[hl].col==op[hr].col) op[id].col=op[hl].col;
            else op[id].col=-1;
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed)
            {
                if(op[id].col==0) return 0;
                else if(op[id].col==-1)
                {
                    down(id);
                    int mid=(l+r)>>1;
                    int hl=id<<1,hr=id<<1|1;
                    return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
                }
                else if(!vis[op[id].col])
                {
                    total--;
                    vis[op[id].col]=true;
                    return 1;
                }
                else return 0;
            }
            else
            {
                down(id);
                int mid=(l+r)>>1;
                int hl=id<<1,hr=id<<1|1;
                return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
            }
        }
        public:
            void update(const int &st,const int &ed,const int &k)
            {
                dfs(1,MAX,1,st,ed,k);
                total++;
            }
            int get(const int &st,const int &ed) { return query(1,MAX,1,st,ed); }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        char c;
        cin>>c;
        if(c=='A')
        {
            int st,ed;
            cin>>st>>ed;
            printf("%d\n",fu.get(st,ed));
            fu.update(st,ed,i);
        }
        else printf("%d\n",total);
    }
    return 0;
}