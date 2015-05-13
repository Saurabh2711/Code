#include<stdio.h>
#include<stdlib.h>
main()
{
int a,b,d,e;
char c;
char *str="12 + 23 - 56";
printf("%s\n",str);
char *ptr=str+6;
printf("%s\n",ptr);
sscanf(str,"%d %c %d %c %d %c",&a,&c,&b,&c,&d,&c);
printf("%d\n%c\n%d\n%c\n%d\n%d\n",a,c,b,c,d,e);
}
