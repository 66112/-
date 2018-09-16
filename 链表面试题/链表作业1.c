#include "linklist.h"
pNode BuyNode(int d)           //买节点
{
	pNode newNode = NULL;
	newNode = (pNode)malloc(sizeof(struct Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

void PushBack(pList* pplist,int d)       //尾插
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

void ListToheadFromLastD(pList plist)    //从尾到头打印,递归
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

void ListToheadFromLast(pList* pplist)    //从尾到头打印，非递归,头插法
{
	pNode cur = NULL;
	pNode re = NULL;
	cur =(*pplist)->next;             //cur总是指向头节点的下一个节点
	(*pplist)->next = NULL;      //将第一个的节点中的指针赋为NULL,当链表的最后一个节点
	while (cur)
	{
		re = cur->next;
		cur->next = *pplist;
		*pplist = cur;
		cur = re;
	}
}

void EraseNotTailNode(pList* pplist,pNode pos)      //删除一个无头单链表的非尾节点
{
	assert(pos != NULL);        
	pos->data = pos->next->data;       //用下一个位置的数据把该位置的数据覆盖掉
	pNode del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void InsertNodeNoHead(pList* pplist,pNode pos,int d)      //在一个无头单链表的一个节点前插入一个节点
{
	assert(pos != NULL);
	DataType tmp = 0;			
	pNode newNode = BuyNode(d);
	newNode->next = pos->next;								
	pos->next = newNode;
	tmp = pos->data;								//先插在指定位置的后面，再交换数值
	pos->data = newNode->data;
	newNode->data = tmp;
}

void JosephCricle(pList* pplist,int d)        //约瑟夫环
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
			printf("幸存者:%d\n", cur->data);
			break;
		}
		while (--i)
		{
			flag = cur;
			cur = cur->next;
		}
		printf("杀死:%d\n", cur->data);
		del = cur;
		flag->next = del->next;
		cur = cur->next;
		free(del);
	}
}

void BubbleSort(pList plist)     //冒泡排序
{
	assert(plist != NULL);
	pNode cur = plist;
	pNode flag = NULL;							//标记已排完序的最后一个节点
	int tmp = 0;
	while (cur!=flag)
	{
		while (cur->next!=flag)                //flag控制内层循环
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

void SelectSort(pList plist)            //选择排序
{
	assert(plist != NULL);
	pNode cur = plist;
	pNode tell = NULL;                   //标记最后一个节点
	pNode flag = cur;                    //标记最大元素的节点
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
void myQuickSort(pList pStart, pList pEnd)       //快速排序，pEnd==NULL
{
	if (pStart == NULL || pStart == pEnd)		//起始节点为空，结束
		return;
	int key = pStart->data;
	pNode cur1 = pStart;
	pNode cur2 = cur1->next;
	while (cur2 != pEnd)
	{
		if (cur2->data < key)					//cur2找比key小的
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

pNode FindNode(pList plist,int d)      //查找单链表的中间节点
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

pNode FindFromtail(pList plist, int k)   //查找单链表倒着数第k个元素
{
	pNode cur = plist;
	pNode flag = plist;                       
	while (cur)                              //遍历链表
	{
		int d = k;
		flag = cur;                           //标记节点
		while (--d)                          //遍历k-1次
		{
			cur = cur->next;     
			if (cur == NULL)                  //一旦k大于链表的实际长度时，cur没到k-1次就会出现NULL
				return NULL;
		}
		if (cur->next == NULL)                //当遍历第k-1次后，cur的next为空，则flag就为要找的那个元素
			return flag; 
		cur = flag->next;                     //否则，从头开始下一个                             
	}
	return NULL;
}

void rmNodeFromTail(pList* pplist,int k)            //删除倒数第k个元素
{
	assert(pplist != NULL);
	pNode cur=FindFromtail(*pplist, k);
	pNode tmp = cur->next->next;
	cur->data = cur->next->data;
	free(cur->next);
	cur->next = tmp;
}
pNode AddSort(pList* pplist1, pList* pplist2)     //合并两个有序链表，结果依然有序，递归
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

void UnionSet(pList plist1, pList plist2)       //求两个已排序单链表中相同的元素
{
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	printf("相同的元素为:");
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
	printf("无\n");
}

pLinkNode CheckCycle(pList plist)           //判断链表是否带环
{
	pNode slow = plist;
	pNode fast = plist;
	while (fast && fast->next)
	{
		slow = slow->next;              //slow一次走一步
		fast = fast->next->next;        //fast一次走两步
		if (fast == slow)               //是环，总会相遇
			return fast;
	}
	return NULL;                        //不是环
}

int GetCircleLength(pLinkNode meet)      //求环的长度
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
//求环的入口点，meetNode是带环时的快慢指针的交点
{
	pNode cur = plist;
	while (cur != meetNode)
	{
		cur = cur->next;
		meetNode = meetNode->next;
	}
	return cur;
}

pNode CheckCross(pList plist1, pList plist2)          //判断两个链表是否相交，若相交求交点
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
	if (cur1 == cur2)					 //若两个链表的尾地址相同，则相交
	{
		printf("相交\n");
		cur1 = plist1;
		cur2 = plist2;
		if (len1 < len2)                //调整，使cur1指的是长一些的链表
		{
			cur1 = plist2;
			cur2 = plist1;
		}
		a=abs(len1-len2);          //绝对值
		while (a--)
		{
			cur1 = cur1->next;      //让长的走a步，使两个链表里交点的距离相等
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		printf("交点为:%d\n", cur1->data);
		return cur1;
	}
	printf("不相交\n");
	return NULL;
}

void DestroyList(pList plist)           //销毁链表
{
	pNode del = NULL;
	while (plist)
	{
		del = plist->next;
		free(plist);
		plist = del;
	}
}

pNode PanDuanSuper(pList p1, pList p2)     //判断升级版
{
	//先判断是否带环
	pLinkNode cur1 = CheckCycle(p1);
	pLinkNode cur2 = CheckCycle(p2);
	pLinkNode tmp = NULL;

	if (cur1 == NULL && cur2 == NULL)     //p1和p2都不带环
	{
		tmp = CheckCross(p1, p2);
		return tmp;
	}
	else if ((cur1 == NULL && cur2 != NULL) || (cur1 != NULL && cur2 == NULL))  //p1带环或p2带环
	{
		printf("带环不相交\n");
		return NULL;
	}
	else
	{
		pNode flag1 = GetCycleEntryNode(p1, cur1);       //求环的入口点
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
			if (len1 < len2)                //调整，使cur1指的是长一些的链表
			{
				cur1 = p2;
				cur2 = p1;
			}
			int	a = abs(len1 - len2);          //绝对值
			while (a--)
			{
				cur1 = cur1->next;
			}
			while (cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			printf("都带环，交点为:%d\n", cur1->data);
			return cur1;
		}
		else
		{
			printf("都带环但不相交！\n");
			return NULL;
		}
	}
}
pNode CreatList(pList* pplist, int d)         //建连续列表
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
	return cur;                         //返回尾节点
	//pNode flag = (*pplist)->next->next;       //带环
	//cur->next = flag;
}