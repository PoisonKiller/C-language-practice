//3.给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现的数字
//此题只需在第二题的基础上修改删除函数即可 
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
	p1 = p2 = (ListNode * )malloc(LEN);//开辟新单元 
	
	cin >> p1 -> val;
	head = NULL;
	
	while(p1 -> val != -1)//当输入0时表示程序输入结束 
	{
		if(head == NULL)head = p1;
        else p2 -> next = p1;//不是第一次输入时就将原来p1的指针(现在是p2)指向p1,使链表连接起来 
		p2 = p1;//将p2存储为原来的p1指针 
		p1 = (ListNode * )malloc(LEN);//创建动态链表 
		cin >> p1 -> val;
	}
	p2 -> next = NULL;//最后的指针指向的应该为空 
	return head;//返回头指针 
}

void print(ListNode* h)
{
    if(h == NULL){puts("NULL");return;}

    while(h){
        cout << h -> val << ' ';
        h = h -> next;
    }
    puts("");
}

//删除操作只需查找每个结点上的数是否与它的上一个结点的数相等 
ListNode* deleteDuplicates(ListNode* head)
{
	ListNode  * current,* prev,* temp,* p;
	current = head -> next;//current初始为head的next指针
	
    //先找出head的位置，即找到第一个只出现一次的数字作为头结点
    //当head的val==current的val，则head直接定为current -> next
    bool flag = false;//flag用来判断原链表中的head->val是否只出现过一次
	while(head && current && head -> val == current -> val)
	{
        flag = true;
		temp = current -> next;//temp存储current的下一个指针
		head = current;
		current = head -> next;//current初始为head的下一个指针
	}
    //如果flag==true 则此时的head应该也被删除，此时的current才是第一个只出现一次的数
	if(flag)head = current;

	current = NULL;//将current初始为空，防止链表中只有一个已经出现的数字
	if(head)prev = head -> next;//head不为空，prev初始为head的next指针
	if(prev)current = prev -> next;//prev不为空，则current初始为prev的下一个指针
	
    p = head;//p用来存储当前 距离 查询到的结点 最近的 只出现一次的结点
    //这样prev的前一个结点存的数一定是只出现过一次的数
	while(current)//当查询到最后一个空结点时，删除操作完成 
	{
		temp = current -> next;//temp每次都存储current的下一个结点 

		if(current -> val == prev -> val) //如果当前结点的val==前一个结点
		{
			p -> next = temp;//删除这两个结点
			p = temp;//p向后移
			current = NULL;//current初始为空
			if(p)prev = p -> next;
			if(prev)current = prev -> next;
		} 

		else //如果当前结点不等于前一个结点，则prev->val一定是只出现过一次的数字
		{
				p = prev; //p向后移动
				prev = current;//prev也向后移动
                current = temp;//当前查询结束，current向后移动一位 
		}
		
	}
	
	return head;//返回头指针 
}

int main()
{
	ListNode * head,* new_head,* p;
	
	head = creat();//head为创建的原链表的头指针 
	
	new_head = deleteDuplicates(head);//new_head为删除相同元素后的新链表的头指针 
	
    print(new_head);
	return 0;
}
