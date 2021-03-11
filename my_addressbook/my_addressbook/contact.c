#include "contact.h"

void init_data(struct con* c)
{
	c->s = (struct inform*)malloc(sizeof(struct inform)*MAX);
	if (c->s == NULL)
	{
		printf("����ʧ��\n");
	}
	c->dex = 0;
}

void add_people(struct con* c)
{
	if (c->dex == sizeof(c->s))
	{
		struct inform* p;
		p = (struct inform*)realloc(c->s,sizeof(c->s)+MAX);//reallocֻ����һ��
		if (p == NULL)
		{
			printf("����ʧ��\n");
		}
		else
		{
			c->s = p;
		}
	}
	else
	{
		printf("����������\n");
		scanf("%s",c->s[c->dex].name);
		printf("����������\n");
		scanf("%d",&(c->s[c->dex].age));//c->c->s[c->dex].ageȡ����������ֵ
		printf("�������Ա�\n");
		scanf("%s",c->s[c->dex].sex);
		printf("������绰\n");
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
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		int sz = 0;
		char del_name[NAME_MAX] = { 0 };
		printf("��������ɾ����\n");
		scanf("%s", &del_name);
		sz = search_nmae(c, del_name);
		if (sz == -1)
		{
			printf("û�д���\n");
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
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int sz = 0;
		char ser_name[NAME_MAX] = { 0 };
		printf("��������Ҫ�����\n");
		scanf("%s", &ser_name);
		sz = search_nmae(c, ser_name);
		if (sz == -1)
		{
			printf("û�д���\n");
		}
		else
		{
			printf("%-10s\t%-5s\t%-5s\t%-20s\n", "����", "����", "�Ա�", "�绰");
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
		printf("ͨѶ¼Ϊ�ոĲ���\n");
	}
	else
	{
		int sz = 0;
		char mod_name[NAME_MAX] = { 0 };
		printf("��������ĵ���\n");
		scanf("%s", &mod_name);
		sz = search_nmae(c, mod_name);
		if (sz == -1)
		{
			printf("û�д���\n");
		}
		else
		{
			printf("�������޸�����\n");
			scanf("%d", &(c->s[sz].age));//c->c->s[c->dex].ageȡ����������ֵ
			printf("�������޸��Ա�\n");
			scanf("%s", c->s[sz].sex);
			printf("�������޸ĵ绰\n");
			scanf("%s", c->s[sz].tle);
		}
	}
}

void appear_people(const struct con* c)
{
	int i = 0;
	if (c->dex == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-10s\t%-10s\t%-10s\t%-20s\n","����","����","�Ա�","�绰");
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