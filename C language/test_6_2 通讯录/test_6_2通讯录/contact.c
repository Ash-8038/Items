#include"contact.h"
//��ʼ��contact
void Init_contact(contact* pc)
{
	assert(pc);//����
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
//������ϵ��
void add_contact(contact* con)
{	
	assert(con);
	if (con->count == MAX)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����������:");
	scanf("%s",con->data[con->count].name);
	printf("����������:");
	scanf("%d",&(con->data[con->count].age));
	printf("�������Ա�:");
	scanf("%s", con->data[con->count].sex);
	printf("���������:");
	scanf("%d", &(con->data[con->count].high));
	printf("����ɹ�\n");
	con->count++;
}

//��ӡͨѶ¼
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



//ɾ��ͨѶ¼
void del_contact(contact* con)
{
	printf("��������Ҫ��ѯ�����֣�");
	char arr1[NAME];
	scanf("%s", arr1);
	int pos = find_byname(con, arr1);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	int i = 0;
	for (i = pos; i < con->count - 1; i++)
	{
		con->data[i] = con->data[i + 1];

	}
	con->count--;
	printf("ɾ���ɹ�\n");
}



//����ͨѶ¼
void sear_contact(contact* con)
{
	printf("��������Ҫ��ѯ�����֣�");
	char arr1[NAME];
	scanf("%s", arr1);
	int pos = find_byname(con, arr1);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("%2s %2d %2s %2d\n", con->data[pos].name, con->data[pos].age, con->data[pos].sex, con->data[pos].high);
}


//�޸�ͨѶ¼
void mod_contact(contact* con)
{
	printf("��������Ҫ�޸ĵ����֣�");
	char arr1[NAME];
	scanf("%s", arr1);
	int pos = find_byname(con, arr1);
	if (pos == -1)
	{
		printf("Ҫ�޸��˲�����\n");
		return;
	}
	printf("����������:");
	scanf("%s", con->data[pos].name);
	printf("����������:");
	scanf("%d", &(con->data[pos].age));
	printf("�������Ա�:");
	scanf("%s", con->data[pos].sex);
	printf("���������:");
	scanf("%d", &(con->data[pos].high));
	printf("�޸ĳɹ�\n");
}

int cmp(const void* e1, const* e2)
{
	return strcmp(((struct peoinfo*)e1)->name, ((struct peoinfo*)e2)->name);
}

void sort_contact(contact* con)
{
	qsort(con->data, con->count, sizeof (struct peoinfo), cmp);
	printf("����ɹ�\n");
}
