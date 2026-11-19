#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=9;

LL a[MAX+10];

int main()
{
    for(int i=1;i<=MAX;i++)
        cin>>a[i];
    for(int i=1;i<MAX;i++)
    {
        if(i&1)
        {
            a[i+1]+=a[i]/2;
            a[i]%=2;
        }
        else
        {
            a[i+1]+=a[i]/3;
            a[i]%=3;
        }
    }
    for(int i=1;i<=MAX;i++)
    {
        if(i>1) cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}