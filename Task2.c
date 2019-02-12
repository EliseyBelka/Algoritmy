//2.–ешить задачу о нахождении длины максимальной последовательности с помощью матрицы.
//јвтор исполнени€ јлексей Ѕелканов
#include <stdio.h>
#include <math.h>


int main(int argc, char*argv[])
{

	char str1[] = "GEEKBRAINS";
	char str2[] = "GEEKMINDS";
	int result[11][11];//не хватка времени на выполнение его в виде динамического массива как в Task1
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
			result[i][j] = counter;
			result[j][i] = counter;
		}
		pow = 0;
	}
	for (i = 0; i < sizeof(str1) - 1; i++)
	{
		for (j = 0; j < sizeof(str2) - 1; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
		
	getch();
	return 0;
}



/*USE
http://dfe.petrsu.ru/koi/posob/c/#g3.2 строки как тип данных
*/