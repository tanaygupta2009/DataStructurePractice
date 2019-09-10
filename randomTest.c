#include<stdio.h>
#include<string.h>
char c[50];
char xy(char a[],int b)
{
    if(b>=strlen(a))
        return a;
    else if(a[b]=='p' && a[b+1]=='i'){
        c[b]='3';
        c[b+1]='.';
        c[b+2]='1';
        c[b+3]='4';
        return xy(a,b+4);}
    else 
    //if(a[b]!='i') 
    {
        c[b]=a[b];
        return xy(a,b+1);
    }
}

int main()
{
    char a[50];
    scanf("%s",&a);
    xy(a,0);
    printf("%s",c);
    return 0;
}