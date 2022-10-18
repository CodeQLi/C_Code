#include"SLiST.h"
SLTNode* pList = NULL;
void TestSList1()
{
	SListPushBack(&pList, 1);//函数内部操作外部指把地址传过去
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListprint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListprint(pList);

	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 5);
	SListprint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListprint(pList);
}
void TestList2()
{
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 5);
	SListprint(pList);

	SLTNode* pos = SListFind(pList, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListprint(pList);
	SListInsertAfter(&pList, 1, 1);
	SListInsertAfter(&pList, 2, 2);
	SListInsertAfter(&pList, 3, 3);
	SListInsertAfter(&pList, 4, 4);
	SListprint(pList);

	int x = 0;
	printf("请输入要删除的下标\n");
	scanf("%d", &x);
	SListEraseAfter(&pList,x);
	SListprint(pList);
}
int main()
{
	TestSList1();
	TestList2();
	free(pList);
	pList = NULL;
	return 0;
}