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

int n,q;
struct fucalorse
{
    private:
        struct tree
        {
            int cnt;
            bool lazy;
        }op[MAX<<2];
        void down(int l,int r,int id)
        {
            if(op[id].lazy)
            {
                int mid=(l+r)>>1;
                int hl=id<<1,hr=id<<1|1;
                int lenl=mid-l+1,lenr=r-mid;
                op[hl].cnt=lenl-op[hl].cnt;
                op[hl].lazy^=1;
                op[hr].cnt=lenr-op[hr].cnt;
                op[hr].lazy^=1;
                op[id].lazy=false;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                op[id].cnt=(r-l+1)-op[id].cnt;
                op[id].lazy^=1;
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed);
            if(mid<ed) dfs(mid+1,r,hr,st,ed);
            op[id].cnt=op[hl].cnt+op[hr].cnt;
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].cnt;
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
        public:
            void update(const int &st,const int &ed) { dfs(1,n,1,st,ed); }
            int get(const int &st,const int &ed) { return query(1,n,1,st,ed); }
}fu;

int main()
{
    n=read(),q=read();
    while(q--)
    {
        int p=read(),st=read(),ed=read();
        if(!p) fu.update(st,ed);
        else printf("%d\n",fu.get(st,ed));
    }
    return 0;
}