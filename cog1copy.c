#include<stdio.h>
#include<string.h>

void compress(char *str,int len, int act);
char str[100];
int length;

int main()
{
scanf("%s",str);
length=strlen(str);
//compression
//we need a recursive sol so that 
//cases like abbbccc or abcccc are also taken care of
compress(str,0,0);
printf("%s",str);
//scanf("%d",&length);

}

//recursive code - prefered
void compress(char *str,int len, int act) {

if(len<length) {
    int k=len;
    int count=0;
    int c, n;
    while(str[k]==str[len]){
        len++; count++;
    }
    n = 0;
    c=count;
    do {
        c /= 10;
        n++;
    } while (c != 0);
    
    compress(str,len,act+n+1);
    
    str[act]=str[k];
    if(k+count==length) 
       str[act+n+1]='\0';
    for(c=0;c<n;c++) {
        str[act+n-c]=(count%10)+48;
        count=count/10;
    }

}
return;
}
