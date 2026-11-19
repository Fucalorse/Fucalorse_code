#include <bits/stdc++.h>
using namespace std;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

struct qwq
{
    int x,y;
};

bool cmp1(const qwq &a,const qwq &b)
{
    return a.x<b.x;
}

bool cmp2(const qwq &a,const qwq &b)
{
    return a.y<b.y;
}

int l,w,n;
vector<qwq>op;

int main()
{
    l=read(),w=read(),n=read();
    for(int i=0;i<n;i++)
        op.push_back({read(),read()});
    op.push_back({0,w});
    op.push_back({0,0});
    op.push_back({l,0});
    op.push_back({l,w});
    sort(op.begin(),op.end(),cmp1);
    int ans=0,len=op.size();
    for(int i=0;i<len;i++)
    {
        int x1=op[i].x,y1=0,y2=w;
        for(int j=i+1;j<len;j++)
        {
            ans=max(ans,(op[j].x-x1)*(y2-y1));
            if(op[j].y>op[i].y) y2=min(y2,op[j].y);
            else y1=max(y1,op[j].y);
        }
    }
    for(int i=len-1;i>=0;i--)
    {
        int x1=op[i].x,y1=0,y2=w;
        for(int j=i-1;j>=0;j--)
        {
            ans=max(ans,(x1-op[j].x)*(y2-y2));
            if(op[j].y>op[i].y) y2=min(y2,op[j].y);
            else y1=max(y1,op[j].y);
        }
    }
    sort(op.begin(),op.end(),cmp2);
    for(int i=1;i<len;i++)
        ans=max(ans,l*(op[i].y-op[i-1].y));
    printf("%d\n",ans);
    return 0;
}