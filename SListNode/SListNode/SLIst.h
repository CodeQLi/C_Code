#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma warning(disable:4996)
typedef int SListDataType;
//�ڵ�
typedef struct SListNode
{
	SListDataType data;//��һ������
	struct SLstNode* Next;	//ָ����һ�����ݵ�ָ��
}SLTNode;

//β��
void SListPushBack(SLTNode** pphead, SListDataType x);

//βɾ
void SListPopBack(SLTNode** pphead);

//ͷ��
void SListPushFront(SLTNode** phead, SListDataType x);

//ͷɾ
void SListPopFront(SLTNode* phead);

//����

SLTNode* SListFind(SLTNode* phead, SListDataType x);

//��ӡ
void SListprint(SLTNode* phead);

//�м����
void SListInsertAfter(SLTNode** phead, SListDataType seat, SListDataType x);

//���ɾ��
void SListEraseAfter(SLTNode* phead,SListDataType delnum);

