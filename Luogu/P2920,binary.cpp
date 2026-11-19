#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

struct qwq
{
    int c,dl;
    bool operator<(const qwq &a)const
    {
        return dl<a.dl;
    }
}op[MAX];

int n;

bool dis(const int &mid)
{
    int total=mid;
    for(int i=1;i<=n;i++)
    {
        total+=op[i].c;
        if(total>op[i].dl) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>op[i].c>>op[i].dl;
    sort(op+1,op+n+1);
    int l=0,r=1e6+10;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(dis(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r<<'\n';
    return 0;
}