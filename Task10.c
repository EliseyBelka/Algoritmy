//10. ���� ����� ����� N(> 0).� ������� �������� ������� ������ � ������ ������� �� �������
//����������, ������� �� � ������ ����� N �������� �����.���� �������, �� ������� True, ���� ���
//� ������� False.//����� �������� �������
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int N,residue, counter=0;

	printf("Enter numbers N>0: ");
	scanf("%d", &N);
	while (N > 0)
	{
		residue = N%10;
		if (residue % 2 != 0) counter++;
		N /= 10;
		printf("%d%d ", N,counter);
	}
	if (counter > 0)			
		printf("\nTrue");
	else
		printf("\nFalse");
	getch();
}