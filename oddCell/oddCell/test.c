#include <stdio.h>

int oddCells(int m, int n, int (*indices)[2], int indicesSize){
	int a[2][3];
	memset(a,0,sizeof(int)*6);
	int rol = 0;
	int col = 0;
	for (int i = 0; i < indicesSize; i++)
	{
		rol = *(*(indices + i) + 0);
		col = *(*(indices + i) + 1);
		for (int j = 0; j < n; j++)
		{
			a[rol][j] += 1;
		}
		for (int j = 0; j < m; j++)
		{
			a[j][col] += 1;
		}
	}
	int num = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] % 2 == 1)
			{
				num++;
			}
		}
	}

	return num;
}

int main()
{
	int a[2][3] = { {0,1}, {1,1} };
	int b = oddCells(2,3,a,2);

	return 0;
}