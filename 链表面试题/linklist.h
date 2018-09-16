#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DataType;
typedef struct Node
{
	int data;
	struct Node* next;
}*pList,*pNode,*pLinkNode;


void ListToheadFromLastD(pList plist);   //递归
void ListToheadFromLast(pList* pplist);   //从尾到头打印，非递归
void EraseNotTailNode(pList* pplist,pNode pos);      //删除一个无头单链表的非尾节点 
void InsertNodeNoHead(pList* pplist,pNode pos,int d);      //在一个无头单链表的一个节点前插入一个节点
void JosephCricle(pList* pplist, int d);       //约瑟夫环
void BubbleSort(pList plist);     //冒泡排序
void SelectSort(pList plist);            //选择排序
void myQuickSort(pList pStart,pList pEnd);       //快速排序
pNode AddSort(pList* pplist1, pList* pplist2);     //合并两个有序链表，结果依然有序，递归
pNode FindNode(pList plist,int d);      //查找单链表的中间节点
pNode FindFromtail(pList plist, int k);   //查找单链表倒着数第k个元素
void rmNodeFromTail(pList* pplist, int k);           //删除倒数第k个元素
void UnionSet(pList plist1, pList plist2);       //求两个已排序单链表中相同的元素
pLinkNode CheckCycle(pList plist);           //判断链表是否带环
int GetCircleLength(pLinkNode meet);         //求环的长度
pLinkNode GetCycleEntryNode(pList list, pLinkNode meetNode);          //求环的入口点
pNode CheckCross(pList list1, pList list2);     //判断两个链表是否相交，若相交求交点
pNode PanDuanSuper(pList p1, pList p2);     //判断升级版

void DestroyList(pList plist);           //销毁链表
pNode BuyNode(int d);
pNode CreatList(pList* pplist, int d);   //创建一个连续的连续的链表
void PushBack(pList* pplist, int d);     //尾插
void Print(pList plist);				 //打印
#endif __LINKLIST_H__