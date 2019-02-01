//С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех
//положительных четных чисел, оканчивающихся на 8.//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int N, sum=0, counter = 0;

	printf("Enter numbers\n(0 is the exit from the program): ");
	scanf("%d", &N);
	while (N != 0)
	{
		if ((N % 2 == 0) & (N > 0) & (N % 10 == 8))
		{
			sum += N;
			counter++;
		}
		printf("Enter numbers\n(0 is the exit from the program): ");
		scanf("%d", &N);
	}
	if (counter != 0)
	printf("The arithmetic mean of the numbers satisfying the condition is %d",(sum / counter));
	else
		printf("There were no numbers satisfying the condition.\nCalculation of arithmetic mean is not possible.");
	getch();
}