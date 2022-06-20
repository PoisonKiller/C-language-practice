//判断一个链表是否为回文链表
//思路：回文链表与将它反转之后的链表完成相同
//故可以线创建一个和原链表一样的链表，再将原链表反转
//最后比较两个链表是否对应节点内的数相同，只要有一个不同，就说明不是回文链表
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

bool isPalindrome(ListNode *head)
{


    //先创建一个和原链表一模一样的链表
    ListNode * newhead , * p1 , * p2 , * p;
    p = head , newhead = NULL;
    p1 = p2 =(ListNode *)malloc(LEN); 
    while(p)
    {
        p1 -> val = p -> val;
        if(newhead == NULL)newhead = p1;
        else p2 -> next = p1;
        p2 = p1;
        p1 = (ListNode *)malloc(LEN);
        p = p -> next;
    }
    p2 -> next = NULL;
    //该链表的表头定义为newhead

    //下面将原链表反转，反转原理可见题一
    ListNode  * prev , * current , * temp;
    prev = head;
    current = prev -> next;
    while(current)
    {
        temp = current -> next;
        current -> next = prev;
        prev = current;
        current = temp;
    }

    head -> next = NULL;
    head = prev;
    //反转完成后，将head定义为反转后链表的表头
    //最后再比较两个链表是否完全相同
    ListNode * t1 , * t2;
    t1 = head ,t2 = newhead;
    while(t1 && t2)
    {
        if(t1 -> val == t2 -> val)//对应位置如果相同，则查询下一位
        {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        else return false;//如果对应位置不同，则直接返回false
    }
    return true;//若全都相同，返回true
}

int main()
{
    ListNode * head , * h;
    head = creat();

    if(isPalindrome(head))puts("true");
    else puts("false");

    return 0;
    
}
