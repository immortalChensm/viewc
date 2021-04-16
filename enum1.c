//
// Created by Administrator on 2016/4/17.


#include <stdio.h>
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 8
int main()
{
    int day;
    scanf("%d",&day);

    switch (day)
    {
        case MONDAY:
            printf("%s\n","MONDAY");
            break;
        case TUESDAY:
            printf("%s\n","TUESDAY");
            break;
        case WEDNESDAY:
            printf("%s\n","WEDNESDAY");
            break;
        case THURSDAY:
            printf("%s\n","THURSDAY");
            break;
        case FRIDAY:
            printf("%s\n","FRIDAY");
            break;
        case SATURDAY:
            printf("%s\n","SATURDAY");
            break;
        case SUNDAY:
            printf("%s\n","SUNDAY");
            break;
        default:
            printf("%s\n","nothing");
            break;
    }
getchar();
    return 0
}
