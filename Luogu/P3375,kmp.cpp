#include <bits/stdc++.h>
using namespace std;

struct fucalorse
{
    vector<int>op;
    void create(const string &s)
    {
        int len=s.size();
        op.resize(len+1,0);
        for(int i=1,j=0;i<len;i++)
        {
            while(j&&s[i]!=s[j]) j=op[j];
            if(s[i]==s[j]) j++;
            op[i+1]=j;
        }
    }
    void find(const string &s1,const string &s2)
    {
        if(s2.size()>s1.size())
        {
            cout<<endl;
            return;
        }
        create(s2);
        for(size_t i=0,j=0;i<s1.size();i++)
        {
            while(j&&s1[i]!=s2[j]) j=op[j];
            if(s1[i]==s2[j]) j++;
            if(j==s2.size())
            {
                cout<<i-j+2<<endl;
                j=op[j];
            }
        }
    }
    void print()
    {
        for(size_t i=1;i<op.size();i++)
            cout<<op[i]<<' ';
    }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    string s1,s2;
    cin>>s1>>s2;
    fu.find(s1,s2);
    fu.print();
    return 0;
}