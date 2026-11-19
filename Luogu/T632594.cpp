#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=1e5+90;

int n,m,k;
int c[MAX],num[MAX];
priority_queue<int,vector<int>,greater<int>>q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=2;i<=n;i++)
    {
        cin>>c[i];
        c[i]+=c[i-1];
    }
    for(int i=1;i<=n;i++)
        cin>>num[i];
    int total=0,maxn=0;
    for(int i=1;i<=n;i++)
    {
        q.push(num[i]);
        total+=num[i];
        while(q.size()&&(int)q.size()>k)
        {
            total-=q.top();
            q.pop();
        }
        int rest=m-c[i];
        if(rest<0) break;
        if(total>=rest)
        {
            maxn=max(maxn,rest);
            break;
        }
        else maxn=max(maxn,total);
    }
    cout<<maxn<<'\n';
    return 0;
}