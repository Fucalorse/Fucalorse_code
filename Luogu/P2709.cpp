#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

struct qwq
{
    int l,r,id;
}op[MAX];

int n,m,k;
LL a[MAX],cnt[MAX],ans[MAX],total=0;

void add(int pos)
{
    total-=cnt[a[pos]]*cnt[a[pos]];
    cnt[a[pos]]++;
    total+=cnt[a[pos]]*cnt[a[pos]];
}

void del(int pos)
{
    total-=cnt[a[pos]]*cnt[a[pos]];
    cnt[a[pos]]--;
    total+=cnt[a[pos]]*cnt[a[pos]];
}

void solve()
{
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>op[i].l>>op[i].r;
        op[i].id=i;
    }

    int size=sqrt(n);
    sort(op+1,op+m+1,[&](const qwq &a,const qwq &b)
    {
        int bx=(a.l-1)/size+1,by=(b.l-1)/size+1;
        
        if(bx!=by) return bx<by;
        else
        {
            if(bx&1) return a.r<b.r;
            else return a.r>b.r;
        }
    });

    int curL=1,curR=0;
    for(int i=1;i<=m;i++)
    {
        const auto &[l,r,id]=op[i];
        while(curL>l) add(--curL);
        while(curR<r) add(++curR);
        while(curL<l) del(curL++);
        while(curR>r) del(curR--);
        ans[id]=total;
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}