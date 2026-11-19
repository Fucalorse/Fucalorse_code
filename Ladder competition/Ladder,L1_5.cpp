#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1090,LEN=26;

char s[MAX];
int f[MAX],op[MAX];

int main()
{
    cin>>(s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
        f[s[i]-'a'+1]++;
    for(int i=1;i<=LEN;i++)
        cin>>op[i];
    for(int i=1;i<=LEN;i++)
    {
        if(i>1) cout<<' ';
        cout<<f[i];
    }
    cout<<endl;
    int ans=0;
    for(int i=1;i<=len;i++)
        ans+=f[i]*op[i];
    cout<<ans<<endl;
    return 0;
}