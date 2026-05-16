#ifndef _LIST_H
#define _LIST_H

#define LIST_SIZE 10

typedef int data_t;

typedef struct List
{
	data_t data[LIST_SIZE];
	int iCount;
}List;
/*
* 采用的是在堆空间申请内存
* 两种创建顺序表的方法一种是返回指针的
*					  一种是调用方法的
*/
List* CreateList();
int CreateList2(List ** pList);
/*插入数据*/
/*            ①对象：哪一个表 ②插入的数据 ③要插入的位置*/
int InsertData(List* pList,data_t tdata,int ioffset);
/*删除数据*/
/*            ①对象：哪一个表 ②删除的位置*/
int DeleteData(List* pList,int ioffset);
/*            ①对象：哪一个表 ②删除的数据 ③删除的位置*/
int DeleteItem(List* pList ,data_t* tdata,int ioffset);
/*查找元素*/
/*			①对象：哪一个表 ②查找的位置 */
int SearchItem(List* pList, data_t tdata);
/*修改元素*/
/*				①对象：哪一个表 ②原本的数据③替换的数据*/
int UpdateItem(List* pList,data_t old,data_t new);
/*打印表*/
void ShowList(List* pList);
/*销毁表*/
void Destory(List* pList);


#endif