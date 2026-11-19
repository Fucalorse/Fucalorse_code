#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e4+90;

char a[MAX],b[MAX];
bool del[MAX];
unordered_set<char>f;

int main()
{
    scanf("%[^\n]%*c%[^\n]%*c",a+1,b+1);
    int lena=strlen(a+1),lenb=strlen(b+1);
    for(int i=1;i<=lenb;i++)
        f.insert(b[i]);
    for(int i=1;i<=lena;i++)
        if(f.count(a[i])) del[i]=true;
    for(int i=1;i<=lena;i++)
        if(!del[i]) printf("%c",a[i]);
    printf("\n");
    return 0;
}