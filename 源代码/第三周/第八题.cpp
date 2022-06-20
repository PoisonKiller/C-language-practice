/*
2 4 6 8 10 -1
1 3 5 7 9 -1
*/
//将两个升序链表合并为一个新的升序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。
#include <iostream>
#include <cstdlib>
#define LEN sizeof(struct ListNode)
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode * next;
}ListNode;

ListNode * creat()
{
    ListNode * head, * p1, * p2;
    p1 = p2 = (ListNode *)malloc(LEN);
    head = NULL;
    cin >> p1 -> val;

    while(p1 -> val != -1)
    {
        if(head == NULL)head = p1;
        else p2 -> next = p1;
        p2 = p1;
        p1 = (ListNode *)malloc(LEN);
        cin >> p1 -> val;
    }
    p2 -> next = NULL;
    return head;
}

void print(ListNode *h)
{
    if(h == NULL){puts("NULL");return;}
    while(h){
        cout << h -> val << ' ';
        h = h -> next;
    }
    puts("");
}

ListNode * mergeTwoLists(ListNode * h1 , ListNode * h2)
{
    ListNode * p , * pp , * current;

    //默认h1为最终链表的头指针，即h1的数据一定要不大于h2的数据
    //如果开始时h1的数据大，则将两个链表的头指针互换
    //这样新链表的表头就可以确定为h1
    if(h2 -> val < h1 -> val)
    {
        ListNode * temp = h1;
        h1 = h2;
        h2 = temp;
    }

    //由于h1的位置已经固定，故从h1所在链表开始搜索
    //currnt为当前
    //
    p = h1 ;//p为h1所在链表的当前查询结点current的前一个指针
    pp = h2 ;//pp为h2所在链表的已经搜索到的节点
    current = p -> next;//current为h1所在链表的已经搜索到的节点

    while(p && pp)
    {
        if(current && current -> val <= pp -> val)
        {
            p = current;
            current = current -> next;
        }//按顺序后移
        else 
        {
            //在current和p之间加入pp指针
            p -> next = pp;
            p = pp;
            pp = pp -> next;//pp后移一位
            p -> next = current;
        }
    }

    return h1;
}

int main()
{
    ListNode * head1, * head2, * head;
    head1 = creat(); head2 = creat();//创建两个新链表

    head = mergeTwoLists(head1 , head2);
    print(head);
    return 0;
}