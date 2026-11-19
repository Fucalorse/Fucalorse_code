#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=2090;

LL read()
{
    LL ans=0,f=1;
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

struct discrete
{
    vector<LL>num;
    void add(const LL &n) { num.push_back(n); }
    void create()
    {
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
    }
    int find(const LL &n)
    {
        return lower_bound(num.begin(),num.end(),n)-num.begin()+1;
    }
    LL cal(const int &l,const int &r) { return num[r]-num[l-1]; }
    int size() { return num.size(); }
}fu;

struct segment
{
    LL x,y1,y2;
    int k;
    bool operator<(const segment &a)const { return x<a.x; }
};
vector<segment>seg;

int n;
struct fucalorse
{
    private:
        struct tree
        {
            LL len;
            int cnt;
        }op[MAX<<2];
        LL sum(int l,int r,int id)
        {
            if(op[id].cnt) return fu.cal(l,r);
            if(l==r) return 0;
            return op[id<<1].len+op[id<<1|1].len;
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].cnt+=k;
                op[id].len=sum(l,r,id);
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].len=sum(l,r,id);
        }
        public:
            void update(const size_t &i)
            {
                int l=fu.find(seg[i].y1),r=fu.find(seg[i].y2)-1;
                dfs(1,fu.size(),1,l,r,seg[i].k);
            }
            LL get() { return op[1].len; }
}fufu;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        LL x1=read(),y1=read(),x2=read(),y2=read();
        seg.push_back({x1,y2,y1,1});
        seg.push_back({x2,y2,y1,-1});
        fu.add(y1),fu.add(y2);
    }
    fu.create();
    sort(seg.begin(),seg.end());
    LL total=0,pre=seg[0].x;
    for(size_t i=0;i<seg.size();i++)
    {
        const segment &cur=seg[i];
        total+=fufu.get()*(cur.x-pre);
        fufu.update(i);
        pre=cur.x;
    }
    printf("%lld\n",total);
    return 0;
}