//*Количество маршрутов с препятствиями.Реализовать чтение массива с препятствием 
//и нахождение количество маршрутов. (!!!чтение осуществил с файла из корня папки)
//Например, карта:
//3 3
//1 1 1
//0 1 0
//0 1 0
//АВТОР исполения решения Алексей Белканов

#define _CRT_SECURE_NO_WARNINGS //необходимость в связи с проверкой на осутствие файла карты на HDD  
#include <stdio.h>
#include <math.h>
#include <io.h>
#include <malloc.h>

int main(int argc, char*argv[])
{
	int *map;  // указатель на массив карты
	int *way;  // указатель на массив пути
	int i, j;
	int rows, columns;
	
	FILE *CardFile; //объявление переменной типа файл
	CardFile=fopen("card.txt", "r");//открытие файла на r чтение w запись а добавление
	if (CardFile == NULL) printf("Erorr: File not found"); //проверка наличия файла в корне папки
	else fscanf(CardFile, "%d%d", &rows, &columns);
	
	map = (int*)malloc(rows*columns * sizeof(int));//Выделение памяти под массив
	// Замолнение массива карты элементами из файла
	for (i = 0; i < rows; i++)  // цикл по строкам
	{
		for (j = 0; j < columns; j++)  // цикл по столбцам
		{
			fscanf(CardFile, "%d", (map + i * columns + j)); //считываение очередного элемента
		}
	}

	way = (int*)malloc(rows*columns * sizeof(int)); //Выделение памяти под массив
	//обработка массива с учетом карты
	{
		for (j = 0; j < columns; j++)
		if (*(map + 0 * columns + j) == 0) 
			*(way + 0 * columns + j) = 0;  //обработка первой строки
		else *(way + 0 * columns + j) = 1; //обработка первой строки
		for (i = 1; i < rows; i++)
		{
			if (*(map + i * columns + 0) == 0)
				*(way + i * columns + 0) = 0;  //обработка перовго столбца
			else *(way + i * columns + 0) = 1; //обработка перовго столбца
			//обход всего массива с учетом карты
			for (j = 1; j < columns; j++)
				if (*(map + i * columns + j) == 1)
					*(way + i * columns + j) = *(way + i * columns + (j - 1)) + *(way + (i - 1) * columns + j);
				else
					if (*(map + i * columns + j) == 0)
						*(way + i * columns + j) = 0;
		}
	}
	//вывод массива обхода поля с учетом карты
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
			printf("%4d", *(way + i * columns + j));
		printf("\n");
	}
		free(map,way);//освобождение динамически расперделенной памяти
	fclose(CardFile); //закрытие файла
	getch();
	return 0;
}



/*USE Resource
https://younglinux.info/c/fopen //теория для работы с файлами
https://prog-cpp.ru/c-alloc/ // теория работа с выделением памяти под динамический массив
*/