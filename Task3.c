//Написать программу обмена значениями двух целочисленных переменных :
//a.с использованием третьей переменной;
//b. *без использования третьей переменной.//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int first, second, temp;

	printf("Enter the two numbers you want to swap: ");
	scanf("%d %d", &first, &second);
	printf("OPTION 1 (using an additional variable):");
	temp = first;
	first = second;
	second = temp;
	printf("\nAfter OPTION 1 first = %d second = second %d", first ,second);
	printf("\nOPTION 2 (using arithmetic has changed back):");
	second = first + second;
	first = second - first;;
	second = second - first;
	printf("\nAfter OPTION 2 first = %d second = second %d", first, second);
	getch();
	return 0;
}