#include <bits/stdc++.h>
using namespace std;

const int MAX=5090;

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

struct discrete
{
    vector<int>num;
    void add(const int &n) { num.push_back(n); }
    void create()
    {
        num.push_back(0);
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
    }
    int find(const int &n) 
    { 
        return lower_bound(num.begin(),num.end(),n)-num.begin()+1;
    }
    int cal(const int &l,const int &r) { return num[r]-num[l-1]; }
    int size() { return num.size(); }
}fu;

struct segment
{
    int x,h,k;
    bool operator<(const segment &a)const { return x<a.x; }
};
vector<segment>seg;

struct fucalorse
{
    private:
        struct tree
        {
            int cnt,len;
        }op[MAX<<2];
        int sum(int l,int r,int id)
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
            void update(const int &i)
            {
                int l=1,r=fu.find(seg[i].h)-1;
                dfs(1,fu.size(),1,l,r,seg[i].k);
            }
            int get() { return op[1].len; }
}fufu;

int main()
{
    int s,h,e;
    while(scanf("%d%d%d",&s,&h,&e)==3)
    {
        seg.push_back({s,h,1});
        seg.push_back({e,h,-1});
        fu.add(h);
    }
    fu.create();
    sort(seg.begin(),seg.end());
    int pre=0;
    for(size_t i=0;i<seg.size();i++)
    {
        while(i+1<seg.size()&&seg[i].x==seg[i+1].x) fufu.update(i),i++;
        fufu.update(i);
        int now=fufu.get();
        if(now!=pre)
        {
            printf("%d %d ",seg[i].x,now);
            pre=now;
        }
    }
    return 0;
}