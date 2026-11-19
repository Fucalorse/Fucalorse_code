#include <bits/stdc++.h>
using namespace std;

const double inf=1e18;

struct qwq
{
    double x,y;
};

bool cmp1(const qwq &a,const qwq &b)
{
    return a.x<b.x;
}

bool cmp2(const qwq &a,const qwq &b)
{
    return a.y<b.y;
}

double cal(const qwq &a,const qwq &b)
{
    double d1=fabs(a.x-b.x),d2=fabs(a.y-b.y);
    return sqrt(pow(d1,2)+pow(d2,2));
}

int n;
vector<qwq>op;

double dfs(int l,int r)
{
    if(l>=r) return inf;
    if(l==r-1) return cal(op[l],op[r]);
    int mid=(l+r)>>1;
    double now=fmin(dfs(l,mid),dfs(mid+1,r));
    vector<qwq>rest;
    for(int i=l;i<=r;i++)
        if(fabs(op[i].x-op[mid].x)<now) rest.push_back(op[i]);
    sort(rest.begin(),rest.end(),cmp2);
    int len=rest.size();
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
        {
            if(rest[j].y-rest[i].y>=now) break;
            now=fmin(now,cal(rest[i],rest[j]));
        }
    return now;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    op.resize(n);
    for(int i=0;i<n;i++)
        cin>>op[i].x>>op[i].y;
    sort(op.begin(),op.end(),cmp1);
    printf("%.4lf\n",dfs(0,n));
    return 0;
}