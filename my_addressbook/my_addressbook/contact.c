#include "contact.h"

void init_data(struct con* c)
{
	c->s = (struct inform*)malloc(sizeof(struct inform)*MAX);
	if (c->s == NULL)
	{
		printf("开辟失败\n");
	}
	c->dex = 0;
}

void add_people(struct con* c)
{
	if (c->dex == sizeof(c->s))
	{
		struct inform* p;
		p = (struct inform*)realloc(c->s,sizeof(c->s)+MAX);//realloc只能用一次
		if (p == NULL)
		{
			printf("开辟失败\n");
		}
		else
		{
			c->s = p;
		}
	}
	else
	{
		printf("请输入姓名\n");
		scanf("%s",c->s[c->dex].name);
		printf("请输入年龄\n");
		scanf("%d",&(c->s[c->dex].age));//c->c->s[c->dex].age取到的是他的值
		printf("请输入性别\n");
		scanf("%s",c->s[c->dex].sex);
		printf("请输入电话\n");
		scanf("%s",c->s[c->dex].tle);
		c->dex++;
	}
}

int search_nmae(struct con* c,char* del_name)
{
	int i = 0;
	for (i = 0; i <= c->dex; i++)
	{
		if (*(c->s[i].name) == *(del_name))
		{
			return i;
		}
	}
	return -1;
}

void del_people(struct con* c)
{
	if (c->dex == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		int sz = 0;
		char del_name[NAME_MAX] = { 0 };
		printf("请输入你删的人\n");
		scanf("%s", &del_name);
		sz = search_nmae(c, del_name);
		if (sz == -1)
		{
			printf("没有此人\n");
		}
		else
		{
			for (i = sz; i < (c->dex)-1; i++)
			{
				c->s[i] = c->s[i + 1];
			}
			c->dex--;
		}
	}
}

void serch_people(const struct con* c)
{
	if (c->dex == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int sz = 0;
		char ser_name[NAME_MAX] = { 0 };
		printf("请输入你要查的人\n");
		scanf("%s", &ser_name);
		sz = search_nmae(c, ser_name);
		if (sz == -1)
		{
			printf("没有此人\n");
		}
		else
		{
			printf("%-10s\t%-5s\t%-5s\t%-20s\n", "姓名", "年龄", "性别", "电话");
			printf("%-10s\t", c->s[sz].name);
			printf("%-5d\t", c->s[sz].age);
			printf("%-5s\t", c->s[sz].sex);
			printf("%-20s\n", c->s[sz].tle);
		}
	}
}
void mod_people(struct con* c)
{
	if (c->dex == 0)
	{
		printf("通讯录为空改不了\n");
	}
	else
	{
		int sz = 0;
		char mod_name[NAME_MAX] = { 0 };
		printf("请输入你改的人\n");
		scanf("%s", &mod_name);
		sz = search_nmae(c, mod_name);
		if (sz == -1)
		{
			printf("没有此人\n");
		}
		else
		{
			printf("请输入修改年龄\n");
			scanf("%d", &(c->s[sz].age));//c->c->s[c->dex].age取到的是他的值
			printf("请输入修改性别\n");
			scanf("%s", c->s[sz].sex);
			printf("请输入修改电话\n");
			scanf("%s", c->s[sz].tle);
		}
	}
}

void appear_people(const struct con* c)
{
	int i = 0;
	if (c->dex == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-10s\t%-10s\t%-10s\t%-20s\n","姓名","年龄","性别","电话");
		for (i = 0; i < c->dex; i++)
		{
			printf("%-10s\t",c->s[i].name);
			printf("%-10d\t", c->s[i].age);
			printf("%-10s\t", c->s[i].sex);
			printf("%-20s\n", c->s[i].tle);
		}

	}
}


void sort_people(struct con* c)
{
	struct inform tem;
	int i = 0;
	for (i = 0; i < (c->dex)-1; i++)
	{
		if (c->s[i].age > c->s[i + 1].age)
		{
			tem = c->s[i];
			c->s[i] = c->s[i + 1];
			c->s[i + 1] = tem;
		}
	}
}