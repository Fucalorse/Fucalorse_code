#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

int t,n;
int op[MAX];
queue<int>q[4];

void initial()
{
    for(int i=0;i<=3;i++)
        while(q[i].size()) q[i].pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        initial();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>op[i];
            q[op[i]&3].push(i);
        }
        int maxn=max(q[1].size(),q[3].size()),minn=min(q[1].size(),q[3].size());
        if(maxn-minn>(int)(q[2].size()<<1))
        {
            cout<<"-1\n";
            continue;
        }
        for(int i=1;i<=minn;i++)
        {
            int a=q[3].front();q[3].pop();
            int b=q[1].front();q[1].pop();
            cout<<a<<' '<<b<<' ';
        }
        while(q[1].size())
        {
            int a=q[1].front();q[1].pop();
            int b=q[1].front();q[1].pop();
            int c=q[2].front();q[2].pop();
            cout<<c<<' '<<a<<' '<<b<<' ';
        }
        while(q[3].size())
        {
            int a=q[3].front();q[3].pop();
            int b=q[3].front();q[3].pop();
            int c=q[2].front();q[2].pop();
            cout<<a<<' '<<b<<' '<<c<<' ';            
        }
        while(q[2].size())
        {
            int a=q[2].front();q[2].pop();
            int b=q[2].front();q[2].pop();
            cout<<a<<' '<<b<<' ';
        }
        while(q[0].size())
        {
            int cur=q[0].front();q[0].pop();
            cout<<cur<<' ';
        }
        cout<<'\n';
    }
    return 0;
}