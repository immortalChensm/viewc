//
// Created by 1655664358@qq.com on 2019/5/16.
//

#include <stdio.h>
/**
 * 每个结点有数据域和指针域构成
 * 单链表：由N个结点【数据元素映像】链构成，每个结点有指针域指向下一个元素的存储位置，以便将线性表的数据元素按其逻辑次序连接在一起
 * 头结点【数据域不存储东西，或存储公共资料，头指针指向第一个元素的位置】
 * 头指针
 *
 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;
typedef int Status;
Status GetElem(LinkList L,int i,ElemType *e);
int main()
{
//    Node student;
//    ListChain stuList;
//    stuList = &student;
//    stuList->data = 1;
//    Node student2;
//    student2.data = 2;
//    stuList->next = &student2;
//    printf("stuList.data=%d,stuList.next.data=%d\n",stuList->data,stuList->next->data);

    Node student1;
    Node student2;
    Node student3;
    Node student4;
    Node student5;

    student1.data = 100;
    student2.data = 200;
    student3.data = 300;
    student4.data = 400;
    student5.data = 500;

    student1.next = &student2;
    student2.next = &student3;
    student3.next = &student4;
    student4.next = &student5;

    LinkList L;//头结点
    Node student0;
    L = &student0;
    L->data = 5;
    L->next = &student1;

    ElemType *e;
    ElemType k;
    e = &k;
    GetElem(L,3,e);
    return 0;
}
/**
 * 获取单链表的某个结点数据
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    j=1;
    LinkList p;//创建一个结点
    p = L->next;//得到单链表头结点指向的第一个结点
    while(p&&j<i){
        p = p->next;//继续得到下一个结点
        j++;
    }
    if (!p||j>i){
        return ERROR;
    }
    *e = p->data;
    printf("your data is %d\n",*e);
    return OK;
}