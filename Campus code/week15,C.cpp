#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int a[MAX];

int cmp(const void *a,const void *b)
{
    const int x=*(const int *)a;
    const int y=*(const int *)b;
    return x-y;
}

void swap(int *a,int *b)
{
    int p=*a;
    *a=*b;
    *b=p;
}

int main()
{
    int val;
    while(scanf("%d",&val)==1)
    {
        int qwq=0,num;
        a[++qwq]=val;
        while(scanf("%d",&num)==1)
        {
            if(num==-1) break;
            a[++qwq]=num;
        }

        int l=1,r=qwq,pos=a[qwq];
        while(l<r)
        {
            while(l<r&&a[l]<pos) l++;
            if(l<r) a[r]=a[l];
            while(l<r&&a[r]>=pos) r--;
            if(l<r) a[l]=a[r];
        }
        a[l]=pos;

        for(int i=1;i<=qwq;i++)
        {
            if(i>1) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}