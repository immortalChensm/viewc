//
// Created by 1655664358@qq.com on 2019/5/21.
//

#include <stdio.h>
#include <stdlib.h>//标准库
#include <signal.h>//信号
#include <unistd.h>//时间
#include <assert.h>//声明
#include <string.h>
void sigHandler(int signo);

int main(int argc,char *argv[])
{
    signal(SIGINT,sigHandler);
//    while(1)
//    {
//        sleep(1);
//    }

    //int age = atoi(argv[1]);
    //printf("age=%d\n",age);
    //getchar();
   //assert(1==2);
    //int k=100;
    //printf("k=%d\n",*&k);
   // bzero(&k, sizeof(k));//清空

//   int a[100];
//   a[2] = 100;
//   memset(a,1, sizeof(a));
//   printf("a[0]=%d",a[2]);
//    char a[10];
//    char *str = a;
//    printf("str=%s\n",str);
//    memset(str,'\0', sizeof(str));
//    printf("%s\n",str);
//
//    printf("BUF_SIZE=%d\n",BUF_SIZ);

    //printf("%s\n",("1234567"+1));
    int *p;

    while(0.1){//-1,'a',"china",12,sigHandler,&p,main函数
        printf("s");
    }
    return 0;
}

void sigHandler(int signo)
{
    if (signo==SIGINT){
        printf("received SIGINT\n");
    }
}
