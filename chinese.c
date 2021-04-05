

#include <stdio.h>

void main()
{
    int a[5] = {1,2,3,4,5};

    int *ptr = (int *)(&a-1);//a = &a[0] &a=[12345]

    printf("%d %d\n",*(a+1),*(ptr));
    printf("a[0]=%#X\n",&a[0]);
    printf("a[1]=%#X\n",&a[1]);
    printf("a[2]=%#X\n",&a[2]);
    printf("a[3]=%#X\n",&a[3]);
    printf("a[4]=%#X\n",&a[4]);


    printf("a=%#X\n",&a);
    printf("a=%#X\n",&a-1);
    printf("a=%#X\n",&a[0]-1);
    printf("a=%#X\n",&a[4]+1);

    int *temp = (int *)(&a-1);
   temp = (int *)(&temp+1);

   int *t = (&a-1);
   
    printf("%d\n",*temp);
    printf("%d\n",*t);

}
