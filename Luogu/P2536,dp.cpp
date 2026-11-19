#include <bits/stdc++.h>
using namespace std;

const int MAX=550,LEN=1090;

char st[LEN],s[LEN];
int n;
bool f[510][1010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>(st+1)>>n;
    int cnt=0,lenl=strlen(st+1);
    for(int k=1;k<=n;k++)
    {
        cin>>(s+1);
        memset(f,false,sizeof f);
        f[0][0]=true;
        for(int i=1;st[i]=='*';i++) f[i][0]=true;
        int lenr=strlen(s+1);
        for(int i=1;i<=lenl;i++)
            for(int j=1;j<=lenr;j++)
            {
                if(st[i]=='?') f[i][j]=f[i-1][j-1];
                else if(st[i]=='*') f[i][j]=f[i-1][j]||f[i-1][j-1]||f[i][j-1];
                else f[i][j]=f[i-1][j-1]&&st[i]==s[j];
            }
        if(f[lenl][lenr]) cnt++;
    }
    cout<<n-cnt<<'\n';
    return 0;
}