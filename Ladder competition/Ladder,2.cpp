#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n;
char c;
vector<string>op;

int main()
{
    cin>>n>>c;
    int h=sqrt((double)(n+1)/2);
    int rest=n-2*h*h+1;
    for(int i=1;i<=h;i++)
    {
        string now=string(i-1,' ')+string(2*(h-i)+1,c);
        op.push_back(now);
        cout<<now<<endl;
    }
    for(int i=op.size()-2;i>=0;i--)
        cout<<op[i]<<endl;
    cout<<rest<<endl;
    return 0;
}