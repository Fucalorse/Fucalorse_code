#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+90;

int t,n;
int f[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=n;i++)
            cin>>f[i];
        bool g=false;
        for(int i=0;i<=n;i++)
        {
            if(i==0||i==n) f[i]--;
            else f[i]-=2;
            if(f[i]<0)
            {
                g=true;
                break;
            }
        }
        if(g)
        {
            cout<<"Impossible"<<'\n';
            continue;
        }
        g=false;
        string s="";
        for(int i=1;i<=n;i++)
        {
            s+='R';
            while(f[i]>0&&f[i-1]>0)
            {
                s+="LR";
                f[i]--;
                f[i-1]--;
            }
        }
        for(int i=0;i<=n;i++)
            if(f[i]>0)
            {
                g=true;
                break;
            }
        if(g)
        {
            cout<<"Impossible"<<'\n';
            continue;
        }
        s+=string(n,'L');
        cout<<s<<'\n';
    }
    return 0;
}