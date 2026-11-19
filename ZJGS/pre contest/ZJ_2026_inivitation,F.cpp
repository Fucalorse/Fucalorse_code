#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int inf=2e9;

string s;
queue<int>q[4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    for(int i=1;i<=3;i++)
    {
        cin>>s;
        for(auto &c:s) q[i].push(c-'0');
    }
    while(q[1].size()||q[2].size()||q[3].size())
    {
        int a=q[1].size()?q[1].front():inf;
        int b=q[2].size()?q[2].front():inf;
        int c=q[3].size()?q[3].front():inf;
        if(a==b)
        {
            q[1].pop(),q[2].pop();
            cout<<a;
        }
        else if(a==c)
        {
            q[1].pop(),q[3].pop();
            cout<<a;
        }
        else
        {
            q[2].pop(),q[3].pop();
            cout<<b;
        }
    }
    cout<<endl;
    return 0;
}