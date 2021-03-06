//
// Created by Administrator on 2019/4/20.
//
/**
 * 符号将多个模块拼接为一个独立的程序的过程就叫做链接（Linking）。
 * 变量，函数名等仅是内存地址的助记符号
 * 编译后最终全部转换为内存地址
 * 程序=代码+数据
 * 指令  操作数据的地址
 * 指令【代码】决定要做什么逻辑处理，如加法逻辑处理，移位等
 * 数据：内存地址上的数据
 * cpu从内存取出指令，取出数据，指令取出后放入指令寄存器，再进行译码产生各种操作的信号
 * 如进行算术和逻辑运算，数据传送，比较等逻辑操作
 *
 * 同时cpu会取出要操作的数据【内存地址上的数据】放入工作寄存器组，由ALU逻辑电路进行处理
 * 再写入到目标寄存器保存
 *
 *
 */
#include <stdio.h>
extern void func();
extern int m;
extern int strLength(char *str);
int main()
{
    func();
    printf("n=%d,m=%d\n",n,m);

    int i;
    for(i=0;i<20;i++){
        putchar('*');
    }
    printf("\n");
    char name[20];
    int length;
    scanf("%s",name);
    if ((length=strLength(name))&&length>0){
        printf("your data is %d name is %s\n",length,name);
    }else{
        printf("error");
    }
    return 0;
}