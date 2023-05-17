#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

int main()
{
    int gs = 1;
    int num = 0;
    int num2 = 0;
    int t = 0;
    
    while(gs)
    {
        if(t==0)
        {
            system("cls");
            title();
            printf("숫자를 입력해주세요. -> ");
            scanf("%d",&num);
            t=1;
            gs=1;
        }

        if(num==1)
        {
            system("cls");
            start();
            break;
        }
        else if(num==2)
        {
            system("cls");
            story();
            printf("\n숫자를 입력하세요. : ");
            scanf("%d",&num2);
            while(gs)
            {
                if(num2==1)
                {
                    num=1;
                    break;
                }
                else if(num2==2)
                {
                    t=0;
                    break;
                }
                else
                {
                    printf("잘못 입력하셨습니다. 다시 입력해주세요.");
                    scanf("%d",&num2);
                }
            }
        }
        else if(num==3)
        {
            system("cls");
            gs = 0;
        }
        else
        {
            printf("잘못 입력하셨습니다. 다시 입력해주세요.");
            scanf("%d",&num);
        }
    }

    return 0;
}