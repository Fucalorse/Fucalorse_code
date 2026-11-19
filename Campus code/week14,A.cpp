#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 1e9
#define LL long long

struct ovo
{
    double x,y;
}op[MAX];
typedef struct ovo point;

int n;

void swap(double *a,double *b)
{
    double p=*a;
    *a=*b;
    *b=p;
}

bool dis(point a,point b,point c)
{
    point num1,num2;
    num1.x=a.x-b.x,num1.y=a.y-b.y;
    num2.x=c.x-b.x,num2.y=c.y-b.y;
    return num1.x==num2.x&&num1.y==num2.y;
}

double cal(point a,point b) { return sqrt(pow(fabs(a.x-b.x),2)+pow(fabs(a.y-b.y),2)); }

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%*c%lf",&op[i].x,&op[i].y);
    double ans=-1e18;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
            {
                double a=cal(op[i],op[j]),b=cal(op[i],op[k]),c=cal(op[j],op[k]);
                if(a>b) swap(&a,&b);
                if(a>c) swap(&a,&c);
                if(b>c) swap(&b,&c);
                if(dis(op[i],op[j],op[k])||pow(a,2)+pow(b,2)<=pow(c,2))
                {
                    double now=fmax(fmax(a,b),c);
                    ans=fmax(ans,now/2);
                }
                else
                {
                    double l=(a+b+c)/2;
                    double s=sqrt(l*(l-a)*(l-b)*(l-c));
                    double now=a*b*c/(4*s);
                    ans=fmax(ans,now);
                }
            }
    printf("以上%d个点的覆盖圆的最小半径为%.4lf\n",n,ans);
}

int main()
{
    solve();
    return 0;
}