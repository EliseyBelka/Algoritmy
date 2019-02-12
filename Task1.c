//*���������� ��������� � �������������.����������� ������ ������� � ������������ 
//� ���������� ���������� ���������. (!!!������ ���������� � ����� �� ����� �����)
//��������, �����:
//3 3
//1 1 1
//0 1 0
//0 1 0
//����� ��������� ������� ������� ��������

#define _CRT_SECURE_NO_WARNINGS //������������� � ����� � ��������� �� ��������� ����� ����� �� HDD  
#include <stdio.h>
#include <math.h>
#include <io.h>
#include <malloc.h>

int main(int argc, char*argv[])
{
	int *map;  // ��������� �� ������ �����
	int *way;  // ��������� �� ������ ����
	int i, j;
	int rows, columns;
	
	FILE *CardFile; //���������� ���������� ���� ����
	CardFile=fopen("card.txt", "r");//�������� ����� �� r ������ w ������ � ����������
	if (CardFile == NULL) printf("Erorr: File not found"); //�������� ������� ����� � ����� �����
	else fscanf(CardFile, "%d%d", &rows, &columns);
	
	map = (int*)malloc(rows*columns * sizeof(int));//��������� ������ ��� ������
	// ���������� ������� ����� ���������� �� �����
	for (i = 0; i < rows; i++)  // ���� �� �������
	{
		for (j = 0; j < columns; j++)  // ���� �� ��������
		{
			fscanf(CardFile, "%d", (map + i * columns + j)); //����������� ���������� ��������
		}
	}

	way = (int*)malloc(rows*columns * sizeof(int)); //��������� ������ ��� ������
	//��������� ������� � ������ �����
	{
		for (j = 0; j < columns; j++)
		if (*(map + 0 * columns + j) == 0) 
			*(way + 0 * columns + j) = 0;  //��������� ������ ������
		else *(way + 0 * columns + j) = 1; //��������� ������ ������
		for (i = 1; i < rows; i++)
		{
			if (*(map + i * columns + 0) == 0)
				*(way + i * columns + 0) = 0;  //��������� ������� �������
			else *(way + i * columns + 0) = 1; //��������� ������� �������
			//����� ����� ������� � ������ �����
			for (j = 1; j < columns; j++)
				if (*(map + i * columns + j) == 1)
					*(way + i * columns + j) = *(way + i * columns + (j - 1)) + *(way + (i - 1) * columns + j);
				else
					if (*(map + i * columns + j) == 0)
						*(way + i * columns + j) = 0;
		}
	}
	//����� ������� ������ ���� � ������ �����
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
			printf("%4d", *(way + i * columns + j));
		printf("\n");
	}
		free(map,way);//������������ ����������� �������������� ������
	fclose(CardFile); //�������� �����
	getch();
	return 0;
}



/*USE Resource
https://younglinux.info/c/fopen //������ ��� ������ � �������
https://prog-cpp.ru/c-alloc/ // ������ ������ � ���������� ������ ��� ������������ ������
*/