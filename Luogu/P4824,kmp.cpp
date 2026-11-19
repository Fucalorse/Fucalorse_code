#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+90;

string s,word;
int op[MAX],st[MAX],id[MAX],qwq=0;

void create(const string &s)
{
    for(size_t i=1,j=0;i<s.size();i++)
    {
        while(j&&s[i]!=s[j]) j=op[j];
        if(s[i]==s[j]) j++;
        op[i+1]=j;
    }
}

int main()
{
    cin>>s>>word;
    create(word);
    for(size_t i=0,j=0;i<s.size();i++)
    {
        while(j&&s[i]!=word[j]) j=op[j];
        if(s[i]==word[j]) j++;
        st[++qwq]=j;
        id[qwq]=i;
        if(st[qwq]==(int)word.size())
        {
            qwq-=word.size();
            j=st[qwq];
        }
    }
    for(int i=1;i<=qwq;i++)
        cout<<s[id[i]];
    cout<<'\n';
    return 0;
}