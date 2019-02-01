//Написать функцию нахождения максимального из трех чисел.//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>
///////
int max(int num1, int num2, int num3)
{
	if ((num1>num2) & (num1>num3))
		return num1;
		else 
		if (num2 > num3)
			return num2;
			else
			return num3;
}

int main(int argc, char*argv[])
{
	int first,second,third;

	printf("Enter three numbers: ");
	scanf("%d%d%d", &first, &second, &third);
		printf("Maximum of three numbers %d %d %d it is %d", first, second, third,max(first, second, third));
	getch();
}