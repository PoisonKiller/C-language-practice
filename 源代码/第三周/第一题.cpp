//反转一个单链表 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#define LEN sizeof(struct ListNode)

//定义结构体 
typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode;

//read函数为输入链表函数 
ListNode* creat()
{
	ListNode * p1,* p2,* head;

	p1 = p2 = (ListNode * )malloc(LEN);// 开辟新单元 

	cin  >> p1 -> val;
	head = NULL;//将头结点定义为空

	while(p1 -> val !=-1)
	{
        if(head == NULL)head = p1;//head定义为第一个结点
        else p2 -> next = p1;//链表连接起来
		p2 = p1;            //p2存储p1
		p1 = (ListNode * )malloc(LEN);//开辟动态单元 
		cin >> p1 -> val;
	}

	p2 ->next = NULL;//最后一个节点为空 
	return head;//返回这个原链表的头指针 
}

ListNode* reverseList(ListNode* head)
{
	ListNode * current, * prev,*  temp;
	//current已经反转到的节点的位置
	//prev存储current的前一个结点
	//temp存储current的下一个结点 
	current = head;
	prev = NULL;
	
	while( current )//当进行到最后一个空结点时返回 
	{
		temp = current -> next;// temp存储current的下一个结点
		current -> next = prev;//将current即当前结点的next指针指向其前一个元素,断开原来的链表关系 
		prev = current;//再将prev往后移1为 
		current = temp;//对应current也要沿原链表的方向往后移动一位 
	}
	
	return prev;//此时的prev就是反转后的链表的头指针
	//而head指针时原链表的头指针，即新链表的最后一个指针 
}

int main()
{

	ListNode  * head, *new_head, * p;
	
	head = creat();//head为输入链表的头节点 
	
	new_head = reverseList(head);//new_head为反转后的新链表的头节点 
	
	p = new_head; 
	
	//按序输出反转后的链表 
	while(p !=NULL){cout << p -> val << ' '; p = p -> next;}
	return 0;
}
