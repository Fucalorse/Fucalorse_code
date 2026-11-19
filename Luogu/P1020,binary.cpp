#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

int n;
int num[MAX],op[MAX],qwq=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int val;
    while(cin>>val) num[++n]=val;
    for(int i=n;i>=1;i--)
    {
        int pos=upper_bound(op+1,op+qwq+1,num[i])-op;
        op[pos]=num[i];
        qwq=max(qwq,pos);
    }
    int ans=qwq;qwq=0;
    memset(op,0,sizeof op);
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(op+1,op+qwq+1,num[i])-op;
        op[pos]=num[i];
        qwq=max(qwq,pos);
    }
    cout<<ans<<'\n'<<qwq<<'\n';
    return 0;
}