#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int dfs(int m,int n)
{
    // printf("%d %d\n",m,n);
    if(!m) return n+1;
    else if(m&&!n) return dfs(m-1,1);
    else if(m&&n) return dfs(m-1,dfs(m,n-1));
    // return 0;
}

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d",dfs(m,n));
    return 0;
}