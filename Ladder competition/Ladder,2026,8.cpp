#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1010;

int n;
string s;

int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        if(p==1)
        {
            string cur;
            cin>>cur;
            auto pos=s.find(cur);
            if(pos==string::npos) cout<<-1<<endl;
            else cout<<pos<<endl;
        }
        else if(p==2)
        {
            string cur,t;
            cin>>cur>>t;
            auto pos=s.find(cur);
            if(pos!=string::npos) s.replace(pos,cur.size(),t);
            cout<<s<<endl;
        }
        else
        {
            char a,b;
            string cur,now="";
            cin>>a>>b>>cur;
            for(size_t i=0;i<s.size()-1;i++)
            {
                now+=s[i];
                if(a==s[i]&&b==s[i+1]) now+=cur;
            }
            now+=s.back();
            s=now;
            cout<<s<<endl;
        }
    }
    return 0;
}