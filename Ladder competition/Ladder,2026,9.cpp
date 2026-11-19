#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1010;

int n;
stack<int>num;
stack<char>op;

int cal(const int &a,const int &b,const char &c)
{
    if(c=='+') return a+b;
    else if(c=='-') return b-a;
    else if(c=='*') return a*b;
    else return b/a;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        num.push(a);
    }
    for(int i=1;i<n;i++)
    {
        char c;
        cin>>c;
        op.push(c);
    }
    for(int i=1;i<n;i++)
    {
        int a=num.top();num.pop();
        int b=num.top();num.pop();
        char c=op.top();op.pop();
        if(a==0&&c=='/')
        {
            printf("ERROR: %d/0\n",b);
            return 0;
        }
        num.push(cal(a,b,c));
    }
    cout<<num.top()<<endl;
    return 0;
}