#include"contact.h"
//初始化contact
void Init_contact(contact* pc)
{
	assert(pc);//断言
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
//增加联系人
void add_contact(contact* con)
{	
	assert(con);
	if (con->count == MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("请输入姓名:");
	scanf("%s",con->data[con->count].name);
	printf("请输入年龄:");
	scanf("%d",&(con->data[con->count].age));
	printf("请输入性别:");
	scanf("%s", con->data[con->count].sex);
	printf("请输入身高:");
	scanf("%d", &(con->data[con->count].high));
	printf("输入成功\n");
	con->count++;
}

//打印通讯录
void show_contact(contact* con)
{
	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		printf("%2s %2d %2s %2d\n", con->data[i].name, con->data[i].age, con->data[i].sex, con->data[i].high);
	}

}


int find_byname(contact* con, char* arr1)
{
	int i = 0;
	for (i = 0; i < con->count ; i++)
	{
		if (strcmp(con->data[i].name, arr1) == 0)
		{
			return i;
		}
	}
	return -1;
}



//删除通讯录
void del_contact(contact* con)
{
	printf("请输入你要查询的名字：");
	char arr1[NAME];
	scanf("%s", arr1);
	int pos = find_byname(con, arr1);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	int i = 0;
	for (i = pos; i < con->count - 1; i++)
	{
		con->data[i] = con->data[i + 1];

	}
	con->count--;
	printf("删除成功\n");
}



//查找通讯录
void sear_contact(contact* con)
{
	printf("请输入你要查询的名字：");
	char arr1[NAME];
	scanf("%s", arr1);
	int pos = find_byname(con, arr1);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("%2s %2d %2s %2d\n", con->data[pos].name, con->data[pos].age, con->data[pos].sex, con->data[pos].high);
}


//修改通讯录
void mod_contact(contact* con)
{
	printf("请输入你要修改的名字：");
	char arr1[NAME];
	scanf("%s", arr1);
	int pos = find_byname(con, arr1);
	if (pos == -1)
	{
		printf("要修改人不存在\n");
		return;
	}
	printf("请输入姓名:");
	scanf("%s", con->data[pos].name);
	printf("请输入年龄:");
	scanf("%d", &(con->data[pos].age));
	printf("请输入性别:");
	scanf("%s", con->data[pos].sex);
	printf("请输入身高:");
	scanf("%d", &(con->data[pos].high));
	printf("修改成功\n");
}

int cmp(const void* e1, const* e2)
{
	return strcmp(((struct peoinfo*)e1)->name, ((struct peoinfo*)e2)->name);
}

void sort_contact(contact* con)
{
	qsort(con->data, con->count, sizeof (struct peoinfo), cmp);
	printf("排序成功\n");
}
