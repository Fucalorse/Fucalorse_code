#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+90;

int n,k;
double v[MAX],w[MAX],op[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    double l=0,r=1e6+5;
    for(int s=1;s<=100;s++)
    {
        double mid=(l+r)/2;
        for(int i=1;i<=n;i++)
            op[i]=w[i]-v[i]*mid;
        sort(op+1,op+n+1,greater<double>());
        double ans=0;
        for(int i=1;i<=k;i++)
            ans+=op[i];
        if(ans>=0) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(2)<<l<<'\n';
    return 0;
}