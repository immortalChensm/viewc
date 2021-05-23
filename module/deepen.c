
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdarg.h>
typedef struct _STUS
{
    int id;
    char name[10];
    int age;
    int num;
}STU;
long getFileSize(FILE *file);
void write(char *fileName,struct _STUS student1);
void copyTest(char *fileName);
void test();
long copy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetSet);
int main()
{
    STU student1;
    student1.id = 100;
    char *name = "tony";
    student1.name[0] = 't';
    student1.age = 18;
    student1.num = 1;

    char *fileName = "E:/c/viewc/module/deepen.txt";
    char *fileName1 = "E:/c/viewc/module/deepen111.txt";

    //write(fileName,student1);
    //copyTest(fileName);
    FILE *readFileHandle = fopen(fileName,"rb+");
    //FILE *readFileHandle1 = fopen(fileName1,"wb+");
    if (readFileHandle==NULL){
        printf("无法打开文件!\n");
        exit(0);
    }
    int k=0;
    int readCount=0;
    while((readCount=fread(&student1, sizeof(struct _STUS),1,readFileHandle))>0){
        printf("student.name[0]=%c\n",student1.name[0]);
    }
    fclose(readFileHandle);

    fseek(readFileHandle,sizeof(struct _STUS),SEEK_END);

//    char *tmp = (char *)malloc(1024*4);
//    fseek(readFileHandle,5*sizeof(struct _STUS),SEEK_SET);
//    fseek(readFileHandle1,5*sizeof(struct _STUS),SEEK_SET);
//    int readCount=0;
//    for(i=0;i<10;i++){
//        readCount = fread(tmp,1,1024,readFileHandle);
//        if(readCount>0){
//            printf("name=%c\n",student1.name[0]);
//            fwrite(tmp,readCount,1,readFileHandle1);
//        }
//
//    }




    return 0;
}

void test()
{
    /***********************************************************/
//    typedef struct _STU{
//        int id;  //学号 4
//        char name[20];  //姓名 20
//        char sex[4];  //性别 4
//        int age;  //年龄 4
//        float math;  //数学成绩 4
//        float cn;  //语文成绩 4
//        float en;  //英语成绩 4
//    }STU;

    //int a = 5*44;
    //int b = 1024*4;
    //int n = ceil((double)((double)a/b));
    //printf("a/b=%d\n",n);
    //printf("stu=%d,float=%d\n", sizeof(struct _STU), sizeof(int));
}

void copyTest(char *fileName)
{
    FILE *readFileHandle = fopen(fileName,"rb+");
    if (readFileHandle==NULL){
        printf("无法打开文件!\n");
        exit(0);
    }
    //FILE *tmpFile = fopen("E:/c/viewc/module/deepen1.txt","wb+");
    FILE *tmpFile = tmpfile();

    if (tmpFile==NULL){
        printf("无法创建临时文件!\n");
        exit(0);
    }

    if(copy(readFileHandle,0,5* sizeof(struct _STUS),tmpFile,0)){
        printf("first copy to tmpfile ok\n");
    }

    STU student2;
    student2.id = 102;
    student2.name[0] = 'k';
    student2.age = 18;
    student2.num = 1;

    if(fwrite(&student2,sizeof(struct _STUS),1,tmpFile)){
        printf("add ok\n");
    }
    //printf("readFileHandle=%d,tmpFile=%d\n",ftell(readFileHandle),ftell(tmpFile));
    if(copy(readFileHandle,5* sizeof(struct _STUS),-1,tmpFile,5* sizeof(struct _STUS)+sizeof(struct _STUS))){
        printf("two copy to tmpfile ok\n");
    }


    freopen(fileName,"wb+",readFileHandle);
    if(copy(tmpFile,0,-1,readFileHandle,0)){
        printf("copy to readFileHandle ok\n");
    }

    fclose(readFileHandle);
    fclose(tmpFile);

}
void write(char *fileName,struct _STUS student1)
{
        FILE *file = fopen(fileName,"wb+");
    if (file!=NULL){
        int i;
        for(i=0;i<10;i++){
            student1.id = i;
            fwrite(&student1, sizeof(struct _STUS),1,file);
        }
    }

    fclose(file);
}
long getFileSize(FILE *file)
{
    long fsize;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fseek(file,0,SEEK_END);
    fsize = ftell(file);
    fsetpos(file,&fpos);
    return fsize;
}

long copy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetSet)
{
    int bufferLen = 1024*4;
    char *buffer = (char *)malloc(bufferLen);
    fseek(sourceFile,offset,SEEK_SET);
    fseek(targetFile,targetSet,SEEK_SET);
    long nBytes=0;
    int readCount=0;

    int i,n;
    if (len<0){
        while((readCount=fread(buffer,1,bufferLen,sourceFile))>0){
            fwrite(buffer,bufferLen,1,targetFile);
            nBytes+=readCount;
        }
    }else{
        n = (int)ceil((double)((double)len/bufferLen));
        for(i=1;i<=n;i++){
            if(len-nBytes<bufferLen)bufferLen=len-nBytes;
            readCount = fread(buffer,1,bufferLen,sourceFile);
            fwrite(buffer,bufferLen,1,targetFile);
            nBytes+=readCount;
        }

    }
    fflush(targetFile);
    free(buffer);
    return nBytes;
}
