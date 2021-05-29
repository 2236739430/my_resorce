#define _CRT_SECURE_NO_WARNINGS 1
#include <ostream>
#include <iostream>

using namespace std;

int main()
{
	char a[9];
	char b[9];
	int year, month, day;
	int year1, month1, day1;
	cin >> a >> b;
	sscanf(a,"%4d%2d%2d",&year,&month,&day);
	sscanf(a, "%4d%2d%2d", &year1, &month1, &day1);

	return 0;
}
