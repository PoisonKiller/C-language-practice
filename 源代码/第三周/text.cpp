#include <iostream>
#include <cstdlib>
using namespace std;

#define LEN sizeof(struct ListNode)

typedef struct ListNode
{
    int val;
    struct ListNode * next;
}ListNode;

ListNode * creat()
{
    ListNode * head , * p1 , * p2;
    p1 = p2 = (ListNode * )malloc(LEN);//开辟动态单元
    head = NULL;//初始头节点为空

    scanf("%d",&p1 -> val);
    while(p1 -> val != -1)//当输入某个数据时表示链表创建结束
    {
        if(head == NULL)head = p1;//初始head为第一个节点
        else p2 -> next = p1;//从第二个节点开始就开始连接相邻节点
        p2 = p1;//p2存储原来的p1节点
        p1 = (ListNode * )malloc(LEN);//创建动态链表
        scanf("%d",&p1 -> val);//输入数据
    }

    p2 -> next = NULL;//使尾节点为空
    return head;//返回头节点
}

void print(ListNode * head)
{
    if(head ==NULL)
    {
        puts("NULL");
        return;
    }

    ListNode * p = head;
    while(p)
    {
        printf("%d ",p -> val);
        p = p -> next;
    }
    puts("");
}

int main()
{
    ListNode * head;
    head = creat();
    print(head);
    return 0;
}