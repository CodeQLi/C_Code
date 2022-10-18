
#include"SList.h"
//������
SLTNode* BuySListNode(SListDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NewNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	NewNode->data = x; //dataλ���ϷŶ�Ӧ����
	NewNode->Next = NULL; //�����һ���������ָ��ı�ɿ�ָ���ֹҰָ��ָ����ȷ��ָ
	return NewNode;
}

//��ӡ
void SListprint(SLTNode* phead)//ָ���ʼ�ĵ�ַ
{
	SLTNode* cur = phead; //�ѳ�ʼָ�븳ֵ����һ��ָ���ֹ��ʼָ�뷢���ı�
	while (cur != NULL)
	{
		printf("%d->", cur->data); //��ӡdata������
		cur = cur->Next;//ʹcurָ����һ����ַ
	}
	printf("NULL\n");
}

//β��
void SListPushBack(SLTNode** pphead, SListDataType x)
{
	SLTNode* NewNode = BuySListNode(x);	//����һ���ṹ��ָ�����ṹ���ٵĽ��
	SLTNode* tail = *pphead; //������һ��ָ�� ���������þ��ҵ���ԭ�����Ǹ�ָ��
	if (*pphead == NULL)	//�����������ָ����һ����ָ��	
	{
		*pphead = NewNode;//��ֱ�ӿ���һ������new�����Ľ�㸳ֵ ����
	}
	else
	{
		while (tail->Next != NULL) //������ǿ�ָ��
		{
			tail = tail->Next;//�������н���ҵ���ָ��
		}
		tail->Next = NewNode; //naexָ��x x�����ֱ���Ϊ��ָ��
	}

}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL) //���Ϊ��
	{
		printf("��ǰ�����������\n");
		return;
	}
	else if ((*pphead)->Next == NULL)	 //һ�����
	{
		free(*pphead);
		*pphead = NULL;
	}
	else	//һ���������
	{
		SLTNode* tail = *pphead;//��һ��ָ������¼���һ��λ��
		SLTNode* prev = *pphead;	//��һ��ָ���¼ǰһ��λ��
		while (tail->Next != NULL)//������Ϊ�յ�ʱ��ͼ���
		{
			tail = tail->Next;//����һ��Ԫ�صĵ�ַ����tail
			if (tail->Next != NULL)
			{
				prev = prev->Next;//tail��Ϊ�յ�ʱ��prevҲ����������
			}
		}
		free(tail);//�ҵ��˾��ͷŵ�
		prev->Next = NULL;//��ǰһ��Ԫ�غ����ָ����Ϊ��
	}
}


//ͷ��
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	newNode->Next = *pphead;//�ѵ�ǰԪ��λ�ø������������Ľ��
	*pphead = newNode;//�ѹ���������Ԫ�ظ���ppehad
}

//ͷɾ
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
		*pphead = (*pphead)->Next;	//�Ȱѱ�����һ��λ��
		free(newNode);//Ȼ���ͷŵ���ǰλ��
	}
}

//����
SLTNode* SListFind(SLTNode* phead, SListDataType x)
{
	SLTNode* cur = phead;//�ȱ����һ��Ԫ�ص�λ��
	while (cur)
	{
		if (cur->data == x)
			return cur;//����ҵ��˷���������ĵ�ַ
		cur = cur->Next;
	}
	return NULL;
}

//�������
void SListInsertAfter(SLTNode** pphead, SListDataType seat, SListDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	SLTNode* cur = *pphead;
	while (--seat)
	{
		cur = cur->Next;
	}
	newNode->Next = cur->Next;//��newNOdeָ����һ��Ԫ��
	cur->Next = newNode;//��newNode�ϲ���ȥ
}

//���ɾ��
void SListEraseAfter(SLTNode** pos,SListDataType delnum)
{
	assert(pos);
	SLTNode* Strat = pos;  //��һ��Ԫ�ص�ָ�븳ֵ����һ��Ԫ��
	SLTNode* nextnext;
	while (Strat->Next!=NULL)
	{							//�ҵ���Ҫɾ��������¼�±�
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
//	SLTNode* next = pos->Next;	//��nextָ����Ҫɾ����Ԫ��
//	SLTNode* nextnext = next->Next;//nextnextָ��ɾ������һ��Ԫ��
//	pos->Next = nextnext;//posָ��ɾ������һ��Ԫ��
//	free(next);
//}