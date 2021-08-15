
#include <stdio.h>
#include <stdlib.h>

int main()
{

    char buffer[9];
    char *text = "hello,world";
    char *key = "12345";

    printf("%#X\n",*text ^ *key);
    int encodeText = (*text ^ *key);
    int decodeText = (encodeText ^ *key);

    printf("text=%d\t\t%7s\n",*text,itoa(*text,buffer,2));
    printf("encodeText=%d\t\t%7s\n",encodeText,itoa(encodeText,buffer,2));
    printf("decodeText=%d\t\t%s\n",decodeText,itoa(decodeText,buffer,2));
printf("decodeText=%d\t\t%s\n",decodeText,atoi(decodeText,buffer,2));
    return 1;
}
