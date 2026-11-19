#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

int n,m;
int l[MAX],r[MAX],h[MAX];

void cal_l()
{
    stack<int>op;
    for(int i=m;i>=1;i--)
    {
        while(op.size()&&h[i]<h[op.top()])
        {
            l[op.top()]=i;
            op.pop();
        }
        op.push(i);
    }
    while(op.size())
    {
        l[op.top()]=0;
        op.pop();
    }
}

void cal_r()
{
    stack<int>op;
    for(int i=1;i<=m;i++)
    {
        while(op.size()&&h[i]<h[op.top()])
        {
            r[op.top()]=i;
            op.pop();
        }
        op.push(i);
    }
    while(op.size())
    {
        r[op.top()]=m+1;
        op.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            h[j]++;
            if(c=='R') h[j]=0;
        }
        cal_l(),cal_r();
        for(int j=1;j<=m;j++)
        {
            int now=(r[j]-l[j]-1)*h[j];
            ans=max(ans,now*3);
        }
    }
    cout<<ans<<'\n';
    return 0;
}