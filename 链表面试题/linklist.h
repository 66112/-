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


void ListToheadFromLastD(pList plist);   //�ݹ�
void ListToheadFromLast(pList* pplist);   //��β��ͷ��ӡ���ǵݹ�
void EraseNotTailNode(pList* pplist,pNode pos);      //ɾ��һ����ͷ������ķ�β�ڵ� 
void InsertNodeNoHead(pList* pplist,pNode pos,int d);      //��һ����ͷ�������һ���ڵ�ǰ����һ���ڵ�
void JosephCricle(pList* pplist, int d);       //Լɪ��
void BubbleSort(pList plist);     //ð������
void SelectSort(pList plist);            //ѡ������
void myQuickSort(pList pStart,pList pEnd);       //��������
pNode AddSort(pList* pplist1, pList* pplist2);     //�ϲ������������������Ȼ���򣬵ݹ�
pNode FindNode(pList plist,int d);      //���ҵ�������м�ڵ�
pNode FindFromtail(pList plist, int k);   //���ҵ�����������k��Ԫ��
void rmNodeFromTail(pList* pplist, int k);           //ɾ��������k��Ԫ��
void UnionSet(pList plist1, pList plist2);       //��������������������ͬ��Ԫ��
pLinkNode CheckCycle(pList plist);           //�ж������Ƿ����
int GetCircleLength(pLinkNode meet);         //�󻷵ĳ���
pLinkNode GetCycleEntryNode(pList list, pLinkNode meetNode);          //�󻷵���ڵ�
pNode CheckCross(pList list1, pList list2);     //�ж����������Ƿ��ཻ�����ཻ�󽻵�
pNode PanDuanSuper(pList p1, pList p2);     //�ж�������

void DestroyList(pList plist);           //��������
pNode BuyNode(int d);
pNode CreatList(pList* pplist, int d);   //����һ������������������
void PushBack(pList* pplist, int d);     //β��
void Print(pList plist);				 //��ӡ
#endif __LINKLIST_H__