//
// Created by  on 2019/5/29.
//

#include <stdio.h>

int main()
{
    int a[40];
    a[0] = 0;
    a[1] = 1;
    int i;
    for(i=2;i<40;i++){
        a[i] = a[i-1]+a[i-2];//1+0 a[2]=1 1+1
        printf("%d\n",a[i]);
        printf("%#x\n",a[i]);
    }
    return 0;
}
