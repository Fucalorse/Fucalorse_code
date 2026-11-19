#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
        printf("%d\n",lcm(a,b));
    return 0;
}