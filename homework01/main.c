#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

int main()
{
    int gs = 1;
    int num = 0;
    system("cls");
    while (gs)
    {
        
        title();
        printf("number -> ");
        scanf("%d", &num);
        if (num == 1)
        {
            system("cls");
            Start();
            gs = 0;
        }
        else if (num == 2)
        {
            system("cls");
            while (gs)
            {
                Guide();
                printf("number -> ");
                scanf("%d", &num);
                if (num == 1)
                {
                    system("cls");
                    break;
                }
                else if (num == 2)
                {
                    num=2;
                    system("cls");
                }
                else
                {
                    while(gs)
                    {
                        system("cls");
                        printf("wrong number\n");
                        break;
                    }          
                }
            }
        }
        else if (num == 3)
        {
            gs = 0;
        }
        else
        {
            system("cls");
            printf("wrong number\n");
        }
    }

    return 0;
}