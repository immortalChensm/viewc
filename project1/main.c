//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"
#include "stu.h"
/**
 *
 * �ļ��ĸ���
 * �ڴ渴��
 * readByte=fread(buffer,1,size,file)���ļ�����1����СΪsize������
 *
 * fwrite(buffer,size=readByte,1,file)  ��1����Сsize=readCount�����ݲ��뵽�ļ���
 */


char printfMainMenu();
char printfChildMenu();
int main()
{
    int MenuId;
    init();
    while (1){
       MenuId = printfMainMenu();
       switch (MenuId){
           case '1':addStu();break;
           case '2':removeStu();break;
           case '3':alterStu();break;
           case '4':
                while (1){
                    MenuId = printfChildMenu();
                    switch(MenuId){
                        case '1':
                            findStuById();
                            break;
                        case '2':
                            findStuByName();
                            break;
                        case '3':
                            findByScores(FIND_BY_MATH);
                            break;
                        case '4':
                            findByScores(FIND_BY_ZH);
                            break;
                        case '5':
                            findByScores(FIND_BY_EN);
                            break;
                        case '6':
                            findByScores(FIND_BY_TOTAL);
                            break;
                    }
                    if (MenuId=='0')break;
                }
               break;
           case '5':showAllStu();break;
           case '0':exit(EXIT_SUCCESS);
       }
    }
    return 0;
}

char printfMainMenu()
{
    char MenuId;
    system("cls");
    printf("*******************weclome to use student management system(there are %d students)*******************\n",stuCount);
    printf("*                                                                                                         *\n");
    printf("*                   ________________________________________                                              *\n");
    printf("*                   |    powered by 1655664358@qq.com      |                                              *\n");
    printf("*                   ----------------------------------------                                              *\n");
    printf("*                                                                                                         *\n");
    printf("*                   1)���ѧ��                                                                               \n");
    printf("*                   2)ɾ��ѧ����Ϣ(����ѧ��)                                                                   \n");
    printf("*                   3)�޸�ѧ����Ϣ(����ѧ��)                                                                   \n");
    printf("*                   4)��ѯѧ����Ϣ                                                                           \n");
    printf("*                   5)ѧ���б�                                                                               \n");
    printf("*                   0)�˳����                                                                              \n");
    printf("*                                                                                                         \n");
    printf("***********************************************************************************************************\n");
    fflush(stdin);
    MenuId = getch();
    return MenuId;
}

char printfChildMenu()
{
    char menuId;
    system("cls");
    printf("*********************************************��ѯ��Ϣ(����%d��ѧ��)************************************************\n",stuCount);
    printf("*                                                                                                              *\n");
    printf("*                                            1)ѧ�Ų�                                                           *\n");
    printf("*                                            2)������                                                           *\n");
    printf("*                                            3)��ѧ������                                                           *\n");
    printf("*                                            4)���ķ�����                                                           *\n");
    printf("*                                            5)Ӣ�ķ�����                                                           *\n");
    printf("*                                            6)�ֲܷ�                                                           *\n");
    printf("*                                            0)�˳�                                                           *\n");
    fflush(stdin);
    menuId = getch();
    return menuId;
}