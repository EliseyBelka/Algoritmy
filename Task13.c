//�������� �������, ������������ ��������� ����� �� 1 �� 100.
//� �������������� ����������� ������� rand()
//��� ������������� ����������� ������� rand()
//����� �������� �������
#include <stdio.h>
#include <math.h>
#include <time.h>


int RandomNumber()
{
	srand(time(NULL));
	return rand()%10;
}

int MYRandomNumber()
{
	time_t sec;
   int ReturnNuberByTime;
   sec = time (NULL);
   ReturnNuberByTime = sec % 100+1;
   return ReturnNuberByTime;
}

int main(int argc, char*argv[])
{
	/*do
	{
		printf("1. A random number is generated with the aid of a standard function %d", RandomNumber());
		printf("2. A random number is generated without the aid of a standard function %d", MYRandomNumber());
		} while (getchar() != 'y');	*/
	printf("1. A random number is generated with the aid of a standard function %d", RandomNumber());
	printf("2. A random number is generated without the aid of a standard function %d", MYRandomNumber());
	getch();
}