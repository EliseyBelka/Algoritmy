//С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).Требуется
//определить, относятся ли к поля к одному цвету или нет.
//Автор Белканов Алексей
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int x1, x2, y1, y2;
	char check2, check1;

	printf("Enter the coordinates of the first field: ");
	scanf("%d%d", &x1, &y1);
	printf("Enter the coordinates of the second field: ");
	scanf("%d%d", &x2, &y2);
	if ((x1 % 2 == 0 & y1 % 2 == 0) | (x1 % 2 != 0 & y1 % 2 != 0))
	{
		//printf("Field color black ");
		check1 = "b";
	}
	else
	{
		//printf("Field color white ");
		check1 = "w";
	}

	if ((x2 % 2 == 0 & y2 % 2 == 0) | (x2 % 2 != 0 & y2 % 2 != 0))
	{
	//	printf("Field color black ");
		check2 = "b";
	}
	else
	{
		//printf("Field color white ");
		check2 = "w";
	}
	if (check1 == check2)
		printf("Fields of the same color ");
	else
		printf("Fields of different colors ");

	getch();
}