#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+90,LEN=20;

int n,k;
int a[MAX],b[MAX];
bool f[1<<(LEN+1)],g[1<<(LEN+1)],h[1<<(LEN+1)];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    f[0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=(1<<LEN);j++)
        {
            if(f[j])
            {
                g[j^a[i]]=true;
                h[j^b[i]^a[i]]=true;
            }
        }
        for(int j=0;j<=(1<<LEN);j++)
            f[j]|=h[j]|g[j];
    }
    for(int i=(1<<LEN);i>=0;i--)
    {
        if(f[i])
        {
            k--;
            if(!k)
            {
                cout<<i<<'\n';
                exit(0);
            }
        }
    }
    cout<<-1<<'\n';
    return 0;
}