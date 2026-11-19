#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=4e5+90,LEN=19,inf=2e9;

struct interval
{
    int l,r;
    bool operator<(const interval &a)const { return l<a.l; }
}num[MAX],q[MAX];

int t,n,m;
int f[MAX][LEN+10],cnt[MAX][LEN+10];
vector<int>pos;

struct discrete
{
    void clear() { pos.clear(); }
    void add(const int &n) { pos.push_back(n); }
    void create()
    {
        sort(pos.begin(),pos.end());
        pos.erase(unique(pos.begin(),pos.end()),pos.end());
    }
    int find(const int &x)
    {
        return lower_bound(pos.begin(),pos.end(),x)-pos.begin();
    }
}fu;

void initial()
{
    fu.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i].l>>num[i].r;
        fu.add(num[i].l),fu.add(num[i].r);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].l>>q[i].r;
        fu.add(q[i].l),fu.add(q[i].r);
    }
    fu.create();
    sort(num+1,num+n+1);
    int minn=inf;
    for(int i=pos.size()-1,j=n;i>=0;i--)
    {
        while(j>=1&&num[j].l>=pos[i])
        {
            minn=min(minn,num[j].r);
            j--;
        }
        if(minn==inf) f[i][0]=inf,cnt[i][0]=0;
        else
        {
            int x=fu.find(minn);
            f[i][0]=x,cnt[i][0]=1;
        }
    }
    int len=pos.size();
    for(int k=1;k<=LEN;k++)
        for(int i=0;i<len;i++)
        {
            if(f[i][k-1]!=inf&&f[f[i][k-1]][k-1]!=inf)
            {
                f[i][k]=f[f[i][k-1]][k-1];
                cnt[i][k]=cnt[i][k-1]+cnt[f[i][k-1]][k-1];
            }
            else
            {
                f[i][k]=inf;
                cnt[i][k]=cnt[i][k-1];
            }
        }
}

int query(const int &st,const int &ed)
{
    int l=fu.find(st),ans=0;
    if(l==(int)pos.size()||pos[l]>ed) return 0;
    for(int k=LEN;k>=0;k--)
        if(f[l][k]!=inf&&pos[f[l][k]]<=ed)
        {
            ans+=cnt[l][k];
            l=f[l][k];
        }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        initial();
        for(int i=1;i<=m;i++)
            cout<<query(q[i].l,q[i].r)<<endl;
    }
    return 0;
}