#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int NumOper = 0;
	int mass[20] = {1,2,3,4,5,6,7,8,9,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0};
	int right = 20;
	int left = 1;
	int sort;
	do {
		sort = 1;
		
		for (int j = left; j < right; j++)
		{
			NumOper += 1;
			//printf("%d > %d", mass[j - 1], mass[j]);
			if (mass[j - 1] > mass[j])
			{
				NumOper += 3;
				
				mass[j - 1] = mass[j -1] + mass[j];
				mass[j] = mass[j - 1] - mass[j];
				mass[j - 1] = mass[j - 1] - mass[j];
				sort = 0;
			}
		}
		right--;
		
		for (int i = right-1; i >= left; i--) 
		{
			NumOper += 1;
			//printf("%d > %d", mass[i], mass[i-1]);
			if (mass[i] < mass[i - 1]) 
			{
				
				NumOper += 3;
				mass[i] = mass[i - 1] + mass[i];
				mass[i - 1] = mass[i] - mass[i - 1];
				mass[i] = mass[i] - mass[i - 1];
				sort = 0;
			}
		}
		left++;
	} while (sort == 0);
for (int i = 0; i < 20; i++)
printf("%d ", mass[i]);
printf("\nThe number of operations: %d \n", NumOper);
getch();
return 0;
}