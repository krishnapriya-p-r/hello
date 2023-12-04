#include<stdio.h>
int main()
{
	int i,limit,sum=0;
	printf("Enter the limit:");
	scanf("%d",&limit);
	for(i=0;i<limit;i++)
	{
		if(i%2!=0)
		{
			sum=sum+i;
		}
	}
	printf("The total sum of odd values are:%d\n",sum);
	return 0;
}
