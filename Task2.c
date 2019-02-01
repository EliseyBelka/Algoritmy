//Найти максимальное из четырех чисел.Массивы не использовать.//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	double first, second, third, fourth;

	printf("Enter four numbers to find the maximum\n(double numbers are filled with \".\"): ");
	scanf("%lf %lf %lf %lf", &first, &second, &third, &fourth);
	if ((first > second)&(first > third)&(first > fourth))
		printf("Maximum of four: %lf", first); 
	else
			if ((second > third)&(second > fourth))
				printf("Maximum of four: %lf", second); 
			else
					if (third > fourth)
						printf("Maximum of four: %lf", third);
					else
						printf("Maximum of four: %lf", fourth);

	getch();
	return 0;
}