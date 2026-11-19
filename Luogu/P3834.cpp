#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct discrete
{
    private:
        vector<int>num;
    public:
        void add(int n) { num.push_back(n); }
        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }
        int find(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }
        int cal(int pos) { return num[pos-1]; }
        int size() { return num.size(); }
}fu;

int n,m;
int a[MAX];

struct peach
{
    private:
        struct tree
        {
            int l,r,cnt;
        }op[MAX<<5];
        int root[MAX],qwq=0;

        void create(int &pos,int l,int r)
        {
            pos=++qwq;
            if(l==r) return;
            int mid=(l+r)>>1;
            create(op[pos].l,l,mid);
            create(op[pos].r,mid+1,r);
        }
        int dfs(int pre,int l,int r,const int &x)
        {
            int now=++qwq;
            op[now]=op[pre];
            op[now].cnt++;
            if(l==r) return now;
            int mid=(l+r)>>1;
            if(x<=mid) op[now].l=dfs(op[pre].l,l,mid,x);
            else op[now].r=dfs(op[pre].r,mid+1,r,x);
            return now;
        }
        int query(int pre,int now,int l,int r,int k)
        {
            int mid=(l+r)>>1,num=op[op[now].l].cnt-op[op[pre].l].cnt;
            if(l==r) return l;
            if(num>=k) return query(op[pre].l,op[now].l,l,mid,k);
            else return query(op[pre].r,op[now].r,mid+1,r,k-num);
        }
    public:
        void debut() { create(root[0],1,fu.size()); }
        void update(int now,int x) { root[now]=dfs(root[now-1],1,fu.size(),x); }
        int get(int l,int r,int k) { return query(root[l-1],root[r],1,fu.size(),k); }
}fufu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fu.add(a[i]);
    }
    fu.create();
    fufu.debut();
    for(int i=1;i<=n;i++)
    {
        int pos=fu.find(a[i]);
        fufu.update(i,pos);
    }
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int pos=fufu.get(l,r,k);
        cout<<fu.cal(pos)<<endl;
    }
    return 0;
}