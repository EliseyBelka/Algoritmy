//������ ������� ��������(�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����,
//����� ��� ����.//����� �������� �������
#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int Years,i;

	printf("Enter the age of the person from 1 year to 150 years: ");
	scanf("%d", &Years);
	//for (i = 1; i < 151; i++)
	//{
	//	Years = i;
		if (Years % 10 > 4 & Years % 10 < 10 | Years % 100 > 10 & Years % 100 < 15 | Years % 10 == 0)
			printf("person %d year(���) ", Years); else
		if (Years % 10 == 1)
			printf("person %d year(���) ", Years); else
		if (Years % 10 > 1 & Years % 10 < 5)
			printf("person %d years(����) ", Years);
		
	//	printf("\n");
	//}
	getch();
	return 0;
}