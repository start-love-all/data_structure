#include"List.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

List* CreateList()
{
	List* p = (List*)malloc(sizeof(List));
	if ( NULL == p)
	{
		printf("创建失败");
		return p;
	}
	memset(p,0,sizeof(List));
	p -> iCount = 0;
	return p;
}

int CreateList2(List** pList)
{
	if ( NULL == pList)
	{
		printf("创建失败");
		return -1;
	}
	List* p = (List*)malloc(sizeof(List));
	if (NULL == p)
	{
		printf("创建失败");
		return p;
	}
	memset(p, 0, sizeof(List));
	p->iCount = 0;
	*pList = p;

	return 0;
}

int InsertData(List* pList, data_t tdata, int ioffset)
{
	/*从对应下标开始整体后移插入排序
	* 1.先判断是否可以插入
	* 2.要移动的元素的个数,循环的次数
	* 3.开始移动
	* 4.在对应位置写入数据
	* 5.iCount要加1因为该表元素个数加一
	*/
	if (NULL == pList || LIST_SIZE == pList->iCount || ioffset < 0 || ioffset > pList->iCount)
	{
		return -1;
	}
	int iMove = pList->iCount - ioffset;
	int i = pList->iCount - 1;

	while (iMove--)
	{
		pList->data[i + 1] = pList->data[i];
		i--;
	}
	pList->iCount++;
	pList->data[ioffset] = tdata;


	return 0;
}

int DeleteData(List* pList, int ioffset)
{
	/*从对应下标开始整体前移
	* 1.先判断是否可以删除
	* 2.在对应位置删除数据
	* 3.要移动的元素的个数,循环的次数
	* 4.开始移动
	* 5.iCount要减1因为该表元素个数减一
	*/
	if (NULL == pList  || ioffset > pList -> iCount - 1 || ioffset < 0 || NULL == pList ->data[ioffset] || NULL == pList->iCount)
	{
		return -1;
	}
	int iMove = pList->iCount - ioffset;
	int i = ioffset;

	while (iMove--)
	{
		pList->data[i] = pList->data[i+1];
		i++;
	}
	pList->iCount--;


	return 0;

}

int DeleteItem(List* pList, data_t* tdata, int ioffset)
{
	/*
	* 两种情况：
	* 1.1 删除最后一个
	* 1.2 只需要iCount前移一位
	* 2.1 删除！最后一个
	* 2.2 从对应下标开始把下一位数据整体前移
	* 2.3 需要iCount前移一位
	*/
	if (NULL == pList || ioffset > pList->iCount - 1 || ioffset < 0 || NULL == pList->data[ioffset] || NULL == pList->iCount)
	{
		return -1;
	}
	*tdata = pList -> data[ioffset];
	if (ioffset == pList->iCount)
	{
		pList->iCount--;
		return 0;
	}
	int i;
	for (i = ioffset; i < pList->iCount - 1; i++)
	{
		pList->data[i] = pList->data[i + 1];
	}
	pList->iCount--;
	return 0;
}

int SearchItem(List* pList, data_t tdata)
{
	if (NULL == pList || NULL == pList->iCount)
	{
		return -1;
	}
	int i = 0;
	for (i = 0; i < pList->iCount; i++)
	{
		if (pList -> data[i] == tdata)
		{
			return i;
		}
	}
	return -1;	
}

int UpdateItem(List* pList, data_t old, data_t new)
{
	/*确保不为空*/
	if (NULL == pList || NULL == pList->iCount)
	{
		return -1;
	}
	/*修改
	* 1.找数据下标
	* 2.换数据
	*/
	int ioffset = SearchItem(pList, old);
	/*测试*/
	//printf("ioffset %d\r\n", ioffset);
	if (pList->data[ioffset] == old)
	{
		pList->data[ioffset] = new;
		return 0;
	}
	return -1;
}

void ShowList(List* pList)
{
	if (NULL == pList)
	{
		printf("NULL\r\n");
		return;
	}
	int i = 0;
	for (i = 0; i < pList->iCount; i++)
	{
		printf("%d  ",pList -> data[i]);
	}
	printf("\r\n");
}

void Destory(List* pList)
{
	if (NULL != pList)
	{
		free(pList);
		pList = NULL;
		printf("空间已经释放\r\n");
	}

}
