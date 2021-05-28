#include "year.h"

void test()
{
	Date d1(2021,5,27);
	printf("d1(2021,5,27):\n");
	d1.print();
	Date d2 = d1;
	printf("d2 = d1:\n");
	d2.print();
	Date d3; 
	printf("d3:\n");
	d3.print();
	d3 = d1;
	printf("d3 = d1:\n");
	d3.print();
	Date d4;
	printf("d4:\n");
	d4.print();
	d4 = d3 - (-3);
	printf("d4 = d3 - (-3):\n");
	d4.print();
	d4 = d3 + (-3);
	printf("d4 = d3 + (-3):\n");
	d4.print();

	d3 += (-3);
	printf("d3 += (-3):\n");
	d3.print();
	d3 -= (-3);
	printf("d3 -= (-3):\n");
	d3.print();
	d3 += 1;
	printf("d3 += 1:\n");
	d3.print();
	d3 += 31;
	printf("d3 += 31:\n");
	d3.print();
	d3++;
	printf("d3++:\n");
	d3.print();
	++d3;
	printf("++d3:\n");
	d3.print();
	d4 = d3--;
	printf("d4 = d3--:\n");
	d4.print();
	printf("d3:\n");
	d3.print();
	d4 = --d3;
	printf("d4 = --d3:\n");
	d4.print();
	printf("d3:\n");
	d3.print();
	d4--;
	printf("d4:\n");
	d4.print();

	if (d3 > d1)
	{
		cout << "d3 > d1" << endl;
	}
	if (d3 >= d1)
	{
		cout << "d3 >= d1" << endl;
	}
	if (d1 < d3)
	{
		cout << "d1 < d3" << endl;
	}
	if (d1 <= d2)
	{
		cout << "d1 <= d2" << endl;
	}
	if (d3 != d1)
	{
		cout << "d3 != d1" << endl;
	}
	if (d2 == d1)
	{
		cout << "d2 == d1" << endl;
	}
	int res1 = d3 - d1;
	int res2 = d1 - d3;
	int res3 = d1 - d4;
	cout << "d3 - d1£º" << res1 << endl << "d1 - d3£º" << res2 << endl << "d1 - d4£º" << res3 << endl;

	cout << d1 << d2 << d3 << d4 << endl;

}

int main()
{
	test();

	return 0;
}