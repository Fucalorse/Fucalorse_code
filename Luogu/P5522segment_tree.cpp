#include <bits/stdc++.h>
using namespace std;

#define UI unsigned int

const int MAX=1e5+90;

struct read
{
    int num_read()
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
    pair<UI,UI> string_read()
    {
        pair<UI,UI>ans={0,0};
        UI f=1;
        char c=getchar();
        while(c!='0'&&c!='1'&&c!='?') c=getchar();
        while(c=='0'||c=='1'||c=='?')
        {
            if(c^'?')
            {
                if(c^'0') ans.first|=f;
                else ans.second|=f;
            }
            f<<=1;
            c=getchar();
        }
        return ans;
    }
}fu;

int k,n,q;
struct fucalorse
{
    private:
        struct qwq
        {
            UI a1,a0;
            qwq operator|(const qwq &other)const
            {
                return {a1|other.a1,a0|other.a0};
            }
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                auto now=fu.string_read();
                op[id].a1=now.first,op[id].a0=now.second;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=op[hl]|op[hr];
        }
        void dfs(int l,int r,int id,const int &x)
        {
            if(l==r)
            {
                auto now=fu.string_read();
                op[id].a1=now.first,op[id].a0=now.second;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x);
            else dfs(mid+1,r,hr,x);
            op[id]=op[hl]|op[hr];
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {0,0};
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)|query(mid+1,r,hr,st,ed);
        }
    public:
        void debut() { create(1,n,1); }
        void update(const int &x) { dfs(1,n,1,x); }
        UI get(const int &st,const int &ed)
        {
            qwq now=query(1,n,1,st,ed);
            if(now.a0&now.a1) return 0;
            else
            {
                UI ans=(~now.a0)&(~now.a1)&((1<<k)-1);
                bitset<32>bit(ans);
                return 1<<(bit.count());
            }
        }
}fufu;

int main()
{
    k=fu.num_read(),n=fu.num_read(),q=fu.num_read();
    fufu.debut();
    int ans=0;
    while(q--)
    {
        int p=fu.num_read();
        if(!p)
        {
            int st=fu.num_read(),ed=fu.num_read();
            ans^=fufu.get(st,ed);
        }
        else
        {
            int x=fu.num_read();
            fufu.update(x);
        }
    }
    printf("%d\n",ans);
    return 0;
}