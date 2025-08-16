#define _CRT_SECURE_NO_WARNINGS



#include "contacts.h"


void meum (void)//打印菜单
{
	printf("*********************************\n");
	printf("****   1.Addd     2.Delete   ****\n");
	printf("****   3.Seacrh   4.Mod      ****\n");
	printf("****   5.Show     6.Sort     ****\n");
	printf("****   0.Exit                ****\n");
	printf("*********************************\n");
}


int main()
{
	void (*ContactsOp[7])(Contacts*) = { NULL,AddPeo,DelPeo,SearchPeo,ModDate,ShowDate,SortDate };
	int input = 0;
	Contacts con;
	Initdate(&con);

	//char text[5] = "-67";
	//int k = charToInt(text);
	//printf("%d\n", k);
	//测试chartoint函数


	do
	{
		char c_input[6] = { 0 };
		meum();
		scanf("%s", c_input);
		input = charToInt(c_input);

		if (6 < input || 0 > input)
		{
			printf("输入有误，请重新输入正确的操作数字：\n");
			continue;
		}
		else if(!input)
			return 0;
		else
			ContactsOp[input](&con);
	} while (input);
	return 0;
}


//void Initdate(Contacts* pc)//初始化通讯录结构体数据，使其全部变成0
//{
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}

int Initdate(Contacts* pc)//初始化通讯录结构体数据，使其全部变成0
{
	PeoInfo* temp = NULL;
	pc->count = 0;
	pc->capacity = DEFALT_SZ;
	while (NULL == temp)
	{
		temp = (PeoInfo*)calloc(pc->capacity, sizeof(PeoInfo));
	}
	pc->date = temp;
}


void DestroyContacts(Contacts* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
	pc = NULL;
}


static void printSingleDate(Contacts* pc, int i,int header)//打印指定下标 i 的联系人数据，header 为0打印表头，否则不打印表头
{
	assert(pc);
	if (0 > i || pc->count < i)
	{
		printf("未找到联系人，打印失败\n");
		return;
	}
	if(!header)
		printf("%-3s\t%-10s\t%-3s\t%-4s\t%-15s\t%-20s\n","序号", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-3d\t%-10s\t%-3d\t%-4s\t%-15s\t%-20s\n",pc->date[i].serial,
												 	pc->date[i].name,
													pc->date[i].age,
													pc->date[i].sex,
													pc->date[i].tele,
													pc->date[i].addr);
}


static int findPeo(Contacts* pc,char *c)
{
	assert(pc);
	char* arr[5] = { "name","age","sex","tele","addr" };
	for (int i = 1;i <= pc->count;i++)
	{
		if (strcmp(c, pc->date[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

int charToInt(char* s)
{
	int i = 0;
	int ret = 0;
	int k = 1;
	for (;s[i];i++)
	{
	}
	for (--i;0 <= i;i--)
	{
		if ('0' <= s[i] && '9' >= s[i])
		{
			ret += (s[i] - 48) * k;
			k *= 10;
		}
		else if ('-' == s[i] && 0 == i )
		{
			ret = -ret;
		}
		else
			return -1;
	}
	return ret;
}

static int indexIsLegal(Contacts* pc, int i)
{
	if (0 < i && pc->count > i)
		return 1;
	return 0;
}

static int exchangPeo(Contacts* pc, int dis, int sou,int ser)
{
	assert(pc);
	if (0 > dis || 0 > sou || pc->count + 1 < dis || pc->count + 1 < sou)
		return -1;
	PeoInfo temp;
	temp = pc->date[sou];
	pc->date[sou] = pc->date[dis];
	pc->date[dis] = temp;
	int k = 0;
	if(!ser)//ser==1时则交换序号
	k = pc->date[sou].serial;
	pc->date[sou].serial = pc->date[dis].serial;
	pc->date[dis].serial = k;
	return 0;

}

static int mod_MoveTO(Contacts* pc, int dis, int sou)
{
	assert(pc);
	if (0 >= dis || 0 >= sou || pc->count < dis || pc->count < sou)
		return -1;
	int temp = 0;
	if (dis < sou)
	{
		exchangPeo(pc, dis, sou, 0);
		int i = pc->count;
		for (;dis + 1 <= i;i--)
		{
			temp = pc->date[i + 1].serial;
			pc->date[i + 1] = pc->date[i];
			pc->date[i + 1].serial = temp;

		}
		exchangPeo(pc, dis + 1, sou + 1, 0);
		for (i = sou + 1;pc->count >= i;i++)
		{
			temp = pc->date[i].serial;
			pc->date[i] = pc->date[i + 1];
			pc->date[i].serial = temp;
		}

	}
	else if (dis > sou)
	{
		exchangPeo(pc, dis, sou, 0);
		int i = 0;
		for (;dis - 1 >= i;i++)
		{
			temp = pc->date[i].serial;
			pc->date[i] = pc->date[i + 1];
			pc->date[i].serial = temp;
		}
		exchangPeo(pc, dis - 1, sou - 1, 0);
		for (i = sou - 1; 1 <= i;i--)
		{
			temp = pc->date[i].serial;
			pc->date[i] = pc->date[i - 1];
			pc->date[i].serial = temp;
		}
	}


}

static int applySerial(Contacts* pc)
{
	for (int i = 1;i <= pc->count;i++)
	{
		pc->date[i].serial = i;
	}
	return pc->count;
}

//static void ModPeo(Contacts* pc, int i, int opNum, char* ex)
//{
//	switch (opNum)
//	{
//	case MOD_ALL:
//
//	case NAME:
//		strcpy(ex, pc->date[i].name);
//		break;
//	case AGE:
//		pc->date[i].age = charToInt(ex);
//		break;
//	case SEX:
//		strcpy(ex, pc->date[i].sex);
//		break;
//	case TELE:
//		strcpy(ex, pc->date[i].tele);
//		break;
//	case ADDR:
//		strcpy(ex, pc->date[i].addr);
//		break;
//	default:
//		printf("未查找到修改项目，修改失败\n");
//		break;
//	}
//}

//静态版本
//void AddPeo(Contacts* pc)
//{
//	assert(pc);
//	if (PEOOLE_MAX - 1 <= pc->count)
//	{
//		printf("联系人数量已经达到上限，添加失败\n");
//		return;
//	}
//	pc->count++;
//	printf("添加联系人开始...\n");
//	printf("请输入名字：\n");
//	scanf("%s", pc->date[pc->count].name);
//	printf("请输入年龄：\n");
//	scanf("%d", &(pc->date[pc->count].age));
//	printf("请输入性别：\n");
//	scanf("%s", pc->date[pc->count].sex);
//	printf("请输入电话：\n");
//	scanf("%s", pc->date[pc->count].tele);
//	printf("请输入地址：\n");
//	scanf("%s", pc->date[pc->count].addr);
//	pc->date[pc->count].serial = pc->count;
//	if(1==pc->count)
//		printSingleDate(pc, pc->count, 0);
//	else
//	{
//		printSingleDate(pc, pc->count-1, 0);
//		printSingleDate(pc, pc->count, 1);
//
//	}
//	printf("联系人添加成功\n");
//
//
//}

void cheakCapacity(Contacts* pc)
{
	assert(pc);
	PeoInfo* temp = NULL;
	if (pc->capacity - 2 <= pc->count)
	{
		pc->capacity += 2;
		while (NULL == temp)
		{
			temp = (PeoInfo*)realloc(pc->date, sizeof(PeoInfo) * pc->capacity);

		}
		pc->date = temp;

		printf("联系人数量已经达到上限，扩容成功\n");

	}

}


void AddPeo(Contacts* pc)
{
	assert(pc);
	//容量检查
	cheakCapacity(pc);
	pc->count++;
	printf("添加联系人开始...\n");
	printf("请输入名字：\n");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入年龄：\n");
	scanf("%d", &(pc->date[pc->count].age));
	printf("请输入性别：\n");
	scanf("%s", pc->date[pc->count].sex);
	printf("请输入电话：\n");
	scanf("%s", pc->date[pc->count].tele);
	printf("请输入地址：\n");
	scanf("%s", pc->date[pc->count].addr);
	pc->date[pc->count].serial = pc->count;
	if (1 == pc->count)
		printSingleDate(pc, pc->count, 0);
	else
	{
		printSingleDate(pc, pc->count - 1, 0);
		printSingleDate(pc, pc->count, 1);

	}
	printf("联系人添加成功\n");


}

void DelPeo(Contacts* pc)
{
	assert(pc);
	char input[NAME_MAX] = { 0 };
	printf("请输入想删除的了联系人的名字：\n");
	scanf("%s", input);
	int i = findPeo(pc, input);
	if (-1 == i)
	{
		printf("未查找到相关联系人，删除失败\n");
		return;
	}
	printSingleDate(pc, i, 1);
	for (;i < pc->count;i++)
	{
		pc->date[i] = pc->date[i + 1];
		pc->date[i].serial = pc->date[i + 1].serial - 1;
	}
	printf("已经成功删除上示联系人\n");
	pc->count--;
}

void SearchPeo(Contacts* pc)
{
	assert(pc);
	char input[NAME_MAX] = { 0 };
	printf("请输入想要查找的联系人的名字:\n");
	scanf("%s", input);
	int i = findPeo(pc, input);
	if (-1 == i)
	{
		printf("未找到相关联系人\n");
		return;
	}
	printf("查找到以下联系人:\n");
	printSingleDate(pc, i, 1);
	printf("查找成功\n\n");
}

void ModDate(Contacts* pc)
{
	assert(pc);
	char input[NAME_MAX] = { 0 };
	printf("请输入要操作的联系人的名字：\n");

	scanf("%s", input);
	int i = findPeo(pc, input);
	if (-1 == i)
	{
		printf("未查找到相关联系人，请重新操作\n");
		return;
	}
	printSingleDate(pc, i, 0);
	printf("查找到以上联系人\n");

	int j = 0;
	int opNum = 1;
	int log = 0;
	while (opNum)
	{
		if (!log)
		{
			printf("当前正在操作的联系人序号为: %d\n", i);
			printf("请输入想要修改的项目的数字：\n");
			printf("1.移动联系人 2.交换联系人 3.全部 4.名字 5.年龄 6.性别 7.电话 8.地址 0.退出\n");
			scanf("%d", &opNum);
		}
		if (opNum)
		{
			printf("请输入修改后内容(移动与交换是输入序号)：\n");
			scanf("%s", input);
		}
		


		if (opNum == MOD_ALL)
		{
			log = 1;
			opNum = NAME;
		}

		switch (opNum)
		{
		case MOVE_TO:
			for (;0 > input && pc->count < input;)
			{
				printf("输入序号超出范围，请重新输入\n");
				scanf("%d", &input);
			}
			mod_MoveTO(pc, charToInt(input), i);
			printSingleDate(pc, i, 0);
			printSingleDate(pc, charToInt(input), 1);
			printf("移动成功\n\n");
			break;

		case EXCHANG:
			//printf("请输入替换目标的序号\n");
			//scanf("%d", &input);
			for (;0 > input && pc->count < input;)
			{
				printf("输入序号超出范围，请重新输入\n");
				scanf("%d", &input);
			}
			exchangPeo(pc, charToInt(input), i, 0);
			printSingleDate(pc, i, 0);
			printSingleDate(pc, charToInt(input), 1);
			printf("修改成功\n\n");
			break;
		case MOD_ALL:
		case NAME:
			strcpy(pc->date[i].name, input);
			printf("名字已修改\n");
			printSingleDate(pc, i, 0);
			break;
		case AGE:
			pc->date[i].age = charToInt(input);
			printf("年龄已修改\n");
			printSingleDate(pc, i, 0);
			break;
		case SEX:
			strcpy(pc->date[i].sex, input);
			printf("性别已修改\n");
			printSingleDate(pc, i, 0);
			break;
		case TELE:
			strcpy(pc->date[i].tele, input);
			printf("电话已修改\n");
			printSingleDate(pc, i, 0);
			break;
		case ADDR:
			strcpy(pc->date[i].addr, input);
			printf("地址已修改\n");
			printSingleDate(pc, i, 0);
			break;
		case MOD_EXIT:
			printf("已退出修改模式\n\n");
		default:
			printf("输入数字未找到相关操作，请重新输入\n");
			break;
		}

		if (log == 1)
		{
			opNum++;
		}
		if (8 < opNum)
		{
			opNum = 9;
			log = 0;
			printf("已全部修改完毕\n\n");
		}
	}
	
}

void ShowDate(Contacts* pc)
{
	assert(pc);
	for (int i = 1;i <= pc->count;i++)
	{
		printSingleDate(pc, i, i-1);
	}
	printf("显示成功\n\n");
}

int cmpPeoByName(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortDate(Contacts* pc)
{
	assert(pc);
	qsort(pc->date + 1, pc->count, sizeof(PeoInfo), cmpPeoByName);
	ShowDate(pc);
	printf("是否要以当前排序应用序号:\n");
	printf("1.是 0.否\n");
	int i = 0;
	scanf("%d", &i);
	if (i == 1)
	{
		applySerial(pc);
	}
	ShowDate(pc);
	printf("应用成功\n\n");
}