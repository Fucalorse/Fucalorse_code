#include <bits/stdc++.h>
using namespace std;

const int MAX=5090;

int n;
bool op[MAX]={false};

int main()
{
    cin>>n;
    int pre=0;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        int now;
        if(c=='F') now=1;
        else now=0;
        op[i]=pre^now;
        pre=now;
    }
    int minn=1e9,ans;
    for(int k=1;k<=n;k++)
    {
        int sum=0,cnt=0;
        bool f[MAX],flag=true;
        memcpy(f,op,sizeof op);
        for(int i=1;i<=n-k+1;i++)
        {
            sum^=f[i];
            if(!sum)
            {
                f[i]^=1;
                f[i+k]^=1;
                sum^=1;
                cnt++;
            }
        }
        for(int i=n-k+2;i<=n;i++)
        {
            sum^=f[i];
            if(!sum) 
            {
                flag=false;
                break;
            }
        }
        if(flag&&cnt<minn) minn=cnt,ans=k; 
    }
    printf("%d %d\n",ans,minn);
    return 0;
}