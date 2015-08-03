/* 
Given an array, consider it as a histogram and find the area of the largest rectangle in it.
2
6 2 5 4 5 1 6
1 2 3 4 5 6

Op
12
12 

*/

#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define MAX(a,b) a>b?a:b

int areaOfHistogram(int*, int);

int main()
{
        int iT, T, *tOut;
	int *a;
	int i, n;
	
        scanf("%d", &T);
	tOut = (int *) malloc(sizeof(int) * T);
	for(iT=0 ; iT < T ; iT++)
	{
/*		n=0;
		do {
			scanf("%d", &a[n++]);	
			ch = getchar();
		   }while(ch != '\n' && ch != EOF);
*/
		scanf("%d",&n);

		a =(int*) malloc (sizeof(int)*n);

		for(i=0;i<n;i++)
			scanf("%d", &a[i]);

	 	tOut[iT] = areaOfHistogram(a, n);;
        }

	for(i=0 ; i < T; i++)
		printf("%d\n", tOut[i]);

	return 0;

}

int areaOfHistogram(int a[], int n)
{
	int area = 0, left, right;
	int i, j, k;

	for(i=0; i< n; i++)
	{
		left = right = 0;
		for(j=i-1; j>=0; j--) {
			if(a[j]	>= a[i])
				left++;
			else
				break;
		}	
			
		for(k=i+1; k<n; k++) {
			if(a[k]	>= a[i])
				right++;
			else
				break;
		}

		area = MAX(area, a[i]*(left+right+1) );	
	}
	
	return area;
}
