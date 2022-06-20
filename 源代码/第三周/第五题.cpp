// 1 2 3 4 5 -1
#include<iostream>
#include<cstdlib>
#define LEN sizeof(struct ListNode)
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* creat()//创建动态链表
{
    ListNode * head,* p1,* p2;

    p1 = p2 = (ListNode *)malloc(LEN);//开辟新单元

    head = NULL;
    cin >> p1 -> val;

    while(p1 -> val != -1)//当输入-1时表示程序结束
    {
        if(head == NULL)head = p1;
        else p2 -> next = p1;
        p2 = p1;
        p1 = (ListNode *)malloc(LEN);//创建动态链表
        cin >> p1 -> val;
    }
    p2 -> next = NULL;

    return head;

}
//print输出链表
ListNode* print(ListNode * h)
{
    while(h){
        cout << h -> val <<' ';
        h = h-> next;
    }
    puts("");
}

ListNode* oddEvenList(ListNode* head)
{
    ListNode * p , * h , * p1, * p2;
    p = head;
    h = NULL;
    p1 = p2 = (ListNode *)malloc(LEN);
    for(int i = 1; p ;i++)
    {
        p1 = (ListNode *)malloc(LEN); 
        //当前结点编号位奇数时，按序存进新链表
        if(i%2 == 1)
        {
            p1 -> val = p -> val;
            if(h == NULL)h = p1;
            else p2 -> next = p1;
            p2 = p1;
        }
        p = p -> next;
    }
    p = head;//p重置为头指针
    for(int i = 1; p ;i++)
    {
        p1 = (ListNode *)malloc(LEN); 
        //当前指针编号位偶数时，按序存储进新链表
        if(i%2 == 0)
        {
            p1 -> val = p -> val;
            p2 -> next = p1;//由于此时为上面的最后的奇数结点，故直接连接
            p2 = p1;
        }
        p = p -> next;
    }
    p2 -> next =NULL;//完成收尾
    return h;//返回头结点
}

int main()
{
    ListNode * head1,* head;
    head1 = creat();//创建新链表
    head = oddEvenList(head1);//反转
    print(head);//输出
    return 0;
}