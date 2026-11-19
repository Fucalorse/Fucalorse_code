#include <bits/stdc++.h>
using namespace std;

const int MAX=600;

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

struct fucalorse
{
    private:
        struct tree
        {
            int l,r,cnt;
        }op[(MAX+90)<<2];
        int num,root;
        void dfs(int &pos,int l,int r,const int &x)
        {
            if(!pos) pos=++num;
            op[pos].cnt++;
            if(l==r) return;
            int mid=(l+r)>>1;
            if(x<=mid) dfs(op[pos].l,l,mid,x);
            else dfs(op[pos].r,mid+1,r,x);
        }
        int query(int pos,int l,int r,int k)
        {
            if(l==r) return l;
            int mid=(l+r)>>1,len=op[op[pos].l].cnt;
            if(k<=len) return query(op[pos].l,l,mid,k);
            else return query(op[pos].r,mid+1,r,k-len);
        }
        public:
            fucalorse()
            {
                memset(op,0,sizeof op);
                root=num=0;
            }
            void update(const int &x)
            {
                dfs(root,0,MAX,x);
            }
            int get(int k)
            {
                return query(root,0,MAX,k);
            }
}fu;

int main()
{
    int n=read(),w=read();
    for(int i=1;i<=n;i++)
    {
        int a=read(),now=max(1,i*w/100);
        fu.update(a);
        printf("%d ",fu.get(i-now+1));
    }
    return 0;
}