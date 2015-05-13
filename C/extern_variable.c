#include<stdio.h>
void fun();

main()
{
    extern int c;
    c++;
    printf("%d\n",c);
    fun();
    printf("%d\n",c);
    fun();
    printf("%d\n",c);
}
void fun()
{
    extern int c;
    c++;
    c++;
    printf("Inside the function with c value %d\n",c);
}
int c=45;