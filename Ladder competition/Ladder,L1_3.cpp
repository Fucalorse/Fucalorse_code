#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int a,s,b;

int main()
{
    cin>>a>>s>>b;
    if(s==1&&a>35&&b>=33) cout<<"Bu Tie"<<endl<<a<<endl;
    else if(a>35&&b>=33&&s==0) cout<<"Shi Nei"<<endl<<a<<endl;
    else if(s==1&&(a<=35||b<33)) cout<<"Bu Re"<<endl<<b<<endl;
    else if(s==0&&(a<=35||b<33)) cout<<"Shu Shi"<<endl<<b<<endl;
    return 0;
}