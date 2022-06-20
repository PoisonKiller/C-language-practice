/*
编写程序以x为基准分割链表，使得所有小于x的节点排在大于或等于x的节点之前。
如果链表中包含x，x只需出现在小于x的元素之后。
分割元素x只需处于“右半部分”即可，其不需要被置于左右两部分之间。
*/
#include <iostream>
#include <cstdlib>
#define LEN sizeof(struct ListNode)
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode * next;
}ListNode;

ListNode * creat()//创建链表
{
    ListNode *head, * p1, * p2;
    p1 = p2 =(ListNode *)malloc(LEN);
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

void print(ListNode * h)//输出链表
{
    if(h == NULL){puts("NULL");return;}
    while(h){
        cout << h -> val << ' ';
        h = h -> next;
    }
    puts("");
}

ListNode * partition(ListNode * h , int x )
{
    ListNode * p, * p1, * p2, * head;
    p = h;
    head = NULL;

    p1 =(ListNode *)malloc(LEN);
    p2 = NULL;//防止链表中没有比x小的数
    //先找小于x的结点
    while(p)
    {
        if(p -> val < x)
        {
            p1 -> val = p -> val;//赋值给新链表
            if(head == NULL)head = p1;
            else p2 -> next = p1;
            p2 = p1;
            p1 = (ListNode *)malloc(LEN);
        }
        p = p -> next;//每次将指针后移一位
    }
    p = h;//重置为头结点
    //再找大于x的结点
    while(p)
    {
        if(p -> val >= x)
        {
            p1 -> val = p -> val;
            if(p2 == NULL)head = p1;
            else p2 -> next = p1;
            p2 = p1;
            p1 = (ListNode *)malloc(LEN);
        }
        p = p -> next;
    }
    p2 -> next = NULL;//是链表完整

    return head;
}

int main()
{
    int x;
    cin >> x;

    ListNode * h, * head;
    h = creat();//创建一个动态链表

    head = partition(h,x);
    print(head);
    return 0;
}