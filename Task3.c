#include <stdio.h>
#include <math.h>
int main(int argc, char*argv[])
{
	int tree[20];
	int i=0, j = 0, Sum = 0;
	printf("Number 3 is converted to number 20 by two commands: +1 and *2 = ");
	tree[20] = 1;
	for (i = 19; i>=3; i--)
	{
		if ((i * 2) <= 20)
		{
			tree[i] = tree[i + 1] + tree[i * 2];
		//	printf("\n%d %d %d %d", i, tree[i], tree[i + 1], tree[i * 2]);
		}
			 else
		{
			tree[i] = tree[i + 1];
		//	printf("\n%d %d %d", i, tree[i], tree[i + 1]);
		}
	}
	printf("%d", tree[3]);
	getch();
	return 0;
}