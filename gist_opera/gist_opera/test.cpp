#include <ostream>
#include <iostream>
using namespace std;

class A{
public:
	A()
		: a(1)
	{
		cout << "A()" << endl;//���ڲ鿴���캯���Ƿ����
	}

	~A()
	{
		cout << "~A()" << endl;//���ڲ鿴���������Ƿ����
	}
private:
	int a;
};

int main()
{
	A* aa = new A;//new + ����
	delete aa;//delete + ʵ�����Ķ�����

	A* bb = new A[5];// new + ����[�����С]������������
	delete[] bb;//delete[] + ʵ�����Ķ�����
	//�ͷ�����ʱ�����[]��������ܻ����

	
	return 0;
}