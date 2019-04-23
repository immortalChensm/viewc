//
// Created by Administrator on 2019/4/17.
//

#include <stdio.h>

int main()
{
    //
    int a = -8;//打印的结果
    /**
     * 1000 0000 0000 0000 0000 0000 0000 1000
     * 1111 1111 1111 1111 1111 1111 1111 0111
     * 1111 1111 1111 1111 1111 1111 1111 1000
     *
     * f     f    f    f    f    f    f 8
     */


    printf("a=%#X\n",a);


    //测试5-9的结果 = 5+(-9)

    int b = 5;
    int c = 9;
    /**
     * 00000000 00000000 00000000 0000 0101
     * 10000000 00000000 00000000 0000 1001
     * 11111111 11111111 11111111 1111 0110
     * 11111111 11111111 11111111 1111 0111
     *
     * 1111111 111111111 11111111 1111 0100
     *
     * 1111111 111111111 1111111 1111 0011
     * 1000000 000000000 0000000 0000 1100
     *
     * ff       ff        ff    fc
     *
     */

    printf("5-9=%#X\n",b-c);

    //与运算
    int d1 = 0Xf0;//1111 0000
    int d2 = 0x18;//0001 1000
    //0001 0000 = 0x10
    printf("%#X\n",d1&d2);

    int d3 = 0xf5;//1111 0101
    int d4 = 0x87;//1000 0111
    //1111 0111 f7
    printf("%#X\n",d3|d4);

    /**
     * 1111 0101
     * 1000 0111
     * 0111 0010  0x72
     */
     printf("%#X\n",d3^d4);

     //取反
     /**
      * 1111 0101
      * 0000 1010
      * 0x0a
      */
     printf("d3=%#X\n",~d3);

     //左移
     d3 = 0xf5;//00000000 00000000 00000000 1111 0101
     //00000000 00000000 00000111 1010 1000 0x7a8
     int d5 = d3<<3;//1111 0101  左移动3位  1010 1000 0xa8
     printf("%#X\n",d5);

     //右移

     int d8 = 0x99;//
     /**
      * 00000000 00000000 00000000 1001 1001 右边移动3位
      * 00000000 00000000 00000000 0001 0011 0x13
      */
      printf("%#X\n",d8>>3);
    return 0;
}