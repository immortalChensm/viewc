

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef int SElemType;
typedef int Status;
#define ERROR 0
#define OK 1
//栈结点
typedef struct stackNode{
    SElemType data;
    struct stackNode *next;
}stackNode,*LinkStackPtr;
//栈链结构
typedef struct linkStack{
    LinkStackPtr top;
    int count;
}linkStack;

Status push(linkStack *S,SElemType *e);
Status pop(linkStack *S,SElemType *e);
int main()
{

    stackNode top;
    top.data=-1;
    top.next = NULL;

    linkStack S;
    S.count=-1;
    int data = 100;
    push(&S,&data);
    //printf("S.top.data=%d\n",S.top->data);
    data = 200;
    push(&S,&data);

    data = 300;
    push(&S,&data);
    //printf("S.top.data=%d\n",S.top->data);

    printf("S.top.data=%d\n");
    int *temp = (int *)calloc(1, sizeof(int));
    pop(&S,temp);
    printf("S.top.data=%d\n",*temp);

    pop(&S,temp);
    printf("S.top.data=%d\n",*temp);

    pop(&S,temp);
    printf("S.top.data=%d\n",*temp);

    pop(&S,temp);
    printf("S.top.data=%d\n",*temp);

    pop(&S,temp);
    printf("S.top.data=%d\n",*temp);
    return 0;
}

Status push(linkStack *S,SElemType *e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(stackNode));
    s->data = *e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

Status pop(linkStack *S,SElemType *e)
{
    if (S->count==-1){
        return ERROR;
    }
    LinkStackPtr p;
    *e = S->top->data;//栈顶的节点
    p = S->top;//栈顶节点
    S->top = S->top->next;//栈顶向下移动
    S->count--;
    free(p);
    p=NULL;
    return OK;
}
