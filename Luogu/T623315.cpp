#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

int t,n,x;
int op[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(int i=1;i<=n;i++)
            cin>>op[i];
        bool f=true;
        for(int i=2;i<=n;i++)
            if(op[i]-op[i-1]>1||op[i-1]-op[i]>x)
            {
                f=false;
                break;
            }
        cout<<(f?"Win":"Lose")<<'\n';
    }
    return 0;
}