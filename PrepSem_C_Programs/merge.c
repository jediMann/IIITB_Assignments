#include<stdio.h>
#include<stdlib.h>
#define start 0
#define end 1
#define MAX 1000

typedef struct interval{
	int val;
	int type;
}INTERVAL;

int int_compare(const void *a, const void *b)
{
	const INTERVAL *x = (INTERVAL *) a;
	const INTERVAL *y = (INTERVAL *) b;

	return x->val - y->val;
}

int main()
{
        int T, size;
	int i, j, k, temp, unique;
	INTERVAL *node = NULL;
	int open;

        scanf("%d", &T);	
	while(T--)
	{

	        scanf("%d", &size);
		if(size>0)
		{
			node = (INTERVAL *) malloc(sizeof(INTERVAL) * size * 2);

			for(i=0; i<size*2; i=i+2){
				scanf("%d%d", &(node[i].val),&(node[i+1].val) );
				node[i].type = start;
				node[i+1].type = end;
			}

			qsort(node, size*2, sizeof(INTERVAL), int_compare);

			/*
			for(i=0; i<size*2; i = i+2){
				printf("\n%d %d\n", node[i].val,node[i].type );
				printf("%d %d\n", node[i+1].val,node[i+1].type );
			}
			*/

			open = 1;
			printf("(%d,",node[0].val);
		
			for(i=1; i<size*2; i++){

				if( node[i].type == start)
					open++;
				else if( node[i].type == end)
					open--;
				//printf("\nafter parsing %d, open : %d\n", node[i].val, open);

				if(!open)
				{
					if(i+1<size*2)
					{
						if( node[i].val == node[i+1].val)
							continue;
					}		
					printf("%d)",node[i].val);
	
					if(i+1<size*2)
						printf(" (%d,",node[i+1].val);
				}
			}	

			if(node)	
			{
				free(node);
			}
		
			printf("\n");
		}
		
        }
	return 0;
}
