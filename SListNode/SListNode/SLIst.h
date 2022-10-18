#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma warning(disable:4996)
typedef int SListDataType;
//节点
typedef struct SListNode
{
	SListDataType data;//第一个数据
	struct SLstNode* Next;	//指向下一个数据的指针
}SLTNode;

//尾插
void SListPushBack(SLTNode** pphead, SListDataType x);

//尾删
void SListPopBack(SLTNode** pphead);

//头插
void SListPushFront(SLTNode** phead, SListDataType x);

//头删
void SListPopFront(SLTNode* phead);

//查找

SLTNode* SListFind(SLTNode* phead, SListDataType x);

//打印
void SListprint(SLTNode* phead);

//中间插入
void SListInsertAfter(SLTNode** phead, SListDataType seat, SListDataType x);

//随机删除
void SListEraseAfter(SLTNode* phead,SListDataType delnum);

