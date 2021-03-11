#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 20
#define TEL_MAX 20
#define SEX_MAX 20
#define MAX 1000

struct inform
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tle[TEL_MAX];
};

struct con
{
	struct inform* s;
	int dex;
};

void init_data(struct con* c);
void add_people(struct con* c);
void del_people(struct con* c);
void sort_people(struct con* c);
void appear_people(const struct con* c);
void mod_people(struct con* c);
void serch_people(const struct con* c);