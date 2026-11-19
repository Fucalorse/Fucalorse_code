#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

struct qwq
{
    int len,h;
};

int n,m,ans=0;
int h[MAX];

void cal()
{
    stack<qwq>op;
    for(int i=1;i<=m;i++)
    {
        int now=0;
        while(op.size()&&h[i]<op.top().h)
        {
            now+=op.top().len;
            ans=max(ans,now*op.top().h*3);
            op.pop();
        }
        op.push({now+1,h[i]});
    }
    int now=0;
    while(op.size())
    {
        now+=op.top().len;
        ans=max(ans,now*op.top().h*3);
        op.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            h[j]++;
            if(c=='R') h[j]=0;
        }
        cal();
    }
    cout<<ans<<'\n';
    return 0;
}