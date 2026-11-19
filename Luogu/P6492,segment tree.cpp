#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90;

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
    struct tree
    {
        int lenl,lenr,maxn;
        bool fl,fr;
        tree()
        {
            lenl=lenr=maxn=1;
            fl=fr=0;
        }
    }op[MAX<<2];
    void merge(int l,int r,int id)
    {
        int mid=(l+r)>>1;
        int hl=id<<1,hr=id<<1|1,lmid=0;
        int sl=mid-l+1,sr=r-mid;
        if((op[hl].fr^op[hr].fl)==1) lmid=op[hl].lenr+op[hr].lenl;
        // printf("%d %d\n",op[2].lenr,op[3].lenl);

        if(op[hl].lenl==sl&&lmid) op[id].lenl=lmid;
        else op[id].lenl=op[hl].lenl;

        if(op[hr].lenl==sr&&lmid) op[id].lenr=lmid;
        else op[id].lenr=op[hr].lenr;

        op[id].maxn=max(max(op[hl].maxn,op[hr].maxn),lmid);
        op[id].fl=op[hl].fl,op[id].fr=op[hr].fr;
    }
    void dfs(int l,int r,int id,const int &x)
    {
        if(l==r) 
        {
            op[id].fl^=1;
            op[id].fr^=1;
            return;
        }
        int mid=(l+r)>>1;
        int hl=id<<1,hr=id<<1|1;
        if(x<=mid) dfs(l,mid,hl,x);
        else dfs(mid+1,r,hr,x);
        merge(l,r,id);
    }
    void update(const int &x)
    {
        dfs(1,n,1,x);
    }
    int query()
    {
        return op[1].maxn;
    }
}fu;

int main()
{
    n=read(),q=read();
    while(q--)
    {
        int x=read();
        fu.update(x);
        printf("%d\n",fu.query());
    }
    return 0;
}
// 8 3
// 3
// 5
// 6