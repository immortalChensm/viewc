//
// Created by Administrator on 2015/3/3

//#include <stdio.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void demo1()
{
    //2?????=16λ ??Чλ??15λ 32 768
//    short a = - 32768;
//    short b = 32768;
//
//    unsigned short c = 65535;
//
//    printf("%hd,%hd,%hu\n",a,b,c);
//    printf("%hd,%hd,%hd\n", sizeof(a), sizeof(b), sizeof(c));
//
//    short d = 0b00101010;
//    short e = 010;
//    short f = 0xef;
//
//    printf("%#hx,%#hx,%#hx\n",d,e,f);
//
//    short d1 = 0b10101010;
//    printf("%#hx\n",d+d1);


      short a = 0x11;//?з?????  ???λ?1???????
      //0x11 1000 0000 0001 0001 17
      //     1000 0000 0001 0001 ???
      //
      //

      printf("%hd\n",a);//???з?????????????????????????????


      printf("%hu\n",a);//?????????????????????????????????

      short b = -0x11;//?з?????  ???λ?1
      //-0x11 1000 0000 0001 0001
      //      1111 1111 1110 1110 ????
      //      1111 1111 1110 1111 ????

      //      ff ef

      printf("%#hX\n",b);//????з??????????????


      short c = -9;//?з?????????
      //1000 0000 0000 1001 ?????????
      //1111 1111 1111 0110 ?????????
      //1111 1111 1111 0111 ?????????

      //fff7

      printf("%#hX\n",c);//????????????
      printf("%hd\n",c);//??????????


}

/**
 * ????????????
 */
void demo2()
{

    short a1 = 0b01;
    short a2 = 0b10;
    /***
     * 0000 0000 0000 0001
     * 0000 0000 0000 0010
     * 0000 0000 0000 0011
     * 0003
     */
    printf("%#hx\n",a1+a2);

    short b1 = 0b111;
    short b2 = 0b111;
    /**
     * 0000 0000 0000 0111
     * 0000 0000 0000 0111
     * 0000 0000 0000 1110
     * 000e
     */
     printf("%#hX\n",b1+b2);


     short c1 = 0b0101;
     short c2 = 0b1010;

     /**
      * 0101
      * 1010
      * 0000 0000 0000 0001
      * 1111 1111 1111 1111
      */

     printf("%#hX\n",c1-c2);


     short d1 = 0b01011010;
     short d2 = 0345;
     short d3 = 0xafe;

     /**
      * 01011010
      * 2*6 2*4 2*3 2 = 2+8+16+64=90
      *
      * 3*8[2] + 4*8[1] + 5*8 = 5+32+195 = 232
      *
      * 10*16[2]+15*16[1]+14 = 14+2560+240 = 2814
      */

     printf("d1=%hd,d2=%hd,d3=%hd\n",d1,d2,d3);



     short e2 = 0234;
     short e3 = 0xaf;
     /**
      * 2*8[2]+3*8[1]+4   + 5*8[-1]=5/8 +4*8[-2]=4/64 + 2*8[-3]=2/512
      * 128+28=156.  0.625+0.0625+0.00390625 = 156.69140625
      *
      *
      *
      * 10*16[1]+15*1 =160+15=175 + 2*16[-1]=2/16 + 3*16[-2]=3/256 + 1*16[3]=1/4096
      * 175 0.125+0.01171875+0.0024449878
      * 175.1391637378
      */



     printf("e2=%hd,e3=%hd\n",e2,e3);

     short f1 = 100;
     /**
      * 100
      * 0110 0100 64
      *
      * 144
      */


     printf("f1=%#ho,f1=%#hx\n",f1,f1);

     short g1 = 0b10100001;
     /**
      * 241
      * a1
      *
      */

     printf("g1=%#ho,g1=%#hX\n",g1,g1);


}

void demo3()
{
    short a = 9;
    short b = 5;

    /***
     * ?????????????????????????
     * 9-5 = 9+(-5) ?????????????
     *0000 0000 0000 1001 ?????????????????????? 9
     *1000 0000 0000 0101 ?????????
     *1111 1111 1111 1010 ??????????
     *1111 1111 1111 1011 ??????????
     *
     *0000 0000 0000 1001 ???? 9
     *1111 1111 1111 1011 ???? -5
     *   1 0000  0000  0000 0100 ???? ????1
     *   0000 0000 0000 0100 ??????????
     *   0000 0000 0000 0100 ????
     *   0000 0000 0000 0100 ???
     */

    printf("%#hX\n",a-b);
    short c = 5;
    short d = 19;

    /**
     * 5-19  5+(-19)????????
     * 0000 0000 0000 0101 5?????
     * 1000 0000 0001 0011 19?????
     * 1111 1111 1110 1100 ????
     * 1111 1111 1110 1101 ????
     *
     * 0000 0000 0000 0101
     * 1111 1111 1110 1101
     * 1111  1111  1111  0010 ???????????油??
     * fff2
     * 1111 1111 1111 0001 ????
     * 1000 0000 0000 1110 ??? ???
     *
     *?ó????????????洢??????????????????????
     */
    printf("%#hX\n",c-d);
    short e = -0x1;
    /**
     * 1000 0000 0000 0001 ???
     * 1111 1111 1111 1110 ????
     * 1111 1111 1111 1111 ????
     * ffff
     */

    printf("%#hX\n",e);

}

void demo4()
{
    float a = 1.0012;
    float b = 0.8e10;//0.8*10??10?η?
    float c = 0.92E-1;//0.92*10??-1?η?
    double d = 0.23e10;//0.23*10??10?η?

    printf("%f\n",a);
    printf("b=%e,b=%f\n",b,b);
    printf("c=%e,c=%f\n",c,c);
    printf("d=%lf,d=%le\n",d,d);
}

void demo5()
{
    char a = 'a';
    char b = 'b';
    putchar(a);
    putchar(b);
    printf("a=%c,b=%c\n",a,b);

    printf("a=%#hX\n",a);

    int c = 65;
    char d = 'q';
    printf("%c,%d,%x\n",c,c,c);
    printf("%c,%d,%x\n",d,d,d);
}

void char_demo6()
{
    char *p = "php is best language";
    char a[] = "一起出去浪！";

    puts(p);
    printf("%s\n",a);
}

//宽字符测试

void wchar()
{
    wchar_t a = L'中';
    wchar_t b = L'国';
    wchar_t c = L'c';

    setlocale(LC_ALL,"zh-CN");
    putwchar(a);
    //wprintf(L"%c\n",b);
    //putwchar(c);

    //wprintf(L"a=%d\n", sizeof(a));
    //wprintf(L"c=%d\n", sizeof(c));
}

//转义字符
void escchar()
{
    char a = '\61';
    char b = '\x31';
    char c = '\x80';

    printf("a=%c,b=%c,c=%c\n",a,b,c);
    char *d1 = "\x31\x32\x33\x61\x62\x63";
    char *d2 = "\x61\x62\x88";

    printf("d1=%s,d2=%s\n",d1,d2);
    printf("\x31\x32\x33\x61\x62\x63");
}

//四则运行测试
void base_operator()
{

    int a = 100;
    short b = 10;
    long c = 9325;

    float d = 12.43;
    double d1 = 1.0921;

    printf("a+b=%d\n",a+b);
    printf("a+c=%ld\n",a+c);
    printf("d+d1=%lf\n",d+d1);

    printf("a+d=%d\n",a+d);
    printf("a+d=%lf\n",a+d);

}

void plusminus()
{
    int a = 10;
    int b = 10;
    --a;
    --b;
    printf("a=%d,b=%d\n",a,b);

    int c = 10;
    int d = 10;
    c++;
    d++;
    printf("c=%d,d=%d\n",c,d);

    //
    int a1 = 20,b1=20,c1=20,d1=20;
    int a2 = ++a1;//21 a1先自增得21，再赋值
    int b2 = --b1;//19 b1先自减得19，再赋值
    int c2 = c1++;//20 c1先赋值给c2,再自增得21
    int d2 = d1--;//20 d1先赋值给d2,再自减得19

    printf("a1=%d,b1=%d,c1=%d,d1=%d\n",a1,b1,c1,d1);
    printf("a2=%d,b2=%d,c2=%d,d2=%d\n",a2,b2,c2,d2);
}

int variable_position_i = 100;
void variable_positaion()
{
    float a = 89.01;
    char *c = "我们转圈圈";
    printf("variable_position_i=%d,a=%hf,c=%s\n",variable_position_i,a,c);
}

int var_init_value_i;
void var_init_value()
{

    float a;
    int b;
    long c;

    printf("var_init_value_i=%d,a=%hf,b=%d,c=%ld\n",var_init_value_i,a,b,c);
}


void printf_function()
{
    char *name1 = "tony";
    int age1 = 100;
    int height1 = 190;

    char *name2 = "jack";
    int age2 = 23;
    int height2 = 170;

    char *name3 = "lucy";
    int age3 = 32;
    int height3 = 160;

    printf("%-9s%-9s%-9s\n","name","age","height");
    printf("%-9s%-9d%-9d\n",name1,age1,height1);
    printf("%-9s%-9d%-9d\n",name2,age2,height2);
    printf("%-9s%-9d%-9d\n",name3,age3,height3);



   /* int n = 234;
    float f = 9.8;
    char c = '@';
    char *str = "http://www.baidu.com";

    //[flag][width][.precision][type]
    //width 不够被空格，超过原样输出
    printf("%10d%12f%4c%8s",n,f,c,str);
*/

    //.precision 整数不够左边加0  超过原样输出
    //小数 够就照样输出，不够就在右边加0
    //字符 够就照样输出，超出原样输出
    /*
    int n = 123456;
    double f = 882.923672;
    char *str = "abcdefghi";
    printf("n: %.9d  %.4d\n", n, n);
    printf("f: %.2lf  %.4lf  %.10lf\n", f, f, f);
    printf("str: %.5s  %.15s\n", str, str);
     */


    /*int n = 123;
    float f = 123.654;
    char *str = "hello";

    printf("%.5d,%.2d\n",n,n);//00123 123
    printf("%.5f,%.1f\n",f,f);//123.65400 123.65

    printf("%.10s,%.3s",str,str);//hello,hel*/

    /*
    int m = 192, n = -943;
    float f = 84.342;
    printf("m=%10d, m=%-10d\n", m, m);  //演示 - 的用法
    printf("m=%+d, n=%+d\n", m, n);  //演示 + 的用法
    printf("m=% d, n=% d\n", m, n);  //演示空格的用法
    printf("f=%.0f, f=%#.0f\n", f, f);  //演示#的用法


     */

    printf("baidu.com\n");

    sleep(5);

    printf("http://www.baidu.com\n");
}


void snake()
{

    COORD coord;
    coord.X = 3;
    coord.Y = 3;

    HANDLE ConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(ConsoleHandler,coord);

    printf("123");
    getchar();
}

void scanf_function()
{
    int a = 0;
    int b = 0;
    int c = 0;
//    int d = 0;
//    printf("please enter your data:\n");
//    scanf("%d\n",&a);
//    scanf("%d\n",&b);
//
//    printf("a+b=%d\n",a+b);
//
//    scanf("%d %d\n",&c,&d);
//    printf("c+d=%d\n",c+d);
//
//      scanf("%d %d",&a,&b);
//      printf("a+b=%d\n",a+b);
//      scanf("%d     %d",&a,&b);
//      printf("a+b=%d\n",a+b);
//
//      scanf("%d,%d,%d",&a,&b,&c);
//      printf("a+b+c=%d\n",a+b+c);
//
//      scanf("%d is bigger than %d",&a,&b);
//      printf("a-b=%d\n",a-b);

//        float age = 0;
//        char name[] = "";
//
//        scanf("%f",&age);
//        scanf("%s",name);
//        printf("your name is %s,and your age is %.2f\n",name,age);

        char author[30];
        char language[30];
        char url[100];
        scanf("%s %s",author,language);
        printf("author=%s,language=%s\n",author,language);
        scanf("%s",url);
        printf("url=%s\n",url);

}

void address()
{
    short int a = 1;//占2个字节
    short int b = 2;
    short int c = 3;

    printf("a=%p,b=%p,c=%p\n",&a,&b,&c);

    //62FDEA 62FDEB 62FDEC 62FDED 62FDEE 62FDEF
}

void getchar_test()
{
    char a;
    a = getchar();
    if (a){
        printf("c=%c\n",a);
    }else{
        printf("please enter a character!");
    }
}


void getche_test()
{
    char a;
    a = getche();
    printf("%c\n",a);
}

void getch_test()
{
    char a;
    a = getch();
    printf("%c\n",a);
}

void gets_test()
{
    char name[30];
    char url[100];

    gets(name);
    gets(url);

    printf("name=%s,url=%s\n",name,url);
}

/**
 * 第一行输出，先到输出缓冲区里待着，然后再和后面的第二行一起输出的 linux是这样的
 * win就不是了
 *
 * 缓冲区【内存】
 * 输出缓冲：当使用printf函数时，它会从输出缓冲区里读取数据，遇到换行符号时，读取结束，并清空缓冲区，数据传递到显示器显示
 * 输入缓冲：当使用scanf函数时，它会从输入缓冲区里读取数据，从第一个地址开始匹配格式式指定的类型，当遇到换行符时，刷新缓冲区，并将数据赋值给变量
 *
 */
void cache_test()
{
//    printf("hello,php");//理论上是输出到缓冲区【内存】
//    sleep(5);
//    printf("nihao,php\n");//遇到换行后一起输出到显示器【硬件】

    printf("%d\n",220*3);
}

void scanf_advance_test()
{

//    int n;
//    float f;
//    char str[23];
//
//    scanf("%2d",&n);//读取指定长度的数字
//    scanf("%*[^\n]");scanf("%*c");//清空缓冲区
//    scanf("%5f",&f);
//    scanf("%*[^\n]");scanf("%*c");
//    scanf("%22s",str);
//
//    printf("n=%10d,f=%10f,str=%s\n",n,f,str);

//      char str[30];
//      char str1[10];
//      scanf("%[abcd]",str);//只读取含有abcd的数据
//      scanf("%*[\n]");scanf("%*c");
//      scanf("%*[^0123456789]",str1);
//      printf("%s\n",str);
//      printf("%s\n",str1);

//    char str[30];
//    int n=0;
//    scanf("%[a-zA-Z]",str);//类似正则  只匹配以小写字母或大写字母
//
//    //scanf("%*[^\n]");scanf("%*c");
//    scanf("%[0-9]",&n);
//    printf("str=%s\n",str);
//    printf("n=%d\n",n);

    //char str1[30];char str2[30];
   // int n;
    //scanf("%[^0-9]",str1);//匹配非数字
    //scanf("%*[^\n]");scanf("%*c");
    //scanf("%[^\n]",str2);//匹配非换行符号
    //scanf("%*[^\n]");scanf("%*c");
    //scanf("%[0-9]",str2);//匹配非换行符号

    //printf("str1=%s,str2=%s\n",str1,str2);

    //scanf("%30[^0-9]",str1);
    //printf("str1=%s\n",str1);

//    scanf("%*d %d",&n);//第一个读取的数字全丢弃  第二个给变量n
//    scanf("%*[a-z]");//所有字母全丢弃清空
//    scanf("%[^\n]",str1);//不是换行符的全部清空丢弃
//
//    printf("n=%d,str1=%s\n",n,str1);



     char str[30];
     char str2[30];
     int n = 0;

//     scanf("%[a-zA-Z]",str);//先从输入缓冲区开始匹配大小写字母
//     scanf("%*[0-9]");//再从缓冲区【指定的位置】开始匹配所有数字
//     scanf("%[a-z]",str2);//再匹配小写字母
//
//     printf("str=%s,str2=%s,n=%d\n",str,str2,n);

//     scanf("%[a-zA-Z]",str);
//     scanf("%*[^\n]");
//     scanf("%[0-9]",&n);
//     printf("your name is %s,and your age is %d\n",str,n);


      char name[10];
      int age;
      char url[100];
      //printf("your name is:\n");
      scanf("%10[a-z]",name);
      //printf("your age is:\n");
      scanf("%d",&age);
      //printf("your url is:\n",url);
      scanf("%[a-z.]",url);

      printf("ok,your info of name is %s,age is %d,url is %s\n",name,age,url);
}

/**
 * 模拟密码输入
 * @param pwd
 * @param pwdlength
 */
void pwd_test(char *pwd,int pwdlength)
{
    char ch = 0;
    int i = 0;

    while(i<pwdlength){

        ch = getche();
        if (ch == '\r'){
            printf("\n");
            break;
        }else if(ch == '\b' && i>0){
            printf("\b \b");
            i--;
        }else if(isprint(ch)){
            pwd[i] = ch;
            printf("*");
            i++;
        }
    }

    pwd[i] = 0;//最后一位
}

void if_test()
{
//    char age = 0;
//    printf("please enter your age");
//    scanf("%d",&age);
//    if (age > 18){
//        printf("ok");
//    }else{
//        printf("no");
//    }

//    int a,b,max;
//    printf("please enter some data:\n");
//    scanf("%d %d",&a,&b);
////    if (a>b)max=a;
////    else max=b;
//
//    //max = (a>b)?a:b;
//    max = b;
//    if(a>b)max=a;
//    printf("max is %d\n",max);

      //int age,score;
     // printf("please enter your age and your score:\n");
      //scanf("%d %d",&age,&score);
//      if (age >18){
//          if (score >=60){
//              printf("ok,u can do it");
//          }else{
//              printf("sorry,u can't do it!");
//          }
//      }else{
//          printf("sorry,u can't use it");
//      }
//     if(age>18 && score >=60){
//         printf("u can do it!");
//     }else{
//         printf("u can not do it!");
//     }
       //if(age>=18&&score>=60)printf("u can do it!");
      // else printf("u can not do it!");

//      int day;
//      while (1){
//          scanf("%d",&day);
//          switch (day){
//              case 1:
//                  printf("Monday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 2:
//                  printf("Tuesday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 3:
//                  printf("Wednesday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 4:
//                  printf("Thurday!\n");
//                  scanf("%d",&day);
//                  break;
//              case 5:
//                  printf("Friday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 6:
//                  printf("Saturday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 7:
//                  printf("Sunday!\n");
//                  scanf("%d",&day);
//                  break;
//              default:
//                  printf("no!\n");
//                  //scanf("%d",&day);
//                  break;
//          }
//      }

      long int i=0;
      while(1){

          printf("%d\n",++i);
          if (i == 100000000){
              break;
          }
      }
}

void ninetonine()
{
    int i;
    int j;
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){

            if ((i-j)<=0){
                printf("%2dx%2d=%2d",i,j,i*j);
            }

        }
        printf("\n");
    }
    getchar();
}

void countCharAndNumAndOther()
{
    printf("please enter some data:\n");
    char str[50];
    scanf("%[a-z]",str);
    scanf("%[A-Z]",str);
    scanf("%[0-9]",str);

}

void square()
{
    int num;
    scanf("%d",&num);
    for(int j=1;j<num;j++){
        if (num/2==j){
            for(int m=num-j;m>0;m--){

               for(int k=m;k>=0;k--){
                   printf(" ");printf("*");
               }
               printf("\n");


            }
        }else if(j<=num/2){

            for(int n=0;n<j;n++){
                printf(" ");printf("*");
            }
            printf("\n");
        }
    }

}

//内存测试  分配内存
void memory_test()
{
    while (1){

        malloc(1024);
    }
}

void array_test1()
{
    int i[5];
    int k;
    for(k=0;k<5;k++){
        i[k] = (k+1);
    }

    for(int j=0;j<5;j++){
        printf("i[%d]=%d\n",j,i[j]);
    }
}

void array_test2()
{
//    int i[5];
//    int k;
//    for(k=0;k<5;k++){
//        scanf("%d",&i[k]);
//    }
//
//    for(int j=0;j<5;j++){
//        printf("i[%d]=%d,i[%d]=%p\n",j,i[j],j,&i[j]);
//    }

     //int k[5] = {1,2,3,4,5};
     //int k[5] = {1,2,4,5};

//     int k[5] = {1,2,3};
//     long int m[5] = {1,2,3};
//     float n[5] = {1.23,1.23};
//     char s[5] = {'d','o'};
//     printf("%d\n",k[4]);
//     printf("%d\n",m[4]);
//     printf("%f\n",n[4]);
//     printf("%c\n",s[4]);

       //int k[] = {1,2,3,4,5,6,7,8};

       //printf("k[5]=%d\n",k[5]);

       int num[2][3] = {{1,2,3},{4,5,6}};
       for(int j=0;j<2;j++){
           for(int k=0;k<3;k++){
                printf("num[%d][%d]=%d,num[%d][%d]=%p\n",j,k,num[j][k],j,k,&num[j][k]);
           }
       }
}

void array_test3()
{
    int n,m;
    int v[3];
    int total;
    //int a[5][3];
    int a[5][3] = {{34,21,66},{87,54,66},{43,65,75},{87,99,100},{100,55,99}};
    int sum;
    int average;

    for(n=0;n<3;n++){
        for(m=0;m<5;m++){
            //scanf("%d",&a[m][n]);//00 10 20 30 40  01 11 21 31 41 02 12 22 32 42
            sum+=a[m][n];//得到每个人的第一个元素
        }
        v[n] = sum/5;
        sum = 0;
    }

    average = (v[0]+v[1]+v[2])/3;
    printf("english is %d,chinese is %d,c language is %d\n",v[0],v[1],v[2]);
    printf("average is %d\n",average);
}

void array_search()
{

    int people[] = {100,200,300,400,500};
    int index;
    scanf("%d",&index);
    int location;
    for(int k=0;k< sizeof(people)/ sizeof(int);k++){
        if (people[k] == index){
            location = k;
            break;
        }
    }

    if (location>0){
        printf("search a people index is %d,and value is %d\n",location,people[location]);
    }else{
        printf("can not search anything!");
    }
}

void array_search1()
{
    int people[] = {100,200,300,400,500};
    int index;
    scanf("%d",&index);
    int location;
    for(int k=0;k< sizeof(people)/ sizeof(int);k++){
        if (people[k] == index){
            location = k;
            break;
        }else if(people[k] >index){
            break;//循环的数值超过键入的值时终止循环  一般用于从小到大有序的数组
        }
    }

    if (location>0){
        printf("search a people index is %d,and value is %d\n",location,people[location]);
    }else{
        printf("can not search anything!");
    }

}

void char_array()
{

//    char name[] = {"小明"};
//    char address[] = "china bejing";
//    printf("name=%s,address=%s,address[0]=%c\n",name,address,address[0]);
//    for(int i=0;i< sizeof(address)/ sizeof(char);i++){
//        printf("address[%d]=%c,address[%d]=%p\n",i,address[i],i,&address[i]);
//    }
//
//    address[1] = 'u';
//    printf("address=%s\n",address);

      char a[6] = "china";//字符串默认会加一个结束标志\0即空字符NULL
      printf("a=%s,a of strlen %d\n",a,strlen(a));
}

void strcat_test()
{
    char str1[100] = "the your website is ";
    char str2[40];

    printf("please enter your website\n");
    gets(str2);
    strcat(str1,str2);
    puts(str1);

}

void strcopy_test()
{
    char str1[100];

    strcpy(str1,"hello,world");
    puts(str1);

}

void insertOrDeleteArray()
{
    int num[10];
    int num1[9];
    int num2[11];

    for(int i=0;i<=10;i++){
        num[i] = i;
    }

    //删除
    for(int j=0;j<=10;j++){
        if (j<6){
            num1[j] = num[j];
        }else if(j>6){
            num1[j-1] = num[j];
        }
    }

    //增加
    for(int k=0;k<=10;k++){
        if (k<7){
            num2[k] = num[k];//0 1 2 3 4 5 6
        }else if(k>7){
            num2[k+1] = num[k];//8
        }else{
            num2[k] = 888;//7
            num2[k+1] = num[k];//8
        }
    }

    //
   for(int n=0;n< sizeof(num)/ sizeof(int);n++){
       printf("num[%d]=%d\n",n,num[n]);
   }
   for(int m=0;m< sizeof(num1)/sizeof(int);m++){
       printf("num1[%d]=%d\n",m,num1[m]);
   }
   for(int z=0;z< sizeof(num2)/sizeof(int);z++){
       printf("num2[%d]=%d\n",z,num2[z]);
   }
}

void outOfArray()
{
    int a[1] = {100};
    //printf("a=%c\n",a[100]);
    //char b[5] = "chinaandhe";

    //printf("b=%s\n",b);
}

//冒泡算法排序
void BubbleArray()
{
    int a[10] = {23,43,76,100,32,54,21,11,98,65};
    int i,j;
    int temp;
    for(i=0;i<10-1;i++){
        for(j=0;j<10-1-i;j++){
            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

            }
        }
    }

    for(int k=0;k<10;k++){
        printf("a[%d]=%d\n",k,a[k]);
    }
}

void array_search_test1()
{
    int a[10] = {12,-98,87,12,34,67,33,66,32,99};
    printf("a[%d]=%d\n",(0+9)/2,a[(0+9)/2]);
}
//二分查找法，要求数据必须是顺序排列的
int array_search2(int key)
{
    int a[10] = {10,30,60,65,70,80,85,88,90,99};
    int low = 0;
    int high = 10-1;
    int mid;
    int midValue;
//    for(int i=0;i<10;i++){
//        printf("%2d",a[i]);
//    }

    while(low<=high){
        mid = (low+high)/2;
        midValue = a[mid];
        if (midValue>key){
            //low = mid+1;
            high = mid-1;
        }else if(midValue<key){
           // high = mid-1;
           low = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

int sum_test()
{
    int i,num=0;
    for(i=1;i<=100;i++){
        num+=i;
    }
    return num;
}

int sum_test1(int m,int n){
    int i,sum=0;
    for(i=m;i<=n;i++){
        sum+=i;
    }
    return sum;
}

long factoria1(int n){
    int i;
    long int result=1;
    for(i=1;i<=n;i++){
        result*=i;
    }
    return result;
}

long sum_test2(int n)
{
    int i;
    long int result=1;
    for(i=1;i<=n;i++){
        result+=factoria1(i);
    }
    return result;
}

long factoria2(int n)
{
    if (n==0||n==1){
        return 1;
    }else{
        return factoria2(n-1)*n;
    }
}

/**
 * 字符串反转 中间递归
 * @param str
 * @return
 */
char *reverse(char *str)
{

    /**
     * 123456789
     * 1、先取第1位放入临时变量
     * 2、将最后一位strlen(123456789)-1放入第1位,同时最后一位len-1=0
     * 3、移到第二位str+1 此时得2345678
     * 4、将前面的第一位放入最后一位
     */

     int len = strlen(str);
     if(len>1){
         char ctemp = str[0];
         str[0] = str[len-1];
         str[len-1] = '\0';
         reverse(str+1);
         str[len-1] = ctemp;
     }
     return str;
}

int sqt(int y)
{
    return ((y)*(y));
}

void test_sqt()
{
    int i=1;
    while(i<=5){
        printf("%d^2=%d\n",(i-1),sqt(i++));
    }
}

void pointer1()
{
    int a=15,b=20,c=30;
    int *p = &a;//指针变量  内存是变量a的地址
    *p = b;//加个指针运算符=变量=b
    c = *p;//指针运算符号获取变量b的内容

    //p = c;

    printf("a=%d,b=%d,c=%d,p=%d\n",a,b,c,*p);
}

void pointer2()
{
    int a=10,b=20,temp;
    int *pa = &a;
    int *pb = &b;

    printf("a=%d,b=%d,pa=%d,pb=%d\n",a,b,*pa,*pb);

    temp = *pa;
    *pa = *pb;
    *pb = temp;

    printf("pa=%d,pb=%d\n",*pa,*pb);
}

/**
 * 指针变量的值进行运算
 */
void pointer3()
{
    int a=10,*pa=&a,*paa=&a;
    int b=20,*pb=&b;
    int c=30,*pc=&c;

    printf("a=%#X,b=%#X,c=%#X\n",&a,&b,&c);
    printf("pa=%#X,pb=%#X,pc=%#X\n",pa,pb,pc);

    //指针变量累加，以4个字节的宽带累加
    pa++;pb++;pc++;
    printf("pa=%#X,pb=%#X,pc=%#X\n",pa,pb,pc);

    pa--;pb--;pc--;
    printf("pa=%#X,pb=%#X,pc=%#X\n",pa,pb,pc);

    if (pa == paa){
        printf("pa==paa\n");
    }else{
        printf("pa!=paa");
    }
}

void array_pointer1()
{
    int a[] = {100,200,300,400,500};
    int len = sizeof(a)/ sizeof(int);
    int i;
    for(i=0;i<len;i++){
        printf("a[%d]=%d,a[%d]=%#X,a[%d]=&%#X,a=%#X\n",i,*(a+i),i,(a+i),i,&a[i],a);
    }
}

void array_pointer2()
{
    int a[] = {100,200,300,500,600};
    int len = sizeof(a)/ sizeof(4);
    int *p = a;
    int i;
    for(i=0;i<len;i++){
        printf("a[%d]=%d,a[%d]=%#X,a[%d]=%d\n",i,*(p+i),i,(p+i),i,p[i]);
    }
}

void array_pointer3()
{
    int a[] = {1,2,3,4,5,6};
    int *p = a+2;//首地址+8个字节【移到数组第二个元素上的位置】

    printf("%d,%d,%d,%d,%d,%d\n",*(p-2),*(p-1),*p,*(p+1),*(p+2),*(p+3));
    printf("%d\n",(*&*&*&*&(&*&*p)[0]+1)+1);
}

void array_char_pointer1()
{
    char name[] = "php is the best in the world!";
    int len = strlen(name),i;
    for(i=0;i<len;i++){
        printf("%c",*&name[i]);
    }
    printf("name=%s\n",name);
    printf("name=%c\n",name[0]);
}

void array_char_pointer2()
{
    char name[] = "php is the best in the world!";
    int len = strlen(name),i;
    char *pname = name;

    for(i=0;i<len;i++){
        printf("%c",(pname+i));
    }

    printf("\n");

    for(i=0;i<len;i++){
        printf("%c",*(pname+i));
    }
    printf("\n");
    for(i=0;i<len;i++){
        printf("%c",pname[i]);
    }
    printf("\n");
    for(i=0;i<len;i++){
        printf("%c",(name+i));
    }
    printf("\n");
    for(i=0;i<len;i++){
        printf("%c",*(name+i));
    }
}


void array_char_pointer3()
{
    char *str = "phpisbestlanguageintheworld!";//字符的首地址为p
    int len = strlen(str),i;

    for(i=0;i<len;i++){
        printf("%c",*(str+i));
    }

    printf("\n");
    for(i=0;i<len;i++){
        printf("%c",str[i]);
    }

    printf("\n");
    for(i=0;i<len;i++){
        printf("%c",*&*&str[i]);
    }

    printf("\n");
    printf("******************************************************\n");
    char *c1 = str;//全部
    char *c2 = str+2;//第3个字符

    char c3 = *str;//第0个字符
    char c4 = str[4];//第5个字符
    char c5 = *(str+6);//第7个字符
    char c6 = *&str[7];//第8个字符

    char c7 = *str+8;//第0个字符+8

    char c8 = (str+1)[5];//

    printf("c1=%s\n",c1);
    printf("c2=%s\n",c2);
    printf("c3=%c\n",c3);
    printf("c4=%c\n",c4);
    printf("c5=%c\n",c5);
    printf("c6=%c\n",c6);
    printf("c7=%c\n",c7);
    printf("c8=%c\n",c8);

}

void swap_pointer1(int *p1,int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int array_max_pointer1(int *num1,int len)
{
    //int maxValue = num1[0];
    int maxValue = *num1;
    int i;
    for(i=1;i<len;i++){
        if(maxValue<num1[i]){
            maxValue = num1[i];
        }
    }
    return maxValue;
}

char *longStr(char *str1,char *str2)
{
    if(strlen(str1) > strlen(str2)){
        return str1;
    }else{
        return str2;
    }
}

int *func_test()
{
    int n = 100;
    printf("n-iner=%d,n=%#X\n",n,&n);
    int *m = &n;
    return m;
}


void more_pointer1() {
    int a = 10;
    /**
     * 变量类型  int
     * 变量名称  a
     * 变量内容  10
     * 变量内存地址【机器地址】  0X001 【假设】
     */
    int *p1 = &a;
    /**
     * 变量类型 int *
     * 变量名称 p1
     * 变量内容 0X001
     * 变量内存地址  0X002
     */
    int **p2 = &p1;
    /**
     * 变量类型 int *
     * 变量名称 p2
     * 变量内容 0X002
     * 变量地址 0X003
     */
    int ***p3 = &p2;
    /**
     * 变量类型 int *
     * 变量名称  p3
     * 变量内容 0X003
     * 变量机器地址  0X004
     */
    int ****p4 = &p3;
    /**
     * 变量类型 int *
     * 变量名称 p4
     * 变量内容 0X004
     * 变量内存地址 0X005
     */

    printf("p1=%d,p2=%d,p3=%d,p4=%d\n", *p1, **p2, ***p3, ****p4);
    printf("a=%#X,p1=%#X,p2=%#X,p3=%#X,p4=%#X\n", &a, p1, p2, p3, p4);//p1=a的内存地址
    printf("a=%#X,p1=%#X,p2=%#X,p3=%#X,p4=%#X\n", &a, &p1, p2, p3, p4);//p2=p1的内存地址
    printf("a=%#X,p1=%#X,p2=%#X,p3=%#X,p4=%#X\n", &a, &p1, &p2, p3, p4);//p3=p2的内存地址
    printf("a=%#X,p1=%#X,p2=%#X,p3=%#X,p4=%#X\n", &a, &p1, &p2, &p3, p4);//p4=p3的内存地址

    printf("p3=%#X\n", p4);//p3的机器地址
    printf("p4=%#X\n", &p4);//p4的机器地址

    printf("p2=%#X\n", p3);//p2的机器地址
    printf("p2=%#X\n", &p2);//p2的机器地址

    printf("p1=%#X\n", p2);//p1的机器地址
    printf("p1=%#X\n", &p1);//p1的机器地址

    printf("p4的内容是p3的机器地址，p3的内容是p2的机器地址，p2的内容是p1的机器地址，p1的内容是a的机器地址\n");

    printf("p2=%#X\n", *p4);//*p4  p4=p3的机器地址【p4的内容】*p4=p3的内容  p3的内容=p2机器地址
    printf("p1=%#x\n", **p4);//**p4=p2的内容，p2的内容=p1的机器地址
    printf("a=%#X\n", ***p4);//p1的内容=变量a的机器地址

    printf("a=%d\n", ****p4);//a的内容

    printf("a=%d\n", *&*&****p4 + 100);

}

/**
 * 程序直接停止
 */
void null_pointer()
{
    char *str;
    gets(str);
    printf("str=%s\n",str);
}

void dynamic_malloc()
{
    char *str = (char *)malloc(sizeof(char)*30);
    gets(str);
    printf("str=%s\n",str);
    str = NULL;
}

void array_noteq_pointer()
{
    int a[6] = {1,2,3,4,5,6};//元素为char类型，共有6个元素，为6个字节
    int *p = a;//a=a[0]的地址，为1个字节

    printf("a=%d\n",*a);
    printf("a=%#X\n",a);
    printf("a=%d\n",*(a+2));//指针加2个字节
    int i;
    for(i=0;i<6;i++){
        printf("a[%d]=%d,a[%d]=%d,a[%d]=%d,a[%d]=%d\n",i,*(a+i),i,p[i],i,*(p+i),i,*&a[i]);
    }

    int len_a = sizeof(a)/sizeof(int);//24/4=6
    int len_b = sizeof(p)/sizeof(int);//4/4=1
    printf("p=%d,int=%d,i=%d\n", sizeof(p), sizeof(int), sizeof(i));
    printf("len_a=%d,len_b=%d,a=%d\n",len_a,len_b, sizeof(&a[0]));

}

void array_item_pointer() {
    int a = 10, b = 20, c = 30;
    int *arr[] = {&a, &b, &c};//每个元素全是指针
    int **parr = arr;//parr保存的是arr的内存地址 *arr保存的是&a的地址

    printf("a[0]=%d\n", *arr[0]);
    printf("parr=%d\n", **parr);

    printf("&a=%#X\n", &a);
    printf("arr=%#X\n", *arr);
    printf("arr=%#X\n", arr);
    printf("parr=%#X\n", parr);


}
/**

 * 数组指针-字符
 */
void char_array_pointer2()
{
    char *lines[5] = {
            "COSC1283/1284",
            "Programming",
            "Techniques",
            "is",
            "great fun"
    };
    char *str1 = lines[1];//取得第2个元素字符串Programming
    char *str2 = *(lines + 3);//先取第4个元素的字符串is  +3取得is
    char c1 = *(*(lines + 4) + 6);//+4后得great fun  +6后得f
    char c2 = (*lines + 5)[5];//先取第1个元素的字符串COSC1283/1284  ,该字符串指针+5=2从2处取5得2
    char c3 = *lines[0] + 2;//取得第1个元素字符串COSC1283/1284 再取1个字符为C,再+2=E
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("  c1 = %c\n", c1);
    printf("  c2 = %c\n", c2);
    printf("  c3 = %c\n", c3);
}

void char_array_pointer12() {
    char *language[] = {
            "php",
            "java",
            "python",
            "chinese",
            "japanese"
    };
    /***
     * language = language[0]的地址 language[0]的内容是php
     *
     */
    printf("language=%s\n", *language);//取得language[0]上的内容

    printf("language=%c\n", (*language)[0]);//取得p

    printf("language=%s\n", *(language + 2));//取python

    printf("language=%c\n", *(*(language + 3) + 5));//取chinese里的s

    printf("language=%c\n", *(*(language + 4)));//取得japanese里的j

    printf("language=%c\n", *((*(language + 4)) + 2));//取得japanese里的p

    printf("language=%c\n", (*(language + 4))[2]);//取得japanese里的p
    printf("language=%c\n", (*(*(language + 4) + 2)));//取得japanese里的p
    printf("language=%c\n", ((language[4])[2]));//取得japanese里的p
    printf("language=%c\n", *&((language[4])[2]));//取得japanese里的p
    printf("language=%c\n", *(*(language + 4) + 2));//取得japanese里的p
    printf("language=%c\n", (*&*&*(*(language + 4) + 2)) + 0);//取得japanese里的p
    printf("language=%c\n", language[4][2]);//取得japanese里的p
    printf("language=%c\n", *&language[4][2]);//取得japanese里的p
    printf("language=%c\n", *(*&language[4] + 2));//取得japanese里的p
    printf("language=%c\n", *(&*(*&language[4] + 2) + 0));//取得japanese里的p
    // printf("language=%s\n",*language[4]);//取得japanese里的p
    printf("language12=%c\n", *&*&*&(language[4][(0b11) - (0b01) + 0b00]));//取得japanese里的p
    printf("language12=%c\n", *&*&*&(language[4][(0x20) - (0x1e) + 0b00]));//取得japanese里的p
    printf("language12=%c\n", *&*&*&(language[4][(002) - (000) + 0b00]));//取得japanese里的p

}
/**
 * 数组名=数组首元素的地址【指针】
 * 数组名=首地址【指针】
 * 数组地址 = 数组名  = 数组首元素地址
 *
 * 数组是一块内存【地址指针】连续的存储空间
 *
 * 数组名=数组首元素的地址【指针】，不是首元素的内容！！！
 */
void pointer_test()
{
    int a[] = {1,2,3,4,5};
    /**
     * 数据类型 int
     * 变量名称 a
     * 变量内容 &a[0] 的地址【指针】
     * 变量机器地址
     */
//     printf("a=%s\n","int");
//     printf("a=%d\n",*a);
//     printf("a[0]=%#X,a[0]=%#X,a[1]=%#X\n",a,&a[0],&a[1]);
//     printf("a=%#X\n",&a);

       // printf("a=%#X,a=%#X,a=%#X\n",a,&a[0],&a);
        //int *b = &a;
       // printf("a=%d,a=%d,a=%d\n",*a,*&a[0],*b);

//     if(*&a == *a == a[0] == *&a[0]){
//         printf("equal");
//     }else{
//         printf("not equal\n");
//         printf("*&a=%d,*a=%d,a[0]=%d,*&a[0]=%d\n",*(&a),*a,a[0],*&a[0]);
//     }

        int a1 = 10,b1=20,c1=30;
       int *b[] = {&a1,&b1,&c1};

       /**
        * *b[0] = &a1
        * 变量名称b[0]
        * 变量内容 &a1地址
        * 变量类型 int
        * 变量机器址
        *
        *
        * *b[1] = &b2
        * *b[2] = &b3
        *
        * b = &b[0]
        */
       /**
        * 数据类型 int 8
        * 变量名称 b
        * 变量内容 = 首元素地址
        * 变量机器地址 = 首元素地址
        */
       int **c = b;

       printf("a=%#X\n",&a1);
       printf("b=%#X,b=%#X,b=%#X,c=%#X\n",b,&b,&b[0],c);

       printf("b[0]=%#X,b[0]=%#X\n",b[0],&a1);
       int k;
       printf("*******************************************************\n");
       printf("a1=%d,b1=%d,c1=%d\n",a1,b1,c1);
       printf("&a1=%#X,&b1=%#X,&c1=%#X\n",&a1,&b1,&c1);
       //for(k=0;k<3;k++){
           printf("b=%d,b[0]=%d,b[1]=%d,b[2]=%d\n",*b,*b[0],*b[1],*b[2]);
           printf("&b=%#X,&b[0]=%#X,&b[1]=%#X,b[2]=%#X\n",b,b[0],b[1],b[2]);
           printf("b=%#X,b[0]=%#X,b[1]=%#X,b[2]=%#X\n",&b,&b[0],&b[1],&b[2]);
       //}

       printf("&c=%#X,c=%#X,a1=%#X\n",c,*c,&a1);//c=b=&b[0] *(&b[0]) 取b[0]上的内容=&a1

       printf("c=%#X,c=%#X,c=%#X,c=%#X\n",&c,c,b,&b[0]);

       for(k=0;k<3;k++){
           printf("c[%d]=%d\n",k,**(c+k));
       }

       printf("***********************************************************\n");
       int d1 = 100;
       int d2 = 200;
       int d3 = 300;

       int *d[] = {&d1,&d2,&d2};//d = &d[0] = d[0]的内容&d1
       int **e[] = {&d[0],&d[1],&d[2]};//e = &e[0] e[0]的内容&d[0] = &d1
       int ***f[] = {&e[0],&e[1],&e[2]};//f = &f[0] f[0]的内容&e[0] = &d[0] = &d1

       printf("d=%#x,d[0]=%#X,d=%#X,d=%#X\n",d,&d[0],*e,**f);//e=e[0]的机器地址 *e获得e[0]上的内容，它的内容是d[0]的机器地址
       //f=f[0]的机器地址 *f获取f[0]上的内容，它的内容是e[0]的机器地址 **f 则是获取e[0]的内容，它的内容是d[0]的机器地址

       //获取最后一个元素的真实内容
       printf("d[2]=%d\n",*d[2]);//d[2]得到的内容是&d2的机器地址,*d[2]获得的是d2的内容
       printf("d[2]=%d\n",**e[2]);//e[2]的内容是d[2]的机器址，*e则是获取d[2]的内容，d[2]的内容是d2的机器址，**e[2]则是获取d2的内容
       printf("d[2]=%d\n",***f[2]);//f[2]的内容是e[2]的机器地址 *f[2]则是获取e[2]的内容，e[2]的内容是d[2]的机器地址，**f[2]则是获取
       //d[2]的内容，d[2]的内容是d3的机器地址，***f[2]则是获取d3上机器地址对应的内容


       



}

void char_array_pointer()
{
    char *lines[5] = {
            "COSC1283/1284",
            "Programming",
            "Techniques",
            "is",
            "great fun"
    };
    char *str1 = lines[1];//取得第2个元素字符串Programming
    char *str2 = *(lines + 3);//先取第4个元素的字符串is  +3取得is
    char c1 = *(*(lines + 4) + 6);//+4后得great fun  +6后得f
    char c2 = (*lines + 5)[5];//先取第1个元素的字符串COSC1283/1284  ,该字符串指针+5=2从2处取5得2
    char c3 = *lines[0] + 2;//取得第1个元素字符串COSC1283/1284 再取1个字符为C,再+2=E
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("  c1 = %c\n", c1);
    printf("  c2 = %c\n", c2);
    printf("  c3 = %c\n", c3);
}

void char_array_pointer1()
{
    char *language[] = {
            "php",
            "java",
            "python",
            "chinese",
            "japanese"
    };
    /***
     * language = language[0]的地址 language[0]的内容是php
     *
     */
    printf("language=%s\n",*language);//取得language[0]上的内容

    printf("language=%c\n",(*language)[0]);//取得p

    printf("language=%s\n",*(language+2));//取python

    printf("language=%c\n",*(*(language+3)+5));//取chinese里的s

    printf("language=%c\n",*(*(language+4)));//取得japanese里的j

    printf("language=%c\n",*((*(language+4))+2));//取得japanese里的p

    printf("language=%c\n",(*(language+4))[2]);//取得japanese里的p
    printf("language=%c\n",(*(*(language+4)+2)));//取得japanese里的p
    printf("language=%c\n",((language[4])[2]));//取得japanese里的p
    printf("language=%c\n",*&((language[4])[2]));//取得japanese里的p
    printf("language=%c\n",*(*(language+4)+2));//取得japanese里的p
    printf("language=%c\n",(*&*&*(*(language+4)+2))+0);//取得japanese里的p
    printf("language=%c\n",language[4][2]);//取得japanese里的p
    printf("language=%c\n",*&language[4][2]);//取得japanese里的p
    printf("language=%c\n",*(*&language[4]+2));//取得japanese里的p
    printf("language=%c\n",*(&*(*&language[4]+2)+0));//取得japanese里的p
    printf("language=%s\n",*language[4]);//取得japanese里的p
    printf("language12=%c\n",*&*&*&(language[4][(0b11)-(0b01)+0b00]));//取得japanese里的p
    printf("language12=%c\n",*&*&*&(language[4][(0x20)-(0x1e)+0b00]));//取得japanese里的p
    printf("language12=%c\n",*&*&*&(language[4][(002)-(000)+0b00]));//取得japanese里的p

}

void array_two_dimesion_pointer()
{
    //int a[] = {1,2,3,4};
    //a[0] = 1
    //a = &a[0]

    //int *pa = a;
    //printf("a=%#X,pa=%#X,a=%#X\n",a,&a[0],pa);

    int a[3][4] = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12}
    };

    //a=&a[0]
    printf("a=%#X,a=%#X\n",a,&a[0]);

    //a[0] = &a[0][0]

    printf("a[0]=%#X,a[0]=%#X\n",a[0],&a[0][0]);

    //a = &a[0] == &a[0][0]

    /**
     * 变量名称 a
     * 变量类型 int
     * 变量内容 &a[0]机器地址
     * 变量地址  0x01
     */

    /**
     * 变量名称 a[0]
     * 变量类型 int
     * 变量内容 &a[0][0] 机器地址
     * 变量地址 0x02
     */

    /**
     * 变量名称a[0][0]
     * 变量内容 1
     * 变量类型 int
     * 变量机器址 0x03
     */
    printf("a=%d\n",**a);

    int (*p)[4] =a;//a = &a[0] a[0] = {1,2,3,4}
    printf("a[0]=%d\n", sizeof(p[1]));
    printf("a[0]=%d\n", (*p)[1]);
    printf("a[0]=%d\n", *(*(p+1+1)+1));


    /**
     * 指针变量  标量  一个变量来在存储一个内存地址
     * 指针数组       一个数组来存储多个内存地址
     * 二维数组指针    一个数组来存储多个元素，每个元素又是一个数组
     */
    printf("*****************************************************************\n");
    printf("a=%#X,a[0]=%#X,a[0]=%d,a[]=%d,a[0]=%d,a[0]=%d\n",p,&a[0], sizeof(p),sizeof(&a[0]), sizeof(p[0]), sizeof(a[0]));//p = &a[0] a[0] = &a[0][0]
    printf("a=%#X,a[1]=%#X,a[0]=%d,a[]=%d\n",p+1,&a[1], sizeof(p+1), sizeof(&a[1]));

    int k;
    int j;
    for(k=0;k<3;k++){
        for(j=0;j<4;j++){
            printf("a[%d][%d]=%d,a[%d][%d]=%#X\n",k,j,*(*(p+k)+j),k,j,(p+k)+j);
        }
    }
    printf("*****************************************************************\n");
    printf("a=%d\n", sizeof((p)[0]));
    printf("a=%d\n", sizeof(p[0][2]));

    printf("a[1]=%#X,a[1]=%#X\n",(p+1),&a[1]);//(p+1)  p+1=a[1]数组的机器地址
    printf("a[1]=%#X,a[1]=%#X\n",*(p+1),&a[1][0]);     //*p+1 表示获取 a[1]上的内容，a[1]=a[1][0]的机器地址
    printf("a[1]=%d,a[1]=%d\n",*(*(p+1)+0),a[1][0]);//取5
    printf("a[1]=%d\n",*&a[1][0]);//取5

    printf("a[1]=%d\n",**(p+1));//取5

    printf("a[1]=%d\n",*(*(p+1)+(0b00000010-0b00000010)));//取5

    //取6
    printf("a[2]=%d\n",*(*(p+1)+1));//*(p+1) = a[1][0] 的机器地址
    printf("a[2]=%d\n",*(*(p+1)+0X01));//取6
    printf("a[2]=%d\n",a[1][1]);//取6
    printf("a[2]=%d\n",*&a[1][1]);//取6
    printf("a[2]=%d\n",*(*((p+2)-1)+2-0b01));//取6
    printf("a[2]=%d\n",*(&a[1][0]+1));//取6
    printf("a[2]=%d\n",*&a[1][0]+1);//取6
    printf("a[2]=%d\n",*&a[0][0]+*&a[1][0]);//取6
    printf("a[2]=%d\n",*&a[1][3]-*&a[0][1]);//取6
    printf("a[2]=%d\n",**(p+1)+1);//取6
    printf("a[2]=%d\n",*(&**(p+1)+1));//取6
    printf("a[2]=%d\n",*&*&*(&**(p+1)+1));//取6
    printf("a[2]=%d\n",*(*(p+2+1-2)+1)-(1+0b01)+*(*(p+0)+1));//取6
    printf("a[2]=%d\n",*(*(p+0)+3)+**p+**p);//取6
    printf("a[2]=%d\n",**p*6);//取6
    printf("a[2]=%d\n",*&**p**(*(p+1)+1));//取6
    printf("a[2]=%d\n",(**p+**p)***p***p***p+*(*(p+0)+3));//取6
    printf("a[2]=%d\n",**p***p***p***p**(*(p+1)+1));//取6
    printf("a[2]=%d\n",*&*&**p***p***p***p**&*&*&*&*(*(p+1)+1));//取6
    printf("a[2]=%d\n",**p**&*(*(p+1)+1)*1*1*1*1*1*1***p);//取6
    printf("a[2]=%d\n",**p+**p+**p+**p+**p+**p***p***p);//取6
    printf("a[2]=%d\n",*&**p+*&**p+*&*&**p+*&*&*&**p+**p+**p***p***p);//取6
    printf("a[2]=%d\n",*((a[1])+1));//取6
    printf("a[2]=%d\n",*((&*&*&*&*&*&*&*a[1])+1));//取6
    printf("a[2]=%d\n",(**p+**p)*(**p+**p***p+**p***p));//取6

    printf("a[2]=%d\n",p);//p = &a[0] *a[0] = &a[0][0]



}

int maxTest(int y,int x)
{
    return y>x?y:x;
}

/**
 * 指针函数
 * @param y
 * @param x
 * @return
 */
int *minTestN(int y,int x)
{
    int *temp;
    if(y<x){
        temp = &y;
    }else{
        temp = &x;
    }
    return temp;
}

char *testChar(int **p)
{
    char *px;
    px = "hello,china";
    return px;
}

int testInt1(int *b)
{
    printf("%d\n",*b);

}

int *testInt(int *b)
{
    int c1=10,c2=20,c3=30,c4=40,c5=50;
    int *f[5] = {&c1,&c2,&c3,&c4,&c5};
    //return f;

}
