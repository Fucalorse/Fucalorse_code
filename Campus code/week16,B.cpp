#include <stdio.h>
#include <string.h>

#define MAXN 100005

char s[MAXN];
char tmp[20];

void erase_range(int l, int r, int *len)
{
    // 删除 [l, r]
    memmove(s + l, s + r + 1, (*len) - r);
    *len -= (r - l + 1);
}

void check_eliminate(int pos, int *len)
{
    while (*len > 0)
    {
        if (pos < 0) pos = 0;
        if (pos >= *len) pos = *len - 1;

        int l = pos;
        int r = pos;
        char c = s[pos];

        while (l - 1 >= 0 && s[l - 1] == c)
            l--;

        while (r + 1 < *len && s[r + 1] == c)
            r++;

        if (r - l + 1 >= 3)
        {
            erase_range(l, r, len);

            // 删除后，新的可能合并位置就在 l 附近
            pos = l;

            if (pos >= *len)
                pos = *len - 1;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    scanf("%s", s);

    int len = strlen(s);
    int pos;

    while (scanf("%s %d", tmp, &pos) == 2)
    {
        char ch = tmp[0];

        // 在 pos 前插入 ch
        memmove(s + pos + 1, s + pos, len - pos + 1);
        s[pos] = ch;
        len++;

        check_eliminate(pos, &len);

        if (len == 0)
        {
            printf("You win!\n");
            break;
        }
        else
        {
            printf("%s\n\n", s);
        }
    }

    return 0;
}