//������ a � b � ������� �������� � ���� ����� �� a �� b.//����� �������� �������
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int a,b,temp;
	
	printf("Enter two numbers [a-b]: ");
	scanf("%d%d", &a, &b);
	printf("Squares of numbers from [a-b]:");
	temp=a;
	while (a != b+1)
	{
		printf("%d ",a*a);
		a++;
	}
	printf("\nCubes of numbers from [a-b]:");
	a = temp;
	while (a != b + 1)
	{
		printf("%d ", a*a*a);
		a++;
	}
	getch();
}