/*.给出两个非空的链表用来表示两个非负的整数。
其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位数字。
如果我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字0之外，这两个数都不会以0 开头。
*/
#include <iostream>
#include<cstdlib>
#define LEN sizeof(struct ListNode)
using namespace std;

int n,m;

typedef struct ListNode{
    int val;
    struct ListNode * next;
}ListNode;

//creat函数为创建新链表的函数
ListNode* creat()
{
    ListNode * p1,* p2,* head;
    
    p1 = p2 = (ListNode *)malloc(LEN);//开辟新单元
    
    cin >> p1 -> val;
    head = NULL;
    
    while(p1 -> val != -1)
    {
        if(head == NULL)head = p1;
        else p2 -> next = p1;
        p2 = p1;
        p1 = (ListNode *)malloc(LEN);//创建动态单元
        cin >> p1 -> val;
    }
    
    p2 ->next = NULL;//结束链表
    
    return head;//返回头结点
}

//输出函数
void print(ListNode *h)
{
    while(h){
        cout << h -> val << ' ';
        h = h -> next;
    }
    puts("");
}

ListNode* add_two_numbers(ListNode* h1,ListNode* h2)
{
    ListNode * head,* p1,* p2,* p,* pp;
    p1 = h1, p2 = h2;
    
    head = NULL;
    
    int sum;//两数之和 
    int flag = 0;//sum对10求余的余数，只有0 1两种取法，初始为0

    while(p1 || p2)
    {
        p = (ListNode *)malloc(LEN);//开辟动态数组
        sum = flag;//如果上一位大于10，则sum初始为1，否则为0
        //每次取两个链表上相同节点的一个数，再将两个指针向后移动1位
        if(p1){
            sum += p1 -> val; 
            p1 = p1 -> next;
        }
        if(p2){
            sum += p2 -> val;
            p2 = p2 -> next;
        }
        
        p ->val = sum % 10;//将sum的各位赋给新链表的指针内
        if(head == NULL)head = p;
        else pp -> next = p;//将上一个指针与之链接起来
        flag = sum / 10;//flag取sum的十位上的数
        pp = p;//pp用来存储p指针

        //如果最后一个sum大于10,则需要在最后再开辟一个单元，存储val = 1；
        if(!p1 && !p2 && flag)
        {
            p = (ListNode *)malloc(LEN); 
            p -> val = 1;
            pp ->next  = p;
            pp = p;
        }
        
    }
    p -> next = NULL;//使链表完整
    return head;//返回头节点
    
}

int main()
{
    ListNode * head1,* head2,* head;
    
    head1 = creat();head2 = creat();//创建两个新链表
 
    head = add_two_numbers(head1,head2);
    print(head);
    
    return 0;
}
