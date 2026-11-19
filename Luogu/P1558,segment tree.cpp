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

int n,t,q;
struct fucalorse
{
    private:
        struct tree
        {
            int col,lazy;
            tree(){ col=1<<1,lazy=0; }
        }op[MAX<<2];
        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl].col=1<<op[id].lazy;
                op[hl].lazy=op[id].lazy;
                op[hr].col=1<<op[id].lazy;
                op[hr].lazy=op[id].lazy;
                op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].col=1<<k;
                op[id].lazy=k;
                return;
            }
            down(id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].col=op[hl].col|op[hr].col;
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].col;
            down(id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)|query(mid+1,r,hr,st,ed);
        }
        int lowbit(int n)  { return n&-n; }
    public:
        void update(const int &st,const int &ed,const int &k)
        {
            dfs(1,n,1,st,ed,k);
        }
        int get(const int &st,const int &ed)
        {
            int now=query(1,n,1,st,ed),ans=0;
            while(now)
            {
                ans++;
                now-=lowbit(now);
            }
            return ans;
        }
}fu;

int main()
{
    n=read(),t=read(),q=read();
    while(q--)
    {
        char c;
        scanf(" %c",&c);
        int st=read(),ed=read();
        if(st>ed) swap(st,ed);
        if(c=='C') 
        {
            int k=read();
            // printf("%d %d %d\n",st,ed,k);
            fu.update(st,ed,k);
        }
        else printf("%d\n",fu.get(st,ed));
    }
    return 0;
}