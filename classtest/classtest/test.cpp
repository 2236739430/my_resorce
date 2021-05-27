#include "year.h"

void test()
{
	Date d1(2021,5,27);
	Date d2 = d1;
	Date d3; 
	d3 = d1;

	d3 += 3;
	d3 += 1;
	d3 += 31;

	if (d3 > d1)
	{
		cout << "d3 > d1" << endl;
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
	int res3 = d1 - d2;
	cout << "d3 - d1£º" << res1 << endl << "d1 - d3£º" << res2 << endl << "d1 - d2£º" << res3 << endl;

}

int main()
{
	test();

	return 0;
}