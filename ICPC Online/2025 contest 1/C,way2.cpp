#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct qwq
{
    int l,r;
    bool operator<(const qwq &a)const { return l<a.l; }
}op[MAX];

int T,n,m;

void solve()
{
    cin>>m>>n;

    for(int i=1;i<=m;i++)
        cin>>op[i].l>>op[i].r;
    
    sort(op+1,op+m+1);

    int pos=1,tot=1,del=0;
    priority_queue<int,vector<int>,greater<int>>q;
    while(1)
    {
        while(tot<=m&&pos>=op[tot].l)
        {
            q.push(op[tot].r);
            ++tot;
        }
        
        while(q.size()&&q.top()<=pos) q.pop();

        if(q.size())
        {
            ++pos;
            ++del;
            q.pop();
        }
        else
        {
            if(tot<=m)
            {
                pos=op[tot].l;
                q.push(op[tot].r);
                ++tot;
            }
            else break;
        }
    }

    cout<<n-del<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}