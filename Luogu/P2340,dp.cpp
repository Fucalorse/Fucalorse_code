#include <bits/stdc++.h>
using namespace std;

const int MAX=450;

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

struct qwq
{
    int IQ,EQ;
    qwq(int a=INT_MIN/4,int b=INT_MIN/4):IQ(a),EQ(b){}
}f[MAX][2],op[MAX];

int n;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int a=read(),b=read();
        op[i]=qwq(a,b);
    }
    f[0][0]=f[0][1]={0,0};
    int maxn=-2e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int a=f[j][1].IQ+op[i].IQ,b=f[j][1].EQ+op[i].EQ;
            int c=f[j][0].IQ+op[i].IQ,d=f[j][0].EQ+op[i].EQ;
            // printf("%d %d %d %d\n",a,b,c,d);
            if(a+b>=f[i][0].EQ+f[i][0].IQ&&a>=0&&b>=0) f[i][0]={a,b};
            if(c+d>=f[i][0].EQ+f[i][0].IQ&&c>=0&&d>=0) f[i][0]={c,d};
            if(a+b>=f[i][1].EQ+f[i][1].IQ) f[i][1]={a,b};
            if(c+d>=f[i][1].EQ+f[i][1].IQ) f[i][1]={c,d};
        }
        maxn=max(maxn,f[i][0].EQ+f[i][0].IQ);
    }
    printf("%d\n",max(maxn,0));
    return 0;
}