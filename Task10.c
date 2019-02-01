//10. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления
//определить, имеются ли в записи числа N нечетные цифры.Если имеются, то вывести True, если нет
//— вывести False.//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int N,residue, counter=0;

	printf("Enter numbers N>0: ");
	scanf("%d", &N);
	while (N > 0)
	{
		residue = N%10;
		if (residue % 2 != 0) counter++;
		N /= 10;
		printf("%d%d ", N,counter);
	}
	if (counter > 0)			
		printf("\nTrue");
	else
		printf("\nFalse");
	getch();
}