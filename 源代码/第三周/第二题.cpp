//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//由于此题所给的链表时已经排好序的，所以查找相同元素只需要在相邻结点内查找
#include<iostream>
#include<cstdlib>
using namespace std;

#define  LEN  sizeof(struct ListNode)

//定义结构体数组 
typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode;

//creat函数用来创建动态链表 
ListNode* creat()
{
	ListNode * p1,* p2,* head;
	p1 = p2 = (struct ListNode * )malloc(LEN);//开辟新单元 
	
	cin >> p1 -> val;
	head = NULL;
	
	while(p1 -> val != -1)//当输入0时表示程序输入结束 
	{
		if( head == NULL )head = NULL;
        else p2 -> next = p1;//不是第一次输入时就将原来p1的指针(现在是p2)指向p1,使链表连接起来 
		p2 = p1;//将p2存储为原来的p1指针 
		p1 = (struct ListNode * )malloc(LEN);//创建动态链表 
		cin >> p1 -> val;
	}
	p2 -> next = NULL;//最后的指针指向的应该为空 
	return head;//返回头指针 
}

//删除操作只需查找每个结点上的数是否与它的上一个结点的数相等 
ListNode* deleteDuplicates(ListNode* head)
{
	ListNode  * current ,* prev,* temp;
	//currnet表示现在已经查询到了的结点的位置  
	current = head -> next;//开始时应该是第二个结点的位置 
	prev = head;//prev存储current的上一个结点，开始时应该是头结点 
	while(current)//当查询到最后一个空结点时，删除操作完成 
	{
		temp = current -> next;//temp存储current的下一个结点 
		if(current -> val == prev -> val)prev -> next = temp;
		//如果相同,则将prev的next指针指向temp，即跳过了current,且此时prev指针应该不变 
		else prev = current;//如果不同，prev可向后移动一位 
		current = temp;//当前查询结束，current向后移动一位 
	}
	return head;//返回头指针 
}

int main()
{
	ListNode * head,* new_head,* p;
	
	head = creat();//head为创建的原链表的头指针 
	
	p = new_head = deleteDuplicates(head);//new_head为删除相同元素后的新链表的头指针 
	
	//输出新链表的元素 
	while(p){
		cout << p -> val << ' ';
		p = p -> next;
	}
	return 0;
}
