#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=86400;
const int dx[]={3600,60,1};

int n;
char s[20];
int f[MAX+5];

int cal()
{
    int len=strlen(s+1),ans=0,num=0;
    for(int p=0,i=1;i<=len;i++)
    {
        if(isdigit(s[i])) num=num*10+s[i]-'0';
        else
        {
            ans+=num*dx[p];
            num=0;
            p++;
        }
    }
    return ans+num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>(s+1);
        l=cal();
        cin>>(s+1);
        r=cal();
        // cout<<l<<' '<<r<<endl;
        f[l]++,f[r+1]--;
    }
    int ans=max(f[0],1);
    for(int i=1;i<=MAX;i++)
    {
        f[i]+=f[i-1];
        ans=max(f[i],ans);
    }
    cout<<ans<<endl;
}