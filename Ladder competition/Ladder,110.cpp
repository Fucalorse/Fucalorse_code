#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e6+90;

int n,m;
int a[MAX];
string s="";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i]+'a'-1;
    }
    while(m--)
    {
        int p;
        cin>>p;
        if(p==1)
        {
            int len,x;
            string now="",t="";
            cin>>len;
            for(int i=1;i<=len;i++)
            {
                cin>>a[i];
                now+='a'+a[i]-1;
            }
            cin>>x;
            for(int i=1;i<=x;i++)
            {
                cin>>a[i];
                t+='a'+a[i]-1;
            }
            auto pos=s.find(now);
            if(pos!=string::npos) s.replace(pos,len,t);
        }
        else if(p==2)
        {
            string now="";
            for(size_t i=1;i<s.size();i++)
            {
                int x=s[i-1]-'a'+1,y=s[i]-'a'+1;
                if((x+y)%2==0)
                {
                    char aft=(x+y)/2+'a'-1;
                    now+=s[i-1];
                    now+=aft;
                }
                else now+=s[i-1];
            }
            now+=s.back();
            // cout<<now<<endl;
            s=now;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            reverse(s.begin()+l-1,s.begin()+r);
        }
        // cout<<s<<endl;
    }
    for(size_t i=0;i<s.size();i++)
    {
        if(i) cout<<' ';
        cout<<s[i]-'a'+1;
    }
    return 0;
}