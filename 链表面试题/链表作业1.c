#include "linklist.h"
pNode BuyNode(int d)           //��ڵ�
{
	pNode newNode = NULL;
	newNode = (pNode)malloc(sizeof(struct Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

void PushBack(pList* pplist,int d)       //β��
{
	assert(pplist != NULL);
	pNode newNode = BuyNode(d);
	if (*pplist == NULL)
	{
		*pplist = newNode;
		return;
	}
	else
	{
		pNode cur = *pplist;
		pNode newNode = BuyNode(d);
		while (cur->next)
			cur = cur->next;
		cur->next = newNode;
	}
}

void Print(pList plist)
{
	pNode cur = plist;
	if (plist == NULL)
		return;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}

void ListToheadFromLastD(pList plist)    //��β��ͷ��ӡ,�ݹ�
{
	pNode cur = plist;
	if (plist == NULL)
		return;
	if (cur->next == NULL)
	{
		printf("%d->", cur->data);
		return;
	}
	ListToheadFromLastD(cur->next);
	printf("%d->", cur->data);
}

void ListToheadFromLast(pList* pplist)    //��β��ͷ��ӡ���ǵݹ�,ͷ�巨
{
	pNode cur = NULL;
	pNode re = NULL;
	cur =(*pplist)->next;             //cur����ָ��ͷ�ڵ����һ���ڵ�
	(*pplist)->next = NULL;      //����һ���Ľڵ��е�ָ�븳ΪNULL,����������һ���ڵ�
	while (cur)
	{
		re = cur->next;
		cur->next = *pplist;
		*pplist = cur;
		cur = re;
	}
}

void EraseNotTailNode(pList* pplist,pNode pos)      //ɾ��һ����ͷ������ķ�β�ڵ�
{
	assert(pos != NULL);        
	pos->data = pos->next->data;       //����һ��λ�õ����ݰѸ�λ�õ����ݸ��ǵ�
	pNode del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void InsertNodeNoHead(pList* pplist,pNode pos,int d)      //��һ����ͷ�������һ���ڵ�ǰ����һ���ڵ�
{
	assert(pos != NULL);
	DataType tmp = 0;			
	pNode newNode = BuyNode(d);
	newNode->next = pos->next;								
	pos->next = newNode;
	tmp = pos->data;								//�Ȳ���ָ��λ�õĺ��棬�ٽ�����ֵ
	pos->data = newNode->data;
	newNode->data = tmp;
}

void JosephCricle(pList* pplist,int d)        //Լɪ��
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	pNode del = NULL;
	pNode flag = NULL;
	int i = 0;
	while (1)
	{
		i = d;
		if (cur->next == cur)
		{
			printf("�Ҵ���:%d\n", cur->data);
			break;
		}
		while (--i)
		{
			flag = cur;
			cur = cur->next;
		}
		printf("ɱ��:%d\n", cur->data);
		del = cur;
		flag->next = del->next;
		cur = cur->next;
		free(del);
	}
}

void BubbleSort(pList plist)     //ð������
{
	assert(plist != NULL);
	pNode cur = plist;
	pNode flag = NULL;							//���������������һ���ڵ�
	int tmp = 0;
	while (cur!=flag)
	{
		while (cur->next!=flag)                //flag�����ڲ�ѭ��
		{
			if (cur->data > cur->next->data)
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		flag = cur;
		cur = plist;
	}
}

void SelectSort(pList plist)            //ѡ������
{
	assert(plist != NULL);
	pNode cur = plist;
	pNode tell = NULL;                   //������һ���ڵ�
	pNode flag = cur;                    //������Ԫ�صĽڵ�
	int tmp = 0;
	while (cur!=tell)
	{
		int max = cur->data;
		while (cur->next != tell)
		{
			if (max < cur->next->data)
			{
				max = cur->next->data;
				flag = cur->next;
			}
			cur = cur->next;
		}
		if (flag != cur)
		{
			tmp = flag->data;
			flag->data = cur->data;
			cur->data = tmp;
		}
		tell = cur;
		cur = plist;
		flag = cur;
	}
}

void myswap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void myQuickSort(pList pStart, pList pEnd)       //��������pEnd==NULL
{
	if (pStart == NULL || pStart == pEnd)		//��ʼ�ڵ�Ϊ�գ�����
		return;
	int key = pStart->data;
	pNode cur1 = pStart;
	pNode cur2 = cur1->next;
	while (cur2 != pEnd)
	{
		if (cur2->data < key)					//cur2�ұ�keyС��
		{
			cur1 = cur1->next;
			myswap(&(cur1->data), &(cur2->data));
		}
		cur2 = cur2->next;
	}
	myswap(&(pStart->data), &(cur1->data));
	pNode flag = cur1;
	myQuickSort(pStart, flag);
	myQuickSort(flag->next, pEnd);
}

pNode FindNode(pList plist,int d)      //���ҵ�������м�ڵ�
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == d)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

pNode FindFromtail(pList plist, int k)   //���ҵ�����������k��Ԫ��
{
	pNode cur = plist;
	pNode flag = plist;                       
	while (cur)                              //��������
	{
		int d = k;
		flag = cur;                           //��ǽڵ�
		while (--d)                          //����k-1��
		{
			cur = cur->next;     
			if (cur == NULL)                  //һ��k���������ʵ�ʳ���ʱ��curû��k-1�ξͻ����NULL
				return NULL;
		}
		if (cur->next == NULL)                //��������k-1�κ�cur��nextΪ�գ���flag��ΪҪ�ҵ��Ǹ�Ԫ��
			return flag; 
		cur = flag->next;                     //���򣬴�ͷ��ʼ��һ��                             
	}
	return NULL;
}

void rmNodeFromTail(pList* pplist,int k)            //ɾ��������k��Ԫ��
{
	assert(pplist != NULL);
	pNode cur=FindFromtail(*pplist, k);
	pNode tmp = cur->next->next;
	cur->data = cur->next->data;
	free(cur->next);
	cur->next = tmp;
}
pNode AddSort(pList* pplist1, pList* pplist2)     //�ϲ������������������Ȼ���򣬵ݹ�
{
	pNode pHead = NULL;
	if (*pplist1 == NULL)
		return *pplist2;
	else if (*pplist2 == NULL)
			 return *pplist1;
	if (*pplist1 == NULL && *pplist2 == NULL)
		return NULL;
	if (((*pplist1)->data) < ((*pplist2)->data))
	{
		pHead = *pplist1;
		pHead->next = AddSort(&((*pplist1)->next), &(*pplist2));
	}
	else
	{
		pHead = *pplist2;
		pHead->next = AddSort(&(*pplist1), &((*pplist2)->next));
	}
	return pHead;
}

void UnionSet(pList plist1, pList plist2)       //��������������������ͬ��Ԫ��
{
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	printf("��ͬ��Ԫ��Ϊ:");
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if (cur1->data == cur2->data)
		{
			printf("%-2d ", cur1->data);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		else
		{
			cur2 = cur2->next;
		}
	}
	printf("��\n");
}

pLinkNode CheckCycle(pList plist)           //�ж������Ƿ����
{
	pNode slow = plist;
	pNode fast = plist;
	while (fast && fast->next)
	{
		slow = slow->next;              //slowһ����һ��
		fast = fast->next->next;        //fastһ��������
		if (fast == slow)               //�ǻ����ܻ�����
			return fast;
	}
	return NULL;                        //���ǻ�
}

int GetCircleLength(pLinkNode meet)      //�󻷵ĳ���
{
	int len = 1;
	pNode cur = meet->next;
	while (cur!=meet)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

pLinkNode GetCycleEntryNode(pList plist, pLinkNode meetNode)          
//�󻷵���ڵ㣬meetNode�Ǵ���ʱ�Ŀ���ָ��Ľ���
{
	pNode cur = plist;
	while (cur != meetNode)
	{
		cur = cur->next;
		meetNode = meetNode->next;
	}
	return cur;
}

pNode CheckCross(pList plist1, pList plist2)          //�ж����������Ƿ��ཻ�����ཻ�󽻵�
{
	assert(plist1 != NULL);
	assert(plist2 != NULL);
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	int len1 = 1;
	int len2 = 1;
	int a = 0;
	while (cur1->next)
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2->next)
	{
		len2++;
		cur2 = cur2->next;
	}
	if (cur1 == cur2)					 //�����������β��ַ��ͬ�����ཻ
	{
		printf("�ཻ\n");
		cur1 = plist1;
		cur2 = plist2;
		if (len1 < len2)                //������ʹcur1ָ���ǳ�һЩ������
		{
			cur1 = plist2;
			cur2 = plist1;
		}
		a=abs(len1-len2);          //����ֵ
		while (a--)
		{
			cur1 = cur1->next;      //�ó�����a����ʹ���������ｻ��ľ������
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		printf("����Ϊ:%d\n", cur1->data);
		return cur1;
	}
	printf("���ཻ\n");
	return NULL;
}

void DestroyList(pList plist)           //��������
{
	pNode del = NULL;
	while (plist)
	{
		del = plist->next;
		free(plist);
		plist = del;
	}
}

pNode PanDuanSuper(pList p1, pList p2)     //�ж�������
{
	//���ж��Ƿ����
	pLinkNode cur1 = CheckCycle(p1);
	pLinkNode cur2 = CheckCycle(p2);
	pLinkNode tmp = NULL;

	if (cur1 == NULL && cur2 == NULL)     //p1��p2��������
	{
		tmp = CheckCross(p1, p2);
		return tmp;
	}
	else if ((cur1 == NULL && cur2 != NULL) || (cur1 != NULL && cur2 == NULL))  //p1������p2����
	{
		printf("�������ཻ\n");
		return NULL;
	}
	else
	{
		pNode flag1 = GetCycleEntryNode(p1, cur1);       //�󻷵���ڵ�
		pNode flag2 = GetCycleEntryNode(p2, cur2);
		if (flag1 == flag2)
		{
			cur1 = p1;
			cur2 = p2;
			int len1 = 0;
			int len2 = 0;
			while (cur1 != flag1)
			{
				len1++;
				cur1 = cur1->next;
			}
			while (cur2 != flag1)
			{
				len2++;
				cur2 = cur2->next;
			}
			cur1 = p1;
			cur2 = p2;
			if (len1 < len2)                //������ʹcur1ָ���ǳ�һЩ������
			{
				cur1 = p2;
				cur2 = p1;
			}
			int	a = abs(len1 - len2);          //����ֵ
			while (a--)
			{
				cur1 = cur1->next;
			}
			while (cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			printf("������������Ϊ:%d\n", cur1->data);
			return cur1;
		}
		else
		{
			printf("�����������ཻ��\n");
			return NULL;
		}
	}
}
pNode CreatList(pList* pplist, int d)         //�������б�
{
	assert(pplist != NULL);
	if (*pplist == NULL)
		*pplist = BuyNode(1);
	int i = 0;
	pNode cur = *pplist;
	for (i = 2; i <= d; i++)
	{
		pNode newNode = BuyNode(i);
		cur->next = newNode;
		cur = cur->next;
	}
	return cur;                         //����β�ڵ�
	//pNode flag = (*pplist)->next->next;       //����
	//cur->next = flag;
}