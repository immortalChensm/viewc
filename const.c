
// Created by Administrator on 2015/4/2

#include <stdio.h>
//const
int main()
{
    int n = 100;
    const int Min = n;
    printf("%d\n",Min);

    //Min = 300;//禁止修改


    int const *p1;//指针变量的值不能被修改
    const int *p2;//指针变量指向的值不能被修改
    int * const p3;

    int a = 10;
    p1 = &a;
    printf("p1=%d\n",*p1);
    p2 = &a;
    p3 = &a;
    int b = 100;
    p1 = &b;

    printf("p1=%d\n",*p1);

    b = 200;
    p1 = &b;
    printf("p1=%d\n",*p1);


    int c = 100;
    p2 = &c;
    int d = 0;
    p2 = &d;
    d = 100;
    p2 = &d;

    p3 = &c;
    
}
