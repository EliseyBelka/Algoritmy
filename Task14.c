//����������� �����.����������� ����� ���������� �����������, ���� ��� ����� ���������
//������ ������ ��������.��������, 25 \ :sup: `2` = 625. �������� ���������, ������� ������
//����������� ����� N � ������� �� ����� ��� ����������� �����, �� ������������� N.
//����� �������� �������
#include <stdio.h>
#include <math.h>

void print(int lowN, int N)
{
	int i;
	for (i = lowN; i <= N; i++)
	{
		if (((i*i) %  (lowN * 10)) == i)
		{
			printf("%d ", i);
		}
	}
}
int main(int argc, char*argv[])
{
	
	int N=0,i;
	int check=1,counter = 0, temp = 0;;

	printf("Enter the number N ");
	scanf("%d", &N);
	temp = N;
	while (temp > 0)
	{
		temp /= 10;
		counter++;
	}
	printf("%d",counter);
	while (check < pow(10, counter))
	{
		print(check,N);
			check *= 10;
	}
getch();
}