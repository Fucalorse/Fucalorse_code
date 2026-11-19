#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=110,mod=11;
const int dx[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

int n;
string s;
bool g=true;
unordered_map<int,char>f;

void create()
{
    f[0]='1',f[1]='0',f[2]='X';
    f[3]='9',f[4]='8',f[5]='7';
    f[6]='6',f[7]='5',f[8]='4';
    f[9]='3',f[10]='2';
}

void peach()
{
    cin>>s;
    int now=0;
    for(int i=0;i<(int)s.size()-1;i++)
    {
        if(isdigit(s[i])) now=(now+(s[i]-'0')*dx[i])%mod;
        else
        {
            cout<<s<<endl,g=false;
            return;
        }
    }
    if(f[now]!=s.back()) cout<<s<<endl,g=false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    create();
    cin>>n;
    while(n--) peach();
    if(g) cout<<"All passed"<<endl;
    return 0;
}