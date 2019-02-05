//����������� ������� ���������� ����� a � ������� b//����� �������� �������
#include <stdio.h>
#include <math.h>

//������� ������������
int SimplePow(int number , int degree)
{
	int  i, temp = 1;
	for (i = 1; i <= degree; i++)
	{
		temp *= number;
	}
	return temp;
}
//���������� � ������� ����� ��������
int exponentiation(int number, int degree)
{
	if (degree==0) return 1; 
	else
	return degree > 1 ? number * exponentiation(number, degree - 1) : number;
}
//���������� � ������� ����� �������� � �������� �������� ��� - ����
int FastPow(int number, int degree)
{
	if (!degree)
		return 1;  
	if (degree % 2)
		return number * FastPow(number*number, degree / 2);
	return FastPow(number*number, degree / 2);
}
int main(int argc, char*argv[])
{
	int number, degree;
	printf("Enter a number and to what extent to raise it ");
	scanf("%d%d", &number, &degree);
	//���������� ��� ��������
	printf("a. The number %d to the power of %d is %d",number,degree,SimplePow(number,degree));
	//���������� ���������
	printf("\nb. The number %d to the power of %d is %d", number, degree, exponentiation(number, degree));
	//���������� ��������� �������� ��������
	printf("\nc. The number %d to the power of %d is %d", number, degree, FastPow(number, degree));
	getch();
	return 0;
}