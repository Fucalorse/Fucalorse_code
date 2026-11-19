#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string a="",b="",s;

int main()
{
    cin>>a;
    while(cin>>s) b+=s;
    bool f=true,g=true;
    int num1=0,num2=0;
    for(auto c:a)
    {
        if(isdigit(c)) num1=num1*10+c-'0';
        else f=false;
    }
    for(auto c:b)
    {
        if(isdigit(c)) num2=num2*10+c-'0';
        else g=false;
    }
    if(f&&g&&num1>=1&&num1<=1000&&num2>=1&&num2<=1000) 
        printf("%d + %d = %d",num1,num2,num1+num2);
    else if(f&&num1>=1&&num1<=1000) printf("%d + ? = ?",num1);
    else if(g&&num2>=1&&num2<=1000) printf("? + %d = ?",num2);
    else printf("? + ? = ?");
    return 0;
}