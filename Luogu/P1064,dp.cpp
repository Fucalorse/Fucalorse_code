#include <bits/stdc++.h>
using namespace std;

const int MAX=4e4+90,LEN=100;

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
    int c,k,fa;
}op[LEN];

int w,n;
int f[MAX];
vector<int>p[LEN];
vector<pair<int,int>>num[LEN];

int main()
{
    w=read(),n=read();
    for(int i=1;i<=n;i++)
    {
        op[i]={read(),read(),read()};
        if(op[i].fa) p[op[i].fa].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(!op[i].fa) num[i].push_back({op[i].c,op[i].c*op[i].k});
        if(p[i].size())
        {
            int a=p[i][0];
            int aft=op[i].c*op[i].k+op[a].c*op[a].k;
            num[i].push_back({op[i].c+op[a].c,aft});
            if(p[i].size()==2)
            {
                int b=p[i][1];
                int sum=op[i].c*op[i].k+op[b].c*op[b].k;
                num[i].push_back({op[i].c+op[b].c,sum});
                num[i].push_back({op[i].c+op[a].c+op[b].c,sum+op[a].c*op[a].k});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(num[i].empty()) continue;
        for(int j=w;j>=0;j--)
            for(auto now:num[i])
            {
                int c=now.first,val=now.second;
                if(j>=c) f[j]=max(f[j],f[j-c]+val);
            }
    }
    printf("%d\n",f[w]);
    return 0;
}