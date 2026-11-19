#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

int w,n;
int f[MAX];

int change()
{
    char c;
    int a,b;
    cin>>a>>c>>b;
    return a*60+b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int a=change(),b=change();
    w=b-a;
    cin>>n;
    for(int s=1;s<=n;s++)
    {
        int t,val,p;
        cin>>t>>val>>p;
        if(!p)
        {
            for(int i=t;i<=w;i++)
                f[i]=max(f[i],f[i-t]+val);
        }
        else
        {
            for(int i=w;i>=t;i--)
                for(int k=1;k<=p;k++)
                    if(i-k*t>=0) f[i]=max(f[i],f[i-k*t]+val*k);
        }
    }
    cout<<f[w]<<'\n';
    return 0;
}