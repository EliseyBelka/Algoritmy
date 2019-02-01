//Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h*h); где
//m - масса тела в килограммах, h - рост в метрах.//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	double Growth, Weight, IMB;

	printf("Enter weight in kilograms ");
	scanf("%lf", &Weight);
	printf("Enter height in meters ");
	scanf("%lf", &Growth);
	printf("Your IMB = %1.2f", Weight / (Growth*Growth));


	getch();
	return 0;
}