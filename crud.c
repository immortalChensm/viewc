
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
long fSize(FILE *file);
long addContentToFile(FILE *targetFile,char *buffer,long offset);

int main()
{
    char *FileName = "E:/c/demo/crud.txt";
    FILE *target = fopen(FileName,"wb");



    return 0;
}
long addContentToFile(FILE *targetFile,char *buffer,long offset)
{

    FILE *tmpFile;
    char *tmpFileName = "E:/c/demo/crud.txt";
    tmpFile = fopen(tmpFileName,"wb");

    int bufferLen = 1024*4;
    char *buffer = (char *)malloc(bufferLen);
    int readCount = 0;

    if (offset<0){
        while(1){
            if (readCount=fread(buffer,1,bufferLen,targetFile)>0){
                fwrite(buffer,readCount,1,tmpFile);
            }
        }
    }

    fseek(targetFile,offset,SEEK_SET);
    fwrite(buffer, sizeof(char),strlen(buffer),targetFile);
    fclose(targetFile);
    return 1;

}

/**
 * 获取文件的大小，返回字节数
 * @param file
 * @return int
 */
long fSize(FILE *file)
{
    long size=0;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fseek(file,0,SEEK_END);
    size = ftell(file);
    fsetpos(file,&fpos);
    return size;
}
