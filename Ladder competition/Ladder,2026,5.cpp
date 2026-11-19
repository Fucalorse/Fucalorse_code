#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int x,n;

string change(const int &n)
{
    string ans=to_string(n);
    int size=ans.size();
    ans=string(4-size,'0')+ans;
    return ans;
}

bool dis(const string &s)
{
    set<char>st;
    for(auto &c:s)
        st.insert(c);
    return (int)st.size()==n;
}

int main()
{
    cin>>x>>n;
    for(int i=x;;i++)
    {
        string now=change(i);
        if(dis(now))
        {
            cout<<i-x<<' '<<now<<endl;
            break;
        }
    }
    return 0;
}