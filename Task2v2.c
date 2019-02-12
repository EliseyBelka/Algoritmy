//2.Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
//Автор исполнения Алексей Белканов
#include <stdio.h>
#include <math.h>


int main(int argc, char*argv[])
{
	char str1[] = "GEEKBRAINS";
	char str2[] = "GEEKMINDS";
	int *resultt;
	resultt = (int*)malloc(sizeof(str2) * sizeof(str1) * sizeof(int));

	int i, j, counter = 0,pow=0;

	for (i = 0; i < sizeof(str2) - 1; i++)
	{
		for (j = i; j < sizeof(str1) - 1; j++)
		{
			if (str2[i] == str1[j] & pow==0)
			{
				counter++;
				pow = 1;
			}
			*(resultt + i * sizeof(str1) + j) = counter;
			*(resultt + j * sizeof(str1) + i) = counter;
		}
		pow = 0;
	}
	for (i = 0; i < sizeof(str1) - 1; i++)
	{
		for (j = 0; j < sizeof(str2) - 1; j++)
			printf("%3d ", *(resultt + i * sizeof(str1) + j));
		printf("\n");
	}
	getch();
	return 0;
}



/*USE
http://dfe.petrsu.ru/koi/posob/c/#g3.2 строки как тип данных
*/