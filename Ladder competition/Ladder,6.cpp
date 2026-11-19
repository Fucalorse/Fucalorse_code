#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int n;

int main()
{
    cin>>n;
    int st=0,maxn=0;
    for(int i=2;i<=sqrt(n);i++)
    {
        LL total=1;
        for(int j=i;;j++)
        {
            total*=j;
            if(n%total!=0) break;
            if(j-i+1>maxn) maxn=j-i+1,st=i;
        }
    }
    if(!maxn)
    {
        cout<<1<<endl<<n<<endl;
        return 0;
    }
    cout<<maxn<<endl;
    for(int i=0;i<maxn;i++)
    {
        if(i) cout<<"*";
        cout<<st+i;
    }
    cout<<endl;
    return 0;
}