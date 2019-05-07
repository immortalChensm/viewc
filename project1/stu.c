//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "common.h"
#include "stu.h"
#include "tool.h"
void init()
{
    if ((file=fopen(FILENAME,"wb+"))==NULL&&(file=fopen(FILENAME,"rb+"))==NULL){
        pause("Error on open %s file",FILENAME);
        exit(EXIT_FAILURE);
    }

    fileSize = getFileSize(file);
    stuSize = sizeof(STU);
    stuCount = fileSize/stuSize;
    stuIndex = NULL;
    updateIndex();
}

void updateIndex()
{
    free(stuIndex);
    stuIndex = (int *)malloc(stuCount*stuSize);
    stuCount = getFileSize(file)/stuSize;
    int i;
    for(i=0;i<stuCount;i++){
        fseek(file,i*stuSize,SEEK_SET);
        fread(&stuIndex[i], sizeof(int),1,file);
    }
}

void addStu()
{
    STU stu;
    getStuId(&stu.id);
    getStuName(stu.name);
    getStuAge(&stu.age);
    getStuSex(stu.sex);
    getStuMath(&stu.math);
    getStuZh(&stu.zh);
    getStuEn(&stu.en);
//    printf("stu.id=%d\n",stu.id);
//    printf("stu.name=%s\n",stu.name);
//    printf("stu.sex=%s\n",stu.sex);
//    printf("stu.age=%d\n",stu.age);
//    printf("stu.math=%f\n",stu.math);
//    printf("stu.zh=%f\n",stu.zh);
//    printf("stu.en=%f\n",stu.en);

    int i;
    int stuPos=0;
    //stuIndex 是一块连续的内存  stuIndex[索引] *stuIndex+索引编号移动指针
    for(i=0;i<stuCount;i++){
        if (stu.id == *(stuIndex+i)){
            pause("学生已经存在");
            return ;
        }else if (stu.id>stuIndex[i]){
            ++stuPos;
        }else{
            break;
        }
    }

    finsert(file,stuPos*stuSize,&stu,stuSize);
    updateIndex();
    pause("添加成功！按任意键返回...");
}

void removeStu()
{
    STU stu;
    getStuId(&stu.id);
    int i;
    int index=-1;
    for(i=0;i<stuCount;i++){
        if (stu.id==*(stuIndex+i)){
            index=i;
        }else if(stu.id<stuIndex[i]){
            break;
        }
    }

    if (index<=0){
        pause("没有找到学生...");
        return ;
    }else{
        fdelete(file,index*stuSize,stuSize);
    }
    updateIndex();
    pause("删除成功！按任意键返回...");

}

void alterStu()
{
    STU stu;
    getStuId(&stu.id);
    int i,index=-1;
    for(i=0;i<stuCount;i++){
        if (stu.id==*(stuIndex+i)){
            index = i;
        }else if(stu.id<stuIndex[i]){
            break;
        }
    }

    if (index<=0){
        pause("找不到学生哩...");
        return ;
    }else{
        getStuName(stu.name);
        getStuSex(stu.sex);
        getStuAge(&stu.age);
        getStuMath(&stu.math);
        getStuZh(&stu.zh);
        getStuEn(&stu.en);

        fseek(file,index*stuSize,SEEK_SET);
        fwrite(&stu,stuSize,1,file);
    }
    pause("修改成功！按任意键返回...");

}
void getStuId(int *id)
{
    while(1){
        printf("请输入ID\n");
        fflush(stdin);
        scanf("%d",id);
        if (checkStuId(*id)){
            break;
        }
    }
}

void getStuName(char name[])
{
    while(1){
        printf("请输入姓名\n");
        fflush(stdin);
        scanf("%s",name);
        if (checkStuName(name)){
            break;
        }
    }
}

void getStuAge(int *age)
{
    while(1){
        printf("请输入年龄\n");
        fflush(stdin);
        scanf("%d",age);
        if (checkStuAge(*age)){
            break;
        }
    }
}


void getStuSex(char sex[])
{
    while(1){
        printf("请输入性别\n");
        fflush(stdin);
        scanf("%s",sex);
        if (checkStuSex(sex)){
            break;
        }
    }
}

void getStuMath(float *math)
{
    while(1){
        printf("请输入数学\n");
        fflush(stdin);
        scanf("%f",math);
        if (checkStuMath(*math)){
            break;
        }
    }
}

void getStuZh(float *zh)
{
    while(1){
        printf("请输入语文\n");
        fflush(stdin);
        scanf("%f",zh);
        if (checkStuZh(*zh)){
            break;
        }
    }
}

void getStuEn(float *en)
{
    while(1){
        printf("请输入英文\n");
        fflush(stdin);
        scanf("%f",en);
        if (checkStuEn(*en)){
            break;
        }
    }
}
int checkStuId(int stdId)
{
    if(stdId<0||stdId>STU_MAX_ID){
        return 0;
    }else{
        return 1;
    }
}

int checkStuName(char name[])
{
    if (strlen(name)<0||strlen(name)>STU_MAX_NAME){
        return 0;
    }else{
        return 1;
    }
}
int checkStuAge(int age)
{
    if (age<0||age>STU_MAX_AGE){
        return 0;
    }else{
        return 1;
    }
}

int checkStuSex(char sex[])
{
    if(strcmp(sex,"男")&&strcmp(sex,"女")){
        return 0;
    }else{
        return 1;
    }
}

int checkStuMath(float math)
{
    if (math<0||math>STU_MAX_MATH){
        return 0;
    }else{
        return 1;
    }
}

int checkStuZh(float zh)
{
    if(zh<0||zh>STU_MAX_ZH){
        return 0;
    }else{
        return 1;
    }
}

int checkStuEn(float en)
{
    if (en<0||en>STU_MAX_EN){
        return 0;
    }else{
        return 1;
    }
}

void showAllStu() {
    STU stu;
    int manTotal = 0, womanTotal = 0;
    float ageTotal=0, mathTotal=0, zhTotal=0, enTotal=0,allTotal=0,totalStu=0;
    int n=0;
    if (stuCount <= 0) {
        pause("暂时没有数据...");
        return ;
    }

    fseek(file, 0, SEEK_SET);
    system("cls");
    printf("--------------------------------------------------------------------\n");
    printf("  学号  |  姓名  |  年龄  |  性别  |  数学  |  语文  |  英文  |  总成绩  |\n");
    printf("--------+--------+--------+--------+--------+------------+-------+---------+\n");
    while(fread(&stu,stuSize,1,file)){
        allTotal+=stu.math+stu.zh+stu.en;
        totalStu+=allTotal;
        mathTotal+=stu.math;
        zhTotal+=stu.zh;
        enTotal+=stu.en;
        ageTotal+=stu.age;
        n++;
        if (strcmp(stu.sex,"男")){
            womanTotal++;
        }else{
            manTotal++;
        }

        printf("  %.2d     | %-6s  |  %-3d    |  %-6s | %-6.2f | %-6.2f | %-6.2f | %-6.2f |\n",stu.id,stu.name,stu.age,stu.sex,stu.math,stu.zh,stu.en
        ,allTotal);
    }
    printf("--------+--------+--------+--------+--------+------------+-------+---------+\n");
    printf("  ---   |  ----  | %-6.2f  |  %2d/%2d    | %-6.2f | %-6.2f | %-6.2f | %-6.2f |\n",ageTotal/stuCount,womanTotal,manTotal,mathTotal/stuCount,zhTotal/stuCount,enTotal/stuCount,totalStu/stuCount);
    printf("---------------------------------------------------------------------------\n");
    pause("\n共有%d个学生,按任意键返回...",stuCount);


}