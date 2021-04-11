//
// Created by Administrator on 2011/4/1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[50];
    int age;
    int num;
    char address[100];
} PERSON;

long insert();
long fSize(FILE *file);
int getMenuid();
void removeUser();
void updateUser();
void listUser();
char *fileName = "E:/c/viewc/persondata.txt";
char *tempFileName = "E:/c/viewc/persond_temp.txt";
int menuid;
FILE *file;
FILE *tmpFileHandle;
int main()
{

    while (1){
        menuid = getMenuid();
        switch(menuid){
            case 0:
               exit(0);
                break;
            case 1:
                insert();
                break;
            case 2:
                listUser();
                break;
            case 3:
                removeUser();
                break;
            case 4:
                updateUser();
                break;
            default:


                break;
        }
    }
    fclose(file);
    return 0;
}


void listUser()
{

    if(file == NULL){
        file = fopen(fileName,"rb+");
    }
    fseek(file,0,SEEK_SET);
    PERSON tempPerson;
    PERSON *tmp = &tempPerson;
    int readCount = 0;
    printf("+%#5s----%5s+%5s---%5s+%5s---%5s+%5s-------%5s+\n","\x2D","\x2D","\x2D","\x2D","\x2D","\x2D","\x2D","\x2D");
    printf("|%5sName%5s+%5sAge%5s+%5sNum%5s+%5sAddress%5s+\n","\x20","\x20","\x20","\x20","\x20","\x20","\x20","\x20");
    if (ftell(file)>0){
        fseek(file,0,SEEK_SET);
    }
    while((readCount=fread(tmp, sizeof(struct person),1,file))>0){
        printf("|***%s***|***%d***|***%d***|***%s***|\n",tmp->name,tmp->age,tmp->num,tmp->address);
    }

    printf("+-------+-------+-------+-------+\n");
}

int getMenuid()
{
    int menuid;

    printf("[1]:add person\n");
    printf("[2]:list person\n");
    printf("[3]:remove person\n");
    printf("[4]:update person\n");

    scanf("%d",&menuid);
    fflush(stdin);
    return menuid;
}



long insert()
{
    PERSON person;

    PERSON *per = &person;
    PERSON tempPerson;

    PERSON *tmp = &tempPerson;

    char *tempName = NULL;

    int readCount = 0;

    file = fopen(fileName,"rb+");
    printf("please enter person info!\n");
    scanf("%s %d %d %s",per->name,&per->age,&per->num,per->address);

    long Size = fSize(file);
    fseek(file,Size,SEEK_SET);
    fwrite(&person, sizeof(struct person),1,file);

    menuid = 2;
}

long fSize(FILE *file)
{
    long n;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fseek(file,0,SEEK_END);
    n = ftell(file);
    fsetpos(file,&fpos);
    return n;
}

void removeUser()
{
    printf("input username who u want to remove\n");
    char temp[50];
    fflush(stdin);
    scanf("%s",temp);
    PERSON tempPerson;
    int readCount=0;
    int nBytes = 0;
    if(temp){
        file = fopen(fileName,"rb+");
        tmpFileHandle = fopen(tempFileName,"wb+");
        fseek(file,0,SEEK_SET);
        fseek(tmpFileHandle,0,SEEK_SET);
        while((readCount=fread(&tempPerson, sizeof(struct person),1,file))>0){
            nBytes+=readCount;
            if (strcmp(temp,tempPerson.name) != 0){
                fwrite(&tempPerson,sizeof(struct person),1,tmpFileHandle);
            }
        }

        fclose(tmpFileHandle);

        //读取临时文件复制到原来的文件完成删除功能
        tmpFileHandle = fopen(tempFileName,"rb+");
        file = fopen(fileName,"wb+");
        fseek(tmpFileHandle,0,SEEK_SET);
        fseek(file,0,SEEK_SET);
        PERSON tmp;
        readCount = 0;
        while((readCount=fread(&tmp, sizeof(struct person),1,tmpFileHandle))>0){
            fwrite(&tmp,sizeof(struct person),1,file);
        }

    }

    menuid = 2;

}

void updateUser()
{
    char name[50];
    printf("input username:\n");
    scanf("%s",name);
    int readCount;
    tmpFileHandle = fopen(tempFileName,"wb+");
    file = fopen(fileName,"rb+");
    fseek(tmpFileHandle,0,SEEK_SET);
    fseek(file,0,SEEK_SET);
    PERSON tempPerson;
    PERSON data;
    int find = 0;
    while((readCount=fread(&tempPerson, sizeof(struct person),1,file))>0){
       if(strcmp(name,tempPerson.name)==0){
           find = 1;
           printf("please input user info:\n");
           scanf("%s %d %d %s",data.name,&data.age,&data.num,data.address);
           fwrite(&data, sizeof(struct person),1,tmpFileHandle);
       }else{
           fwrite(&tempPerson, sizeof(struct person),1,tmpFileHandle);
       }
    }

    fclose(tmpFileHandle);
    if (find == 0){
        printf("sorry,not found this user!\n");

    }else{
        //复制文件

        tmpFileHandle = fopen(tempFileName,"rb+");
        file = fopen(fileName,"wb+");
        fseek(file,0,SEEK_SET);
        fseek(tmpFileHandle,0,SEEK_SET);
        PERSON tmp;
        while((readCount=fread(&tmp, sizeof(struct person),1,tmpFileHandle))>0){
            printf("update:%s",tmp.name);
            fwrite(&tmp, sizeof(struct person),1,file);
        }
        printf("update userinfo ok!\n");

    }

    menuid = 2;
}
