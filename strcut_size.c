#include<stdio.h>
struct node{
 char a:3;
};
main()
{
	printf("%d\n",(int)sizeof(struct node));
}
