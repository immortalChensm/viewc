

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

typedef struct DulNode{
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
}DulNode *DulLinkList;

typedef struct Node *LinkList;
typedef int Status;
Status GetElem(LinkList L,int i,ElemType *e);
Status LinkListInsert(LinkList L,int i,ElemType *e);
Status LinkListRemove(LinkList L,int i,ElemType *e);
Status showAllElem(LinkList L,int i,int type);
void CreateListHead(LinkList L,int i);
void CreateListTail(LinkList L,int i);
void CreateCircularLinkList(LinkList L,int i);//创建一个循环链表
Status ClearList(LinkList L);
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

//    Node student1;
//    Node student2;
//    Node student3;
//    Node student4;
//    Node student5;
//
//    student1.data = 100;
//    student2.data = 200;
//    student3.data = 300;
//    student4.data = 400;
//    student5.data = 500;
//
//
//    student1.next = &student2;
//    student2.next = &student3;
//    student3.next = &student4;
//    student4.next = &student5;
//    student5.next = NULL;
//    LinkList L;//头结点
//    Node student0;
//    student0.data = 6;
//    student0.next = &student1;
//    L = &student0;
//    //L->data = 5;
//    //L->next = &student1;
//
//    ElemType *e;
//    ElemType k;
//    e = &k;
//    GetElem(L,3,e);
//
//    printf("*************************************\n");
//    int a=80;
//    LinkListInsert(L,4,&a);
////    GetElem(L,4,e);
//
//    showAllElem(L,7);
//    printf("**************remove***********************\n");
//    LinkListRemove(L,2,e);
//    showAllElem(L,6);


    LinkList L;
    L = (LinkList)malloc(sizeof(Node));
   // L->next = NULL;
   L->data = -1;
    int n=6;
    //CreateListHead(L,n);

    //CreateListTail(L,n);
   // showAllElem(L,n);

     CreateCircularLinkList(L,n);
     showAllElem(L,n,1);

//    printf("will remove list\n");
//    ClearList(L);
//    CreateListTail(L,n);
//    showAllElem(L,n);

    return 0;
}

Status showAllElem(LinkList L,int i,int type)
{
    int k=1;
    LinkList p;
    p = L;
    if (p==NULL||p->next==NULL){
        printf("null linklist\n");
        return ERROR;
    }
    if (type==1){
        while(p&&k<=i){//&&p->next->data!=-1
            p = p->next;
            printf("p.data=%d\n",p->data);
            k++;
        }
    }else{
        while(p){//&&p->next->data!=-1
            p = p->next;
            printf("p.data=%d\n",p->data);
            k++;
        }
    }

    if (!p||k>i){
        return ERROR;
    }
    return OK;
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
    //p = L->next;//得到单链表头结点指向的第一个结点
    p = L;
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

/**
 * 单链表插入
 * @param L
 * @param i
 * @param e
 * @return
 */
Status LinkListInsert(LinkList L,int i,ElemType *e)
{
    int j;
    j=1;
    LinkList p,s;
    //p = L->next;//获取第一个结点
    p = L;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if (!p||j>i){
        return ERROR;
    }

    //创建新结点
    s = (LinkList)malloc(sizeof(Node));
    s->data = *e;//新结点要保存的数据
    s->next = p->next;//新结点保存后继数据元素的存储位置
    p->next = s;//保存当前创建的新结点

    return OK;
}

/**
 * 单链表结点移除
 * @param L
 * @param i
 * @param e
 * @return
 */
Status LinkListRemove(LinkList L,int i,ElemType *e)
{
    int j;
    j=1;
    LinkList p,q;
    p = L->next;//得到头结点指向的第一个结点
    while(p&&j<i){
        p=p->next;//结点向下循环
        j++;
    }

    if (!p||i>j){
        return ERROR;
    }

    q = p->next;//当前结点的下一个结点  要删除下一个结点
    p->next = q->next;//当前结点等于下一个结点的下一个结点

    return OK;

}

/**
 * 头插法创建整个结点
 * @param L
 * @param n
 */
void CreateListHead(LinkList L,int n)
{
    LinkList p;
    int i;
    srand(time(0));

    //L = (LinkList)malloc(sizeof(Node));
    //(L)->next = NULL;

    /**
     * 每次创建新结点的指针域都会保存链表的第一个结点
     * 而新结点都会作为链表的第一个结点
     */
    for(i=0;i<n;i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()*100+1;
        p->next = (L)->next;//L.next = 第一个元素
        (L)->next = p;//L.next指向的第一元素换成目前插入

    }
}

/**
 * 链表尾插入
 * @param L
 * @param n
 */
void CreateListTail(LinkList L,int n)
{
    LinkList p,r;
    int i;
    srand(time(0));

    r = L;
    for(i=0;i<n;i++){
        p = (LinkList)calloc(1,sizeof(Node));
        p->data = i;
        r->next = p;//单链表的最后一个是新结点p
        r = p;//表示当前链表的最后一个结点是新插入的p
    }
    r->next = NULL;
}

/**
 * 清空链表
 * @param L
 * @return
 */
Status ClearList(LinkList L)
{
    LinkList p,q;
    p = L->next;
    while(p){
        q = p->next;//p的第二个节点
        free(p);//清空刚才的第一个节点
        p = q;//当前节点为第二个获取到的结点
    }
    L->next = NULL;
    return OK;
}

/**
 * 创建循环链表
 * @param L
 * @param i
 */
void CreateCircularLinkList(LinkList L,int i)
{
    LinkList p,r;
    p = L;
    int k;
    for(k=0;k<i;k++){
        r = (LinkList)calloc(1, sizeof(Node));
        r->data = k;
        r->next = p->next;
        p->next = r;//链表的头指点一直是当前插入的新结点
        /**
         * p->next=r  尾插法
         * p = r  让链表的头结点等于当前插入的新结点
         */
    }
    int m=0;
    //让链表的终端结点指向第一个节点
    while(p&&m<i){
        p = p->next;
        m++;
    }

    p->next = L;//让最后一个结点指向头结点

}
