#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

int n;
double a[MAX],b[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",a+i,b+i);
    sort(a,a+n,greater<double>());
    sort(b,b+n,greater<double>());
    int i=0,j=0;
    double suma=0,sumb=0,ans=0;
    while(i<n&&j<n)
    {
        if(suma>sumb) sumb+=b[j++];
        else suma+=a[i++];
        ans=fmax(ans,fmin(suma-i-j,sumb-i-j));
    }
    while(i<n)
    {
        suma+=a[i++];
        ans=fmax(ans,fmin(suma-i-j,sumb-i-j));
    }
    while(j<n)
    {
        sumb+=b[j++];
        ans=fmax(ans,fmin(suma-i-j,sumb-i-j));
    }
    printf("%.4lf\n",ans);
    return 0;
}