//Написать программу нахождения корней заданного квадратного уравнения.
//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	double A, B, C;
	int D;

	printf("Enter the values A,B,C for quadratic equation:\nAx^2+Bx+C=0:");
	scanf("%lf %lf %lf", &A, &B, &C);
	D = round(pow(B,2) - 4 * A * C);
	printf("%d", D);
	
	if (A == 0 & B != 0) 
		printf("One root x1= %lf", (-C) / (B));
	else
	if (A == 0 & B == 0)
		printf("No real roots");
	else

	{
		if (D < 0) printf("No real roots");
		if (D == 0) printf("One root x1= %lf", (-B) / (2 * A));
		if (D > 0) printf("The first root x1= %lf\nThe second root x2= %lf", ((-B + sqrt(D)) / (2 * A)), ((-B - sqrt(D)) / (2 * A)));
	}
	getch();
	return 0;
}