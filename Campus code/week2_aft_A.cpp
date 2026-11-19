#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int n;

void peach(int cnt)
{
    if(cnt>n) return;
    int now;
    scanf("%d",&now);
    peach(cnt+1);
    printf("%d ",now);
}

int main()
{
    scanf("%d",&n);
    peach(1);
    return 0;
}