#include <stdio.h>

double average(int* salary, int salarySize)
{
	int max = 0;
	int min = *salary;
	int sum = 0;
	for (int i = 0; i<salarySize; i++)
	{
		min = min < salary[i] ? min : salary[i];
		max = max > salary[i] ? max : salary[i];
		sum += salary[i];
	}
	return (sum - (min + max)) / (salarySize - 2.0);

}

int main()
{
	int a[] = {100,200,600,300};
	printf("%f\n",average(a,4));

	return 0;
}