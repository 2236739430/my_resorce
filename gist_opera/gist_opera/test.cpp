#include <ostream>
#include <iostream>
using namespace std;

class A{
public:
	A()
		: a(1)
	{
		cout << "A()" << endl;//用于查看构造函数是否调用
	}

	~A()
	{
		cout << "~A()" << endl;//用于查看析构函数是否调用
	}
private:
	int a;
};

int main()
{
	A* aa = new A;//new + 类名
	delete aa;//delete + 实例化的对象名

	A* bb = new A[5];// new + 类名[数组大小]，开辟类数组
	delete[] bb;//delete[] + 实例化的对象名
	//释放数组时必须加[]，否则可能会出错

	
	return 0;
}