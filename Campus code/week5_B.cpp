#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int len,qwq,tot;
double num[MAX];
char s[MAX],op[MAX];

int get(char c)
{
    if(c=='+'||c=='-') return 1;
    else if(c=='*'||c=='/') return 2;
    return 0;
}

double cal(double a,double b,char c)
{
    if(c=='+') return a+b;
    else if(c=='-') return a-b;
    else if(c=='*') return a*b;
    else return a/b;
}

int main()
{
    while(scanf(" %s",s+1)==1)
    {
        len=strlen(s+1);
        qwq=tot=0;
        for(int i=1;i<=len;i++)
        {
            if(isdigit(s[i]))
            {
                double now=0;
                while(i<=len&&isdigit(s[i]))
                {
                    now=now*10+s[i]-'0';
                    i++;
                }
                num[++qwq]=now;
                i--;
            }
            else if(s[i]=='(') op[++tot]=s[i];
            else if(s[i]==')')
            {
                while(tot&&op[tot]!='(')
                {
                    char c=op[tot--];
                    double b=num[qwq--];
                    double a=num[qwq--];
                    num[++qwq]=cal(a,b,c);
                }
                if(tot) tot--;
            }
            else
            {
                if(s[i]=='-'&&(i==1||s[i-1]=='('))
                {
                    double now=0;
                    i++;
                    while(i<=len&&isdigit(s[i]))
                    {
                        now=now*10+s[i]-'0';
                        i++;
                    }
                    num[++qwq]=-now;
                    i--;
                    continue;
                }
                while(tot&&get(op[tot])>=get(s[i]))
                {
                    char c=op[tot--];
                    double b=num[qwq--];
                    double a=num[qwq--];
                    num[++qwq]=cal(a,b,c);
                }
                op[++tot]=s[i];
            }
        }
        while(tot)
        {
            char c=op[tot--];
            double b=num[qwq--];
            double a=num[qwq--];
            num[++qwq]=cal(a,b,c);            
        }
        printf("%.3lf\n",num[qwq]);
    }
    return 0;
}