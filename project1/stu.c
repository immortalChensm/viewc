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
    if ((file=fopen(FILENAME,"rb+"))==NULL&&(file=fopen(FILENAME,"wb+"))==NULL){
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
    //stuIndex ��һ���������ڴ�  stuIndex[����] *stuIndex+��������ƶ�ָ��
    for(i=0;i<stuCount;i++){
        if (stu.id == *(stuIndex+i)){
            pause("ѧ���Ѿ�����");
            return ;
        }else if (stu.id>stuIndex[i]){
            ++stuPos;
        }else{
            break;
        }
    }

    finsert(file,stuPos*stuSize,&stu,stuSize);
    updateIndex();
    pause("��ӳɹ��������������...");
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

    if (index<0){
        pause("û���ҵ�ѧ��...");
        return ;
    }else{
        fdelete(file,index*stuSize,stuSize);
    }
    updateIndex();
    pause("ɾ���ɹ��������������...");

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

    if (index<0){
        pause("�Ҳ���ѧ����...");
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
    pause("�޸ĳɹ��������������...");

}

void findStuById()
{
    STU stu;
    int i;
    int index=-1;
    float allTotal=0;
    getStuId(&stu.id);
    for(i=0;i<stuCount;i++){
        if(stu.id == *(stuIndex+i)){
            index=i;
        }else if(stu.id<stuIndex[i]){
            break;
        }
    }
    if (index<0){
        pause("û��ѧ����...");
        return ;
    }else{
        fseek(file,index*stuSize,SEEK_SET);
        fread(&stu,stuSize,1,file);
        allTotal=stu.en+stu.math+stu.zh;
        printf("--------------------------------------------------------------------\n");
        printf("  ѧ��  |  ����  |  ����  |  �Ա�  |  ��ѧ  |  ����  |  Ӣ��  |  �ܳɼ�  |\n");
        printf("--------+--------+--------+--------+--------+------------+-------+---------+\n");
        printf("  %.2d     | %-6s  |  %-3d    |  %-6s | %-6.2f | %-6.2f | %-6.2f | %-6.2f |\n",stu.id,stu.name,stu.age,stu.sex,stu.math,stu.zh,stu.en
                ,allTotal);
        printf("--------------------------------------------------------------------\n");
    }

    pause("�����������...");


}

void findStuByName()
{
    STU stu;
    int n=0;
    float total=0;
    char name[20];
    getStuName(name);
    fseek(file,0,SEEK_SET);
    while(fread(&stu,stuSize,1,file)){
        if (strstr(stu.name,name)){
            n++;
            total = stu.en+stu.zh+stu.math;
            if (n==1){
                printf("--------------------------------------------------------------------\n");
                printf("  ѧ��  |  ����  |  ����  |  �Ա�  |  ��ѧ  |  ����  |  Ӣ��  |  �ܳɼ�  |\n");
                printf("--------+--------+--------+--------+--------+------------+-------+---------+\n");
                printf("  %.2d     | %-6s  |  %-3d    |  %-6s | %-6.2f | %-6.2f | %-6.2f | %-6.2f |\n",stu.id,stu.name,stu.age,stu.sex,stu.math,stu.zh,stu.en
                        ,total);
                printf("--------------------------------------------------------------------\n");
            }
        }
    }
    if (n>0){
        pause("���ҵ�%d����¼�������������...",n);
    }else if(n==0){
        pause("û���κμ�¼�������������...");
    }
}

/**
 * ��ȡ������Χ���ж���Сֵ�����ֵ��
 *
 * @param flag
 */
void findByScores(int flag)
{
    STU stu;
    float total=0;
    int n=0;
    char *courseName = NULL;
    float *scores = NULL;
    int MAX = 0;
    int min=0,max=0;
    if(flag==FIND_BY_MATH){
        courseName = "��ѧ";
        scores = &stu.math;
        MAX = STU_MAX_MATH;
    }else if(flag == FIND_BY_ZH){
        courseName = "����";
        scores = &stu.zh;
        MAX = STU_MAX_ZH;
    }else if(flag == FIND_BY_EN){
        courseName = "Ӣ��";
        scores = &stu.zh;
        MAX = STU_MAX_ZH;
    }else if(flag == FIND_BY_TOTAL){
        courseName = "�ܳɼ�";
        scores = &total;
        MAX = STU_MAX_MATH+STU_MAX_EN+STU_MAX_ZH;
    }

    while(1){
        printf("������Ŀ %s \n",courseName);
        fflush(stdin);
        scanf("%d %d",&min,&max);
        if (min<0||min>MAX||max<0||max>MAX){
            pause("����ķ�Χ����,%s�ķ�Χ%d~%d",courseName,min,max);
            continue ;
        }
        if (min>max){
            pause("��ͷֳ�������߷�,���������������...");
            continue;
        }
        break;
    }

    fseek(file,0,SEEK_SET);
    while(fread(&stu,stuSize,1,file)){
        total=stu.math+stu.en+stu.zh;
        if (min<=*scores&&*scores<=max){
            n++;
            if (n==1){
                printf("--------------------------------------------------------------------\n");
                printf("  ѧ��  |  ����  |  ����  |  �Ա�  |  ��ѧ  |  ����  |  Ӣ��  |  �ܳɼ�  |\n");
                printf("--------+--------+--------+--------+--------+------------+-------+---------+\n");
                printf("  %.2d     | %-6s  |  %-3d    |  %-6s | %-6.2f | %-6.2f | %-6.2f | %-6.2f |\n",stu.id,stu.name,stu.age,stu.sex,stu.math,stu.zh,stu.en
                        ,total);
                printf("--------------------------------------------------------------------\n");
            }
        }
    }

    if (n>0){
        pause("�ҵ�%dѧ��,�����������...",n);
    }else if(n==0){
        pause("û���ҵ���¼�������������...");
    }

}
void getStuId(int *id)
{
    while(1){
        printf("������ID\n");
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
        printf("����������\n");
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
        printf("����������\n");
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
        printf("�������Ա�\n");
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
        printf("��������ѧ\n");
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
        printf("����������\n");
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
        printf("������Ӣ��\n");
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
    if(strcmp(sex,"��")&&strcmp(sex,"Ů")){
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
        pause("��ʱû������...");
        return ;
    }

    fseek(file, 0, SEEK_SET);
    system("cls");
    printf("--------------------------------------------------------------------\n");
    printf("  ѧ��  |  ����  |  ����  |  �Ա�  |  ��ѧ  |  ����  |  Ӣ��  |  �ܳɼ�  |\n");
    printf("--------+--------+--------+--------+--------+------------+-------+---------+\n");
    while(fread(&stu,stuSize,1,file)){
        allTotal+=stu.math+stu.zh+stu.en;
        totalStu+=allTotal;
        mathTotal+=stu.math;
        zhTotal+=stu.zh;
        enTotal+=stu.en;
        ageTotal+=stu.age;
        n++;
        if (strcmp(stu.sex,"��")){
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
    pause("\n����%d��ѧ��,�����������...",stuCount);


}