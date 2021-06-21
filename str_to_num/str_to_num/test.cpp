#include <ostream>
#include <iostream>
#include <string>
using namespace std;

	int StrToInt(string str) {
		if (str.size() == 0 || str.size() == 1)
		{
			return 0;
		}
		reverse(str.begin(), str.end());
		cout << str << endl;
		string::iterator it = str.begin();
		int sum = 0;
		int y = 0;
		while (it != str.end() - 1)
		{
			if (*it < '1' || *it > '9')
			{
				return 0;
			}
			sum += ((*it) - '0') * pow(10, y);
			y++;
			it++;
		}
		if (*(it) == '-')
		{
			sum *= -1;
		}
		else if (*(it) == '+')
		{
			sum *= 1;
		}
		else
		{
			return 0;
		}
		cout << sum << endl;
		return sum;
	}


int main()
{  
	string aa("-123456");
	cout << aa << endl;
	int sum = 0;
	sum = 	StrToInt(aa);


	return 0;
}