//
// Created by bf on 2016/4/26.
//

#include <stdio.h>
#include <stdlib.h>
void fund(char **str);//二级指针
//野指针测试  指针变量对应的内容地址没了，找不到了
int main()
{
    char *pstr;//栈区
    //fund(&pstr);
    //puts(*pstr);
    char name[] = "china";
    char *pname = name;
    char **str = &pname;//name=&name[0]
    printf("str=%c\n",**str);
     printf("str=%s\n",**str);
    return 0;
}

void fund(char **str)
{
    //局部变量  参数，都位于栈内存  本函数出栈后所有变量的内容全销毁
    char name[] = "hello";//name = &name[0]  栈区
    *str = name;//栈区 str=二级指针  *str获取其变量的内容
    //str=&name *str=*name name=&name[0]
}
