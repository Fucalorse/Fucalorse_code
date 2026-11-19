#include <bits/stdc++.h>
using namespace std;

const int MAX=5090;

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

 struct segment
 {
    int x,h,k;
    bool operator<(const segment &a)const
    {
        if(x!=a.x) return x<a.x;
        else if(k!=a.k) return k>a.k;
        return h>a.h;
    }
 };
 vector<segment>seg;

 priority_queue<int>q;
 unordered_map<int,int>f;

 int main()
 {
    int s,h,e;
    while(scanf("%d%d%d",&s,&h,&e)==3)
    {
        seg.push_back({s,h,1});
        seg.push_back({e,h,-1});
    }
    sort(seg.begin(),seg.end());
    int preh=0,prex=0;
    for(size_t i=0;i<seg.size();i++)
    {
        if(seg[i].k==1) q.push(seg[i].h);
        else
        {
            f[seg[i].h]++;
            while(q.size()&&f[q.top()]>0)
            {
                f[q.top()]--;
                q.pop();
            }
        }
        int now=q.size()?q.top():0;
        if(seg[i].x!=prex&&now!=preh)
        {
            printf("%d %d ",seg[i].x,now);
            preh=now,prex=seg[i].x;
        }
    }
    return 0;
 }