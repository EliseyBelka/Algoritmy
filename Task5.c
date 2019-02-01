//С клавиатуры вводится номер месяца.Требуется определить, к какому времени года он относится
//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int Number;

	printf("Enter the month number: ");
	scanf("%d", &Number);
	if (Number==1 | Number ==2 | Number ==12)
		printf("Time of year - Winter");
	else
		if (Number > 2 & Number <6)
			printf("Time of year - Spring");
		else
			if (Number > 5 & Number < 9)
				printf("Time of year - Summer");
			else
				if (Number > 8 & Number < 12)
					printf("Time of year - Autumn");
				else
					printf("Does not exist on the earth the time of year.\nThere is 12 months.");
	getch();
	return 0;
}