//Реализовать функцию перевода чисел из десятичной системы в двоичную, используя
//рекурсию.//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

void TenTwo(int num10)
{
	if (num10 >= 2)
		TenTwo(num10 / 2);
	printf("%d", num10 % 2);
}

int main(int argc, char*argv[])
{
	int Number10;
	printf("Enter a number in decimal notation. ");
	scanf("%d", &Number10);
	printf("The number in the binary system has the form: ");
	TenTwo(Number10);
	getch();
	return 0;
}