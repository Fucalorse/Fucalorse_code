#include <bits/stdc++.h>
using namespace std;

const int MAX=45,LEN=1e5+90,inf=0x3f3f3f3f;

int n,minn=inf;
int f[MAX][LEN];
string s;

void dfs(int pos,int cnt,int sum)
{
    if(sum>n||cnt>=minn||cnt>=f[pos][sum]) return;
    f[pos][sum]=cnt;
    if(pos==(int)s.size())
    {
        if(sum==n) minn=min(minn,cnt);
        return;
    }
    int num=0;
    for(size_t i=pos;i<s.size();i++)
    {
        num=num*10+s[i]-'0';
        if(num>n) return;
        dfs(i+1,cnt+1,sum+num);
    }
}

int main()
{
    cin>>s>>n;
    memset(f,0x3f,sizeof f);
    dfs(0,0,0);
    printf("%d\n",minn==inf?-1:minn-1);
    return 0;
}