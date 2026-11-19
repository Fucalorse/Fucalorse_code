#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90,LEN=205;

vector<string>word;
bool f[LEN][MAX],ans[MAX];

struct fucalorse
{
    void create(const string &s,vector<int>&op)
    {
        op.resize(s.size()+1,0);
        for(size_t i=1,j=0;i<s.size();i++)
        {
            while(j&&s[i]!=s[j]) j=op[j];
            if(s[i]==s[j]) j++;
            op[i+1]=j;
        }
    }
    void find(const string &s1,const int &p)
    {
        const string &s2=word[p];
        if(s2.size()>s1.size()) return;
        vector<int>op;
        create(s2,op);
        for(size_t i=0,j=0;i<s1.size();i++)
        {
            while(j&&s1[i]!=s2[j]) j=op[j];
            if(s1[i]==s2[j]) j++;
            if(j==s2.size())
            {
                f[p][i+1]=true;
                j=op[j];
            }
        }
    }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    string s="",p;
    while(cin>>p)
    {
        if(p==".") break;
        word.push_back(p);
    }
    while(cin>>p) s+=p;
    for(size_t i=0;i<word.size();i++)
        fu.find(s,i);
    ans[0]=true;
    int maxn=0;
    for(size_t i=0;i<s.size();i++)
    {
        int x=i+1;
        for(size_t j=0;j<word.size();j++)
        {
            if(word[j].size()>i+1) continue;
            if(f[j][x]&&ans[x-word[j].size()])
            {
                ans[x]=true;
                maxn=x;
                break;
            }
        }
    }
    cout<<maxn<<'\n';
    return 0;
}