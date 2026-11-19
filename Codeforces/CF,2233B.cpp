#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n;
int ans[MAX];

void update_2(int st,int num)
{
    ans[st]=ans[st+3]=ans[st+5]=ans[st+6]=num;
    ans[st+1]=ans[st+2]=ans[st+4]=ans[st+7]=num+1;
}

void update_3(int st,int num)
{
    ans[st]=ans[st+1]=ans[st+3]=ans[st+6]=num;
    ans[st+2]=ans[st+4]=ans[st+8]=ans[st+9]=num+1;
    ans[st+5]=ans[st+7]=ans[st+10]=ans[st+11]=num+2;
}

void solve()
{
    cin>>n;

    if(n&1)
    {
        update_3(1,1);
        for(int st=13,num=4;st<=n*4;st+=8,num+=2)
            update_2(st,num);
    }
    else
    {
        for(int st=1,num=1;st<=n*4;st+=8,num+=2)
            update_2(st,num);
    }

    for(int i=1;i<=n*4;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}