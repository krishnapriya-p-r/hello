#include <stdio.h>

int main(){

	int arr[100],pos,value,size;
	
	printf("enter the size of the array:");
	scanf("%d",&size);

	printf("enter the elements of the array:");
	for(int i=0;i<size;i++){
	scanf("%d",&arr[i]);
}
	printf("the new array:");
	for(int i=0;i<size;i++){
	printf("%d",arr[i]);
}

	printf("enter the position to be inserted:");
	scanf("%d",&pos);

	printf("enter the value to be inserted:");
	scanf("%d",&value);

	for (int i=size-1;i>=pos-1;i--){
	arr[i+1]=arr[i];
}


	arr[pos - 1]=value;
	size++;

	printf("the inserted array:");
	for(int i=0;i<size;i++){
	printf("%d",arr[i]);
}
	
return 0;


}
