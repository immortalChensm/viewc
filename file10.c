
#include <stdio.h>
#define N 3
struct stu{
    char name[30];
    int num;
    int age;
    float score;
}stus[N],stu,*pstu;
int main()
{
    FILE *file;
    char *fileName = "E:/c/demo/hello.txt";
    pstu = stus;
    file = fopen(fileName,"rb+");
    if(file == NULL){
        printf("not found file!");
    }

    int i=0;
    for(i;i<N;i++,pstu++){
        fscanf(stdin,"%s %d %d %f\n",pstu->name,&pstu->num,&pstu->age,&pstu->score);
    }

    pstu = stus;

    fwrite(pstu, sizeof(struct stu),N,file);
    //指针定位  文件指针  获取某位置的数据
    fseek(file, sizeof(struct stu)*2,SEEK_SET);

    fread(&stu, sizeof(struct stu),N,file);

   fprintf(stdout,"%s %d %d %f\n",stu.name,stu.num,stu.age,stu.score);
    return 0;
}
