//���� ����� ������������� ����� N � K.��������� ������ �������� �������� � ���������, �����
//������� �� ������� ������ N �� K, � ����� ������� �� ����� �������.//����� �������� �������
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int N, K, counter=0;

	printf("Enter two numbers N>0 and K>0:");
	scanf("%d%d", &N, &K);
	while (N >= K)
	{
		counter++;
		N -= K;
	} 
	printf("The quotient of N by K = %d", counter);
	printf("\nRemainder of division N by K = %d", N);

	getch();
}