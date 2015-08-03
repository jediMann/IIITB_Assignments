/* WAP to find the maximum number which can be formed from a given array of elements. Single digit elements only

IP
1 Number of testcase
4 Size of array
2 7 8 9 Array Elements

OP
9872 Maximum numbner formed using the array elements

*/

#include<stdio.h>

int main()
{
	int testcase,i,j,temp,k,size,A[100];
	scanf("%d",&testcase);
	for(i=0;i<testcase;i++)
	{
		scanf("%d",&size);
		for(j=0;j<size;j++)
			scanf("%d",&A[j]);		
		
		for(k=0;k<size-1;k++)
		{
			for(j=0;j<size-k-1;j++)
			{
				if(A[j]<A[j+1])
				{
					temp = A[j];
					A[j]=A[j+1];
					A[j+1]=temp;
				}
			}
		}
		for(k=0;k<size;k++)
			printf("%d",A[k]);
		printf("\n");
	}
	
	
	return 0;

}

