#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e6+90,inf=2e9;

LL read()
{
    LL ans=0,f=1;
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
    LL val,add;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int n,k;
char s[MAX];
LL num[MAX];
priority_queue<qwq>q;

int main()
{
    n=read(),k=read();
    scanf(" %s",s+1);
    for(int i=1;i<=n;i++)
        num[i]=read();
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') sum+=num[i];
        else if(s[i]=='1')
        {
            if(i==1||s[i-1]=='1') q.push({(num[i]+1)/2,0});
            else
            {
                LL maxn=max((num[i]+sum+1)/2,sum);
                q.push({maxn,sum+(num[i]+1)/2-maxn});
            }
            sum=0;
        }
    }
    if(s[n]=='0') q.push({sum,0});
    LL ans=0;
    for(int i=1;i<=k&&q.size();i++)
    {
        qwq cur=q.top();q.pop();
        ans+=cur.val;
        if(cur.add) q.push({cur.add,0});
    }
    printf("%lld\n",ans);
    return 0;
}
// 7 3
// 0010011
// 2 2 6 8 6 3 10