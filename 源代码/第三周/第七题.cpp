/*
7.给你一个链表的头节点 head.
反复删去链表中由总和值为0的连续节点组成的序列，直到不存在这样的序列为止。
删除完毕后，请你返回最终结果链表的头节点。
你可以返回任何满足题目要求的答案。
*/
/*思路：依次搜索链表，当搜索到一个结点时，求该节点的所有后缀和
        若有后缀和为0的，则直接删去这段后缀
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#define LEN sizeof(struct ListNode)
using namespace std;

const int N = 500;
int g[N][N];//存储从当前节点到头结点之间的一段链表中所有后缀和

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

    while(p1 -> val != 9999)
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
 
ListNode * delete_the_0(ListNode * head)
{
    if(head == NULL)return NULL;//如果最后没有元素剩下，则返回NULL;
    ListNode * p = head;

    for(int i = 0 ; p ; i ++)//p为当前搜索到的节点
    {
        g[i][0] = p -> val;//长度为0时，后缀就是其本身
        //j表示后缀长度
        for(int j = 1 ; j <= i ;j ++)g[i][j] = g[i-1][j-1] + p -> val;
        //i表示节点编号，当后缀长大于0，将它前面一个元素的所有后缀+当前数字来得到

        for(int j = 0 ; j <=i ; j ++)
        {
            //搜索当前节点的所有后缀和中是否有等于0的
            if(g[i][j] == 0)
            {
                //当后缀长度等于节点编号时，表示此后缀包含了头节点，头结点也需要删去
                if(i == j) return delete_the_0(p -> next);//直接删去p前面一段
                //当后缀长度小于节点编号时，则只需删除这段后缀即可
                ListNode * temp = head ; 
                for(int t = 1 ; t < i -j  ; t ++)temp = temp -> next;//找到后缀起点的前一个结点
                temp -> next = p -> next;//删除
                return delete_the_0(head);//下一次重新搜索
            }
        }
        p = p -> next;
    }
    return head;
}

int main()
{
    ListNode * head , * newhead;
    head = creat();//创建链表
    newhead = delete_the_0(head);

    print(newhead);//输出
    return 0;
}