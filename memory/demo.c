//
// Created by Administrator on 2019/4/21.
//

#include <stdio.h>
/**
 * cpu运行原理大概说明
 * 计算机所有的数据都保存在内存【在运行的时候会加载到内存】
 * 内存：由大量的寄存器构成
 * 寄存器：由大量的触发器构成
 * 触发器：由大量的门电路【逻辑门电路】构成，一个触发器具有记忆一位二进制的能力
 * 门电路：由大量的电子元件构成【集成芯片】构成大规模的逻辑门电路，如与门，或，非，与非，与或，与或非，异或门等
 * 门电路的构成完成了大量的逻辑信号处理
 * 具备开发功能的电子元件：二极管，三极管，CMOS管，开为高电平，关为低电平逻辑状态为1和0
 * 电子元件的材料：硅，锗
 * 导电特性：半导体，输入不同的电压使元件输出不同的结果如三极具有截止【关】，饱和【关】的功能
 * 数字电路的分析：借助逻辑函数，逻辑表达式，逻辑代数，逻辑图，逻辑电路等
 *
 * 数字电路分类：组合逻辑电路，时序逻辑电路【具有记忆功能】
 * 数字电路能完成的功能：逻辑运算，移位，算术运算，编码，译码等
 *
 * CPU[ALU+寄存器组+状态寄存器等】
 * cpu从内存【指令或叫程序寄存器里取出指令/程序二进制1为高电平0为低电平】，取出的指令输入到
 * 指令寄存器里【寄存器具有存储二进制的功能，如RS触发器】，指令译码器【如3/8译码器，4/16译码器就是将
 * 输入的二进制信号转换为多位的二进制，如000得到00000000 001得到00000001 这种玩意】
 * 指令译码器电路运行后得到结果
 *
 * 译码器译码的二进制信号会传输到【会送ALU（ALU具有逻辑运算的电路，由大量的逻辑门电路构成）】ALU逻辑电路进行处理
 * 处理的结果会保存在状态寄存器【结果】会写到内存
 *
 * 而指令寄存器和数据寄存器【通用计算机就一根内存条保存】单片机单独装，有自己的寻址总线
 *
 * 总线：数据总线，控制总线，控制总线
 *
 *
 * cpu在时钟脉冲电路【时钟电路驱动】下，从指令寄存器【它存储了用户编写的大量二进制信号】，每来一个脉冲就取一条指令
 * 【有一个程序计数器电路计数】，然后译码，并保存在工作寄存器组，最终送入到逻辑门电路的【ALU】
 *
 * 处理的结果最终是保存在各类寄存器【内存】，其它设备再从内存获取数据
 *
 * 指令：一串二进制，大量的指令构成指令系统，ALU逻辑电路运行后会输出不同的结果
 * 编译：将源码转换为指令【不同的二进制组合，就是数字信号，输入不同的电平，会输出不同的结果】
 *
 * 所有的指令全部经过强大复杂的ALU逻辑运算单元处理【具体里面有上百万的集成逻辑电路构成】
 *
 * 逻辑电路：能进行逻辑运算的电路 如与门电路
 *
 * cpu由时钟电路驱动执行指令，在时钟的上升沿或下降沿执行指令，如果指令占用一个方波
 * 就是单周期指令[一个时钟周期就是一个上升沿到下降沿的过程|---|___高电平变化低电平就是一个时钟周期]
 *
 * 存储器的空间：00000000 000000 ~ffffffff ffffffff=4294967295/1000=4294967kb
 * 4294967kb/1000/4294MB=4G
 *
 */
struct test{
    int a;
    char b;
    int c;
}t={1,'c',2};
int main(void)
{
//    int a = 10;
//    int b = 20;
//    printf("a=%#X,b=%#X\n",&a,&b);
//    /**
//     * 打印变量的内存地址并不是真的内存物理地址，而是虚拟地址，会由操作系统管理内存完成
//     * 相互切换
//     *
//     * 程序运行时，操作系统会完成虚拟地址和物理的内存映射
//     */

     //内存地址 对齐
     printf("%d,%d,%d,%d\n", sizeof(t.a), sizeof(t.b), sizeof(t.c), sizeof(t));
     printf("%#X,%#X,%#X,%#X\n", &t.a, &t.b, &t.c, &t);

     //变量内存对齐测试
     int k=0;
     char m='c';
     int n=2;
     printf("%d,%d,%d\n", sizeof(k), sizeof(m), sizeof(n));
     printf("%#X,%#X,%#X\n",&k,&m,&n);
    return 0;
}