#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include <iostream>
#define CompletedTask 3 
typedef int T;
int n; //размерость массива


//
void printMenu();
void task_1();
void task_2();
void task_3();
void PrintMatrix(char str[]);
void DFS(int k, int *YetSee, int *MatrixSM);


int main(int argc, const char * argv[])
{
	printMenu();
}
void printMenu() {
	int answer = 0;
	do {
		printf("Select task number:\n");
		printf("0. ExiT The MenU\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n1.Read the adjacency matrix;\n2.Deep recursion;\n3.Recursion in width;\n");
		scanf("%d", &answer);
		system("cls");
	} while (answer < 0 || answer > CompletedTask);
	switch (answer) {
	case 0:
		return;
	case 1:
		task_1();
		break;
	case 2:
		task_2();
		break;
	case 3:
		task_3();
		break;
	default:
		break;
	}
	printf("\n-=-=-=-=-= Press any key =-=-=-=-=-\n");
	getch();
	system("cls");
	printMenu();
}

void task_1()
{
	char str[] = "matrix.txt";
	PrintMatrix(str);
}
void task_2() {
	int i, j;
	int *MatrixSM;
	int YetSee[1000];//массив сохраняющий пройденные вершины

	FILE *MatrixFile; //файл для считывания данных
	MatrixFile = fopen("matrix.txt", "r"); //место считывания
	if (MatrixFile == NULL) printf("Erorr: File not found");
	else fscanf(MatrixFile, "%d", &n);

	for (int i = 0; i < n; i++)
		if (YetSee[i] = 0);

	MatrixSM = (int*)malloc(n*n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fscanf(MatrixFile, "%d", (MatrixSM + i * n + j));
			MatrixSM[i, j] = *(MatrixSM + i * n + j);
			//printf("%4d", MatrixSM[i,j]); 		
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++)
		if (YetSee[i] == 0)
			DFS(i, YetSee, MatrixSM);
	for (int i = 0; i < n; i++)
		printf("%4d", YetSee[i]); 
}

void task_3() {
	printf("Body task_3");
}

void PrintMatrix(char str[])
{
	int *matrix;
	int i, j;
	int n;
	FILE *MatrixFile;
	MatrixFile = fopen(str, "r");
	if (MatrixFile == NULL) printf("Erorr: File not found");
	else fscanf(MatrixFile, "%d", &n);
	printf("The result of reading the adjacency matrix by size: ");
	printf("%d\n", n);
	matrix = (int*)malloc(n*n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fscanf(MatrixFile, "%d", (matrix + i * n + j));
			printf("%4d", *(matrix + i * n + j));
		}
		printf("\n");
	}
	fclose(MatrixFile);
}

void DFS(int k, int *YetSee, int *MatrixSM)
{
	YetSee[k] = 2;
	for (int l = 0; l < n; l++)
	{
		if ((MatrixSM[k, l] == 1) & (YetSee[l] == 0))
		{
			//printf("%4d %4d %4d", k, l, MatrixSM[k, l]);
			DFS(l, YetSee, MatrixSM);
		}
	}
}