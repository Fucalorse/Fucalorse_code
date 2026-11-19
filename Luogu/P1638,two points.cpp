#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+90;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

const int mod=1<<14,p=0x45d9f3b;
struct HASH
{
    struct qwq
    {
        int key,val;
        qwq *next;
        qwq(int k):key(k),val(0),next(nullptr){}
    };
    qwq *num[mod];
    vector<qwq*>loc;
    HASH() { memset(num,0,sizeof num); }
    ~HASH()
    {
        for(auto i:loc)
            delete(i);
    }
    int cal(int n)
    {
        n=((n>>16)^n)*p;
        n=((n>>16)^n)*p;
        n=(n>>16)^n;
        return n&(mod-1);
    }
    int &operator[](int n)
    {
        int now=cal(n);
        qwq *cur=num[now];
        while(cur)
        {
            if(cur->key==n) return cur->val;
            cur=cur->next;
        }
        qwq *aft=new qwq(n);
        loc.push_back(aft);
        aft->next=num[now];
        num[now]=aft;
        return aft->val;
    }
    bool count(int n)
    {
        int now=cal(n);
        qwq *cur=num[now];
        while(cur)
        {
            if(cur->key==n) return true;
            cur=cur->next;
        }
        return false;
    }
};

int n,m;
int num[MAX]={0};
HASH f;

int main()
{
    n=read(),m=read();
    int total=0,minn=1e9;
    pair<int,int>ans;
    for(int l=1,r=1;r<=n;r++)
    {
        num[r]=read();
        if(++f[num[r]]==1) total++;
        while(l<r&&f[num[l]]>1)
        {
            f[num[l]]--;
            l++;
        }
        if(total==m&&r-l+1<minn) 
        {
            minn=r-l+1;
            ans={l,r};
        } 
    }
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}