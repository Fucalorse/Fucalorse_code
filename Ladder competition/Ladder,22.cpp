#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1090;

int n,a,b;
int op[MAX];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i];
        if(op[i]&1) a++;
        else b++;
    }
    cout<<a<<' '<<b<<endl;
    return 0;
}