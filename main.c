#include"List.h"
#include<stdio.h>



int main()
{
	//List* p = CreateList();
	List* p = NULL;
	int iRet = CreateList2(&p);
	if (-1 == iRet)
	{
		printf("创建失败");
		return -1;
	}
	
	printf("创建成功\r\n");

	int i = 10;
	while (i--)
	{
		iRet = InsertData(p,i,0);
		if (NULL == p)
		{
			printf("插入失败");
			break;
		}
	}
	ShowList(p);
	/*
	//测试插入情况
	iRet = InsertData(NULL, 5, 2);
	printf("指向空表"
		"iRet = %d\r\n",iRet);
	iRet = InsertData(p, 11, -1);
	printf("指向P\t"
		"iRet = %d\r\n", iRet);
	*/
	/*删除元素*/
	/*
	DeleteData(p,3);
	ShowList(p);
	*/
	/*
	int temp = -1;
	iRet = DeleteItem(p, &temp, 0);
	printf("iRet = %d , %d\r\n",iRet,temp);
	iRet = DeleteItem(p, &temp, 9);
	printf("iRet = %d , %d\r\n", iRet, temp);
	iRet = DeleteItem(p, &temp, 2);
	printf("iRet = %d , %d\r\n", iRet, temp);
	iRet = DeleteItem(p, &temp, -1);
	printf("iRet = %d , %d\r\n", iRet, temp);
	
	*/
	/*查找完成*/
	iRet = SearchItem(p,0);
	printf("iRet = %d\r\n", iRet);
	iRet = SearchItem(p, 9);
	printf("iRet = %d\r\n", iRet);
	/*修改*/
	iRet = UpdateItem(p,6,2);
	printf("iRet = %d\r\n", iRet);
	ShowList(p);
	printf("iCount = %d\r\n",p -> iCount);
	Destory(p);
	return 0;
}