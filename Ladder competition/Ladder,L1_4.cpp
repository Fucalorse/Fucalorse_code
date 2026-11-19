#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int LEN=31;

int x;

int main()
{
    cin>>x;
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            cout<<(1<<i)<<endl;
            break;
        }
    return 0;
}