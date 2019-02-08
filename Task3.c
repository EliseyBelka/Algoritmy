#include <stdio.h>
#include <math.h>

//Вот функция но сложности с передачей массива в С++. Поэтому функцию не вызываю
//int BinSearch(int mass[], int num)
//{
//	int mid = 20 / 2;
//	int left = 0, right = 20;
//	while (num == mass[mid])
//		if (num < mass[mid]) mid = mid / 2; //else mid = mid + mid / 2;
//	if (num > mass[mid]) mid = mid + mid / 2;
//	return mid;
//}
int main(int argc, char*argv[])
{
	int result = 0;

	int mass[] = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,1,2,3,4,5,6,7,8,9,10 };
	//result = BinSearch(mass, 9);
	int mid = 20 / 2;
	int left = 0, right = 20;
	for (int i=0;i<20;i++)
		printf("%d ", mass[i]);
	//printf("\nIndex of what number should be displayed");
	int num=-100;
	//scanf("%d",&num);
	while (num != mass[mid])
	{
		
		if (num < mass[mid])
		{
			right = mid; 
			mid = (right - left) / 2;

		}
		if (num > mass[mid])
		{
			left = mid; 
			mid = mid + (right - left) / 2;

		} 
		if ((right - left)==1 & num != mass[mid])
		{
			result = -1;
			break;
		} 
		result = mid;
	}
	if (result == -1)	printf("\n-1"); else

	printf("\nItem in %d place ", result+1);
	getch();
	return 0;
}