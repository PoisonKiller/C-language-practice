//�ж�һ�������Ƿ�Ϊ��������
//˼·�����������뽫����ת֮������������ͬ
//�ʿ����ߴ���һ����ԭ����һ���������ٽ�ԭ����ת
//���Ƚ����������Ƿ��Ӧ�ڵ��ڵ�����ͬ��ֻҪ��һ����ͬ����˵�����ǻ�������
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


    //�ȴ���һ����ԭ����һģһ��������
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
    //������ı�ͷ����Ϊnewhead

    //���潫ԭ����ת����תԭ��ɼ���һ
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
    //��ת��ɺ󣬽�head����Ϊ��ת������ı�ͷ
    //����ٱȽ����������Ƿ���ȫ��ͬ
    ListNode * t1 , * t2;
    t1 = head ,t2 = newhead;
    while(t1 && t2)
    {
        if(t1 -> val == t2 -> val)//��Ӧλ�������ͬ�����ѯ��һλ
        {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        else return false;//�����Ӧλ�ò�ͬ����ֱ�ӷ���false
    }
    return true;//��ȫ����ͬ������true
}

int main()
{
    ListNode * head , * h;
    head = creat();

    if(isPalindrome(head))puts("true");
    else puts("false");

    return 0;
    
}
