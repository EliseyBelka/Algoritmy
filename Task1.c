#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int NumOperA=0;
	int NumOperB= 0;
	const n = 20;
	int massA[20] = {1,2,3,4,5,6,7,8,9,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0};
	int massB[20] = { 1,2,3,4,5,6,7,8,9,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0 }; 
#pragma region ������ � �� ���������������� �����������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++) 
		{
			NumOperA += 1;//��������� �������� 1 ��������
			if (massA[j] > massA[j + 1])
			{
				int b = massA[j]; 
				massA[j] = massA[j + 1]; 
				massA[j + 1] = b; 
				NumOperA += 3;//����� �������� 3 ��������
			}
		}
	}
	printf("\nNumber of operations on non-optimized sorting %d \n", NumOperA);
	for (int i = 0; i < n; i++)
	printf("%d ", massA[i]);


#pragma endregion
#pragma region ������ � ���������������� �����������
	
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n - (i + 1); j++) {
			NumOperB += 1;//��������� �������� 1 ��������
			if (massB[j] > massB[j + 1]) {
				flag = 0;
				NumOperB += 1;//���������� �������� 1 ��������
				massB[j]= massB[j + 1]+ massB[j];
				massB[j + 1] = massB[j] - massB[j + 1];
				massB[j] = massB[j] - massB[j + 1];
				NumOperB += 3;//����� �������� 3 ��������
			}
		}
		if (flag=0) {
			break;
		}
	}
	printf("\nNumber of operations on optimized sorting %d \n", NumOperB);
	for (int i = 0; i < n; i++)
		printf("%d ", massB[i]);

#pragma endregion

	printf("\nThe number of operations decreased by: %d \n", NumOperA-NumOperB);
	getch();
	return 0;
}