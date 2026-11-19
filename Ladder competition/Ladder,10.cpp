#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=3;

int op[10];

int main()
{
    for(int i=1;i<=MAX;i++)
        cin>>op[i];
    sort(op+1,op+MAX+1);
    for(int i=1;i<=MAX;i++)
    {
        if(i>1) cout<<"->";
        cout<<op[i];
    }
    cout<<endl;
    return 0;
}