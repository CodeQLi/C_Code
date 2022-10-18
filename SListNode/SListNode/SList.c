
#include"SList.h"
//申请结点
SLTNode* BuySListNode(SListDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NewNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	NewNode->data = x; //data位置上放对应的数
	NewNode->Next = NULL; //将最后一个数后面的指针改变成空指针防止野指针指向不明确的指
	return NewNode;
}

//打印
void SListprint(SLTNode* phead)//指向最开始的地址
{
	SLTNode* cur = phead; //把初始指针赋值给另一个指针防止初始指针发生改变
	while (cur != NULL)
	{
		printf("%d->", cur->data); //打印data的数据
		cur = cur->Next;//使cur指向下一个地址
	}
	printf("NULL\n");
}

//尾插
void SListPushBack(SLTNode** pphead, SListDataType x)
{
	SLTNode* NewNode = BuySListNode(x);	//用另一个结构体指针来结构开辟的结点
	SLTNode* tail = *pphead; //本身是一个指针 对他解引用就找到了原来的那个指针
	if (*pphead == NULL)	//如果传过来的指针是一个空指针	
	{
		*pphead = NewNode;//就直接开辟一个结点把new出来的结点赋值 给他
	}
	else
	{
		while (tail->Next != NULL) //如果不是空指针
		{
			tail = tail->Next;//遍历所有结点找到空指针
		}
		tail->Next = NewNode; //naex指向x x后面又被置为空指针
	}

}

//尾删
void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL) //结点为空
	{
		printf("当前结点暂无数据\n");
		return;
	}
	else if ((*pphead)->Next == NULL)	 //一个结点
	{
		free(*pphead);
		*pphead = NULL;
	}
	else	//一个结点以上
	{
		SLTNode* tail = *pphead;//用一个指针来记录最后一个位置
		SLTNode* prev = *pphead;	//另一个指针记录前一个位置
		while (tail->Next != NULL)//当他不为空的时候就继续
		{
			tail = tail->Next;//将下一个元素的地址给到tail
			if (tail->Next != NULL)
			{
				prev = prev->Next;//tail不为空的时候prev也跟着往后走
			}
		}
		free(tail);//找到了就释放掉
		prev->Next = NULL;//把前一个元素后面的指针置为空
	}
}


//头插
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	newNode->Next = *pphead;//把当前元素位置赋给构建出来的结点
	*pphead = newNode;//把构建出来的元素给到ppehad
}

//头删
void SListPopFront(SLTNode** pphead)
{
	SLTNode* newNode = *pphead;
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->Next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		*pphead = (*pphead)->Next;	//先把保存下一个位置
		free(newNode);//然后释放掉当前位置
	}
}

//查找
SLTNode* SListFind(SLTNode* phead, SListDataType x)
{
	SLTNode* cur = phead;//先保存第一个元素的位置
	while (cur)
	{
		if (cur->data == x)
			return cur;//如果找到了返回这个数的地址
		cur = cur->Next;
	}
	return NULL;
}

//随机插入
void SListInsertAfter(SLTNode** pphead, SListDataType seat, SListDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	SLTNode* cur = *pphead;
	while (--seat)
	{
		cur = cur->Next;
	}
	newNode->Next = cur->Next;//让newNOde指向下一个元素
	cur->Next = newNode;//把newNode合并进去
}

//随机删除
void SListEraseAfter(SLTNode** pos,SListDataType delnum)
{
	assert(pos);
	SLTNode* Strat = pos;  //第一个元素的指针赋值给另一个元素
	SLTNode* nextnext;
	while (Strat->Next!=NULL)
	{							//找到需要删除的数记录下标
		nextnext = Strat->Next;
		if (delnum == Strat->data)
		{
			Strat = Strat->Next;
		}
		if (nextnext->Next == NULL && delnum == nextnext->data)
		{
			nextnext = NULL;
			break;
		}
		Strat = nextnext;
	}
}
//if (pos->Next)
//{
//	SLTNode* next = pos->Next;	//让next指向需要删除得元素
//	SLTNode* nextnext = next->Next;//nextnext指向删除得下一个元素
//	pos->Next = nextnext;//pos指向被删除得下一个元素
//	free(next);
//}