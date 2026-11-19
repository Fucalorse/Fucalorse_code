#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int a,b,n;

int main()
{
    cin>>a>>b>>n;
    int cnta=0,cntb=0;
    for(int i=1;i<=n;i++)
    {
        int u,x,v,y,now;
        cin>>u>>x>>v>>y;
        now=u+v;
        if(x==now&&y!=now) cnta++;
        else if(y==now&&x!=now) cntb++;
        if(cnta>a||cntb>b) break;
    }
    if(cnta>a) cout<<"A"<<endl<<cntb<<endl;
    else cout<<"B"<<endl<<cnta<<endl;
    return 0;
}