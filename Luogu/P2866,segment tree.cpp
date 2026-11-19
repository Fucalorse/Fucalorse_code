#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=8e4+90;

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
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
    }
    int find(const int &n)
    {
        return lower_bound(num.begin(),num.end(),n)-num.begin()+1;
    }
    int size() { return num.size(); }
}fu;

struct fucalorse
{
    private:
        struct tree
        {
            int cnt;
            bool lazy;
        }op[MAX<<2];
        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl].cnt=0;
                op[hl].lazy=true;
                op[hr].cnt=0;
                op[hr].lazy=true;
                op[id].lazy=false;
            }
        }
        void dfs(int l,int r,int id,const int &x)
        {
            if(x<l) return;
            if(r<x)
            {
                op[id].cnt=0;
                op[id].lazy=true;
                return;
            }
            if(l==r)
            {
                op[id].cnt=1;
                return;
            }
            down(id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            dfs(l,mid,hl,x);
            dfs(mid+1,r,hr,x);
            op[id].cnt=op[hl].cnt+op[hr].cnt;
        }
    public:
        void update(const int &n)
        {
            int x=fu.find(n);
            dfs(1,fu.size(),1,x);
        }
        int query() { return op[1].cnt; }
}fufu;

int n;
vector<int>op;

int main()
{
    n=read();
    for(int i=0;i<n;i++)
    {
        op.push_back(read());
        fu.add(op[i]);
    }
    fu.create();
    LL total=0;
    for(auto i:op)
    {
        fufu.update(i);
        total+=fufu.query()-1;
    }
    printf("%lld\n",total);
    return 0;
}