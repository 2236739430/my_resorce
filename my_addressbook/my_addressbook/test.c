#include "contact.h"

enum choice1
{
	EXIT,
	ADD,
	DEL,
	SERCH,
	MODIFY,
	APPEAR,
	EMPTY,
	SORT,
};

void mune()
{
	printf("******************************\n");
	printf("****1.ADD   2.DEL  3.SERCH****\n");
	printf("****  4.MODIFY  5.APPEAR  ****\n");
	printf("****  6.EMPTY   7.SORT    ****\n");
	printf("****        0.EXIT        ****\n");
	printf("******************************\n");

}


void test()
{
	struct con c;
	init_data(&c);
	int input = 0;
	do
	{
		mune();
		printf("请选择模式\n");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			add_people(&c);
			break;
		case DEL:
			del_people(&c);
			break;
		case SERCH:
			serch_people(&c);
			break;
		case MODIFY:
			mod_people(&c);
			break;
		case APPEAR:
			appear_people(&c);
			break;
		case EMPTY:
			init_data(&c);
			break;
		case SORT:
			sort_people(&c);
			break;
		case EXIT:
			printf("退出\n");
			break;
		default:
			printf("输入错误\n");
			break;
		};
	
	
	} while (input);
}

int main()
{
	test();

	return 0;
}