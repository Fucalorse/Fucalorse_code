#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

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
        int reflect(int pos) { return num[pos-1]; }
        int size() { return num.size(); }
}dis;

struct qwq
{
    int l,r,v;
    int id;
}op[MAX];

int n,q,m;
int a[MAX],cnt[MAX],ans[MAX];
set<int>num;
multiset<int>gap;

int cal(int x,int y)
{
    int now=((y-x)%m+m)%m;
    return !now?m:now;
}

void erase_num(int x)
{
    auto it=gap.find(x);
    gap.erase(it);
}

void add(int x)
{
    assert(x>=1);
    int now=dis.reflect(x);

    if(num.empty())
    {
        num.insert(now);
        ++cnt[x];
        gap.insert(m);
        return;
    }

    auto ed=num.end();--ed;
    if(!cnt[x])
    {
        auto r=num.lower_bound(now);
        if(r==num.end()) r=num.begin();
        auto l=r;

        l=r==num.begin()?ed:--l;

        erase_num(cal(*l,*r));
        gap.insert(cal(*l,now)),gap.insert(cal(now,*r));

        num.insert(now);
    }

    ++cnt[x];
}

void del(int x)
{
    assert(x>=1);
    int now=dis.reflect(x);

    --cnt[x];

    auto ed=num.end();--ed;
    if(!cnt[x])
    {
        auto mid=num.find(now);
        auto l=mid,r=mid;

        l=mid==num.begin()?ed:--l;
        r=mid==ed?num.begin():++r;

        erase_num(cal(*l,*mid)),erase_num(cal(*mid,*r));
        gap.insert(cal(*l,*r));

        num.erase(now);
    }
}

void solve()
{
    cin>>n>>q>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dis.add(a[i]);
    }
    for(int i=1;i<=q;i++)
    {
        cin>>op[i].l>>op[i].r>>op[i].v;
        op[i].id=i;
        dis.add(op[i].v);
    }

    int size=sqrt(n);
    sort(op+1,op+q+1,[&](const qwq &x,const qwq &y)
    {
        int bx=(x.l-1)/size+1,by=(y.l-1)/size+1;

        if(bx!=by) return bx<by;
        else
        {
            if(bx&1) return x.r<y.r;
            else return x.r>y.r;
        }
    });
    dis.create();

    for(int i=1;i<=n;i++)
        a[i]=dis.find(a[i]);
    for(int i=1;i<=q;i++)
        op[i].v=dis.find(op[i].v);

    int curL=1,curR=0;
    for(int i=1;i<=q;i++)
    {
        const auto &[l,r,v,id]=op[i];

        add(v);

        while(curL>l) add(a[--curL]);
        while(curR<r) add(a[++curR]);
        while(curL<l) del(a[curL++]);
        while(curR>r) del(a[curR--]);
        ans[id]=m-*gap.rbegin();

        del(v);
    }

    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}