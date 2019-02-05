//Реализовать функцию возведения числа a в степень b//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

//простое перемножение
int SimplePow(int number , int degree)
{
	int  i, temp = 1;
	for (i = 1; i <= degree; i++)
	{
		temp *= number;
	}
	return temp;
}
//возведение в степень через рекурсию
int exponentiation(int number, int degree)
{
	if (degree==0) return 1; 
	else
	return degree > 1 ? number * exponentiation(number, degree - 1) : number;
}
//возведение в степень через рекурсию и свойство степеней Аль - Каши
int FastPow(int number, int degree)
{
	if (!degree)
		return 1;  
	if (degree % 2)
		return number * FastPow(number*number, degree / 2);
	return FastPow(number*number, degree / 2);
}
int main(int argc, char*argv[])
{
	int number, degree;
	printf("Enter a number and to what extent to raise it ");
	scanf("%d%d", &number, &degree);
	//Возведение без рекурсии
	printf("a. The number %d to the power of %d is %d",number,degree,SimplePow(number,degree));
	//Возведение рекурсиия
	printf("\nb. The number %d to the power of %d is %d", number, degree, exponentiation(number, degree));
	//Возведение рекурсиия свойство степеней
	printf("\nc. The number %d to the power of %d is %d", number, degree, FastPow(number, degree));
	getch();
	return 0;
}