#include <stdio.h>


int findsum(int num1,int num2)
{
	return num1+num2;
}
int main()
{
	int a,b,sum;
	

	printf("enter two numbers");
	scanf("%d %d",&a,&b);
	sum=findsum(a,b);
	printf("%d",sum);
}
