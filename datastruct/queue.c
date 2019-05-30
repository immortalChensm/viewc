//
// Created by 1655664358@qq.com on 2019/5/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QElemType;
typedef int Status;
#define ERROR 0
#define OK 1

//队列结点
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

//队链
typedef struct
{
    QueuePtr front,rear;
}LinkQueue;

Status EnQueue(LinkQueue *Q,QElemType e);
Status DeQueue(LinkQueue *Q,QElemType *e);

Status removeStr(char *str,char *temp);
int main()
{
    LinkQueue Q;
    QueuePtr Qnode = (QueuePtr)malloc(sizeof(QNode));
    Qnode->data = 100;
    Q.front = Qnode;//链队默认的队头结点和队尾结点
    Q.rear = Qnode;

    QElemType data = 100;
    EnQueue(&Q,data);//入队
    data = 200;
    EnQueue(&Q,data);
    data = 300;
    EnQueue(&Q,data);

    int k;
    DeQueue(&Q,&k);//从链队队头出队列
    printf("k=%d\n",k);
    DeQueue(&Q,&k);
    printf("k=%d\n",k);
    char a='0';
    printf("a=%d\n",(int)a);

    printf("*******************************\n");
    char *str = "php is best language in the world!";
    char *temp;
    //removeStr(str,temp);
    //strcat(temp,str+2);
    //strcat(temp,str+5);
    //printf("str=%s\n",temp);

    temp = strrchr(str,str+1);
    printf("str=%s\n",temp);
    return 0;
}


Status removeStr(char *str,char *temp)
{
    int i;
    for(i=0;i<strlen(str);i++){
        if((int)str[i]>=48||(int)str[i]<=57){

        }else{
            temp[i] = str[i];
        }
    }
}

/**
 * 入队列  队尾
 * @param Q
 * @param e
 * @return
 */
Status EnQueue(LinkQueue *Q,QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;//将当前新结点插入到队列尾
    Q->rear = s;//将当前队尾设置新插入的结点

    return OK;
}

/**
 * 出队列 队头
 * @param Q
 * @param e
 * @return
 */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
    QueuePtr p;
    if (Q->front==Q->rear){
        return ERROR;
    }

    p = Q->front->next;//队头结点的下一个结点

    *e = p->data;

    Q->front->next = p->next;//队头
    if (Q->rear==p){
        Q->rear=Q->front;
    }
    free(p);
    return OK;

}