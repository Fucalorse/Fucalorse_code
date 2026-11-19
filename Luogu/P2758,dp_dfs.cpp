#include <bits/stdc++.h>
using namespace std;

const int MAX=2090;

char a[MAX],b[MAX];
int f[MAX][MAX];

int dfs(int i,int j)
{
    if(f[i][j]!=-1) return f[i][j];
    if(!i) return f[i][j]=j;
    if(!j) return f[i][j]=i;
    int p=a[i]==b[j]?0:1;
    int ans=min(min(dfs(i-1,j)+1,dfs(i,j-1)+1),dfs(i-1,j-1)+p);
    return f[i][j]=ans;
}

int main()
{
    cin>>(a+1)>>(b+1);
    int lena=strlen(a+1),lenb=strlen(b+1);
    memset(f,-1,sizeof f);
    cout<<dfs(lena,lenb)<<'\n';
    return 0;
}