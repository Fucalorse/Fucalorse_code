#include <bits/stdc++.h>
using namespace std;

const int MAX=100;

int n,depth;
int op[MAX];
string s;

bool dfs(int cnt,int pos,int sum)
{
    if(cnt>depth||sum+op[pos]>n) return false;
    if(cnt==depth)
    {
        int ans=0;
        for(size_t i=pos;i<s.size();i++)
            ans=ans*10+s[i]-'0';
        return ans+sum==n;
    }
    int num=0;
    for(size_t i=pos;i<s.size();i++)
    {
        int pre=num;
        num=num*10+s[i]-'0';
        if(pre==num) continue;
        if(num>n) return false;
        if(dfs(cnt+1,i+1,sum+num)) return true;
    }
    return false;
}

int main()
{
    cin>>s>>n;
    for(int i=(int)s.size()-1;i>=0;i--)
        op[i]=s[i]-'0'+op[i+1];
    while(depth<=(int)s.size()-1)
    {
        if(dfs(0,0,0))
        {
            printf("%d\n",depth);
            exit(0);
        }
        depth++;
    }
    printf("-1\n");
    return 0;
}