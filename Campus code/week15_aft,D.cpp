#include <stdio.h>
#include <string.h>

#define MAXN 1000000

int a[MAXN], b[MAXN];
int cnt[10];

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void radix_pass(int n, int base)
{
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; i++)
    {
        int digit = (a[i] / base) % 10;
        cnt[digit]++;
    }

    for (int i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (a[i] / base) % 10;
        b[--cnt[digit]] = a[i];
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    int x;
    int n = 0;

    while (scanf("%d", &x) != EOF)
    {
        if (x == -1)
        {
            int base = 1;

            for (int i = 0; i < 3; i++)
            {
                radix_pass(n, base);
                print(n);
                base *= 10;
            }

            n = 0;
        }
        else
        {
            a[n++] = x;
        }
    }

    return 0;
}