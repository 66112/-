#include "linklist.h"
int main()
{
	pList plist1=NULL;
	pList plist2 = NULL;
	PushBack(&plist1, 1);
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 4);
	PushBack(&plist1, 5);
	ListToheadFromLastD(plist1);
	//Print(plist1);
	/*pNode pEnd=CreatList(&plist1,5);
	Print(plist1);
	ListToheadFromLast(&plist1);
	Print(plist1);*/

	/*PushBack(&plist2, 3);
	PushBack(&plist2, 11);
	PushBack(&plist2, 6);
	PushBack(&plist2, 8);
	PushBack(&plist2, 7);
	PushBack(&plist2, 9);
	Print(plist2);*/
	//pEnd->next = plist1->next->next;
	//plist2->next->next->next->next->next->next = plist1->next->next;
	//plist2->next->next->next->next->next->next = plist2->next->next;
	//PanDuanSuper(plist1, plist2);
	/*pEnd->next = plist2->next;
	Print(plist1);
	CheckCross(plist1, plist2);
	pNode meet = CheckCycle(plist1);
	if (meet != NULL)
	{
		int len = GetCircleLength(meet);
		printf("环的长度:%d\n", len);
		printf("入口点:%d\n", GetCycleEntryNode(plist1, meet)->data);
	}*/
	//myQuickSort(plist1, NULL);
	//Print(plist1);
	//myQuickSort(plist2, NULL);
	//Print(plist2);
	//UnionSet(plist1, plist2);       //求两个已排序单链表中相同的元素
	//rmNodeFromTail(&plist1, 4);            //删除倒数第k个元素
	//Print(plist1);
	//pNode cur = FindFromtail(plist1, 6);  //查找单链表倒着数第k个元素
	/*if (cur == NULL)
		printf("找不到！\n");
	else
		printf("找到了！%d\n", cur->data);*/
	//ListToheadFromLast(&plist1);    //从尾到头打印，非递归,头插法
	//BubbleSort(plist1);
	//Print(plist1);
	/*PushBack(&plist2, 1);
	BubbleSort(plist2);*/
	
	//pNode add=AddSort(&plist1, &plist2);     //合并两个有序链表，结果依然有序
	//Print(add);
	//CreatList(&plist, 41);
	//JosephCricle(&plist, 3);
	//BubbleSort(plist);          //冒泡排序
	//SelectSort(plist);            //选择排序
	//Print(plist);
	//ListToheadFromLast(&plist);
	//pNode pos=FindNode(plist, 5);
	//EraseNotTailNode(pos);
	//InsertNodeNoHead(&plist,pos,100);
	//Print(plist);
	//DestroyList(plist1);
	//DestroyList(plist2);

	return 0;
}