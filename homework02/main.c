#include "screen.h"

int main()
{
    int gs = 1;
    int num = 0;
    int num2 = 0;
    int t = 0;

    while (gs)
    {
        if (t == 0)
        {
            title();
            scanf("%d", &num);
            t = 1;
        }

        if (num == 1)
        {
            gamest();
        }
        else if (num == 2)
        {
            rule();
            scanf("%d",&num2);
            if (num2 == 1)
            {
                num = 1;
            }
            else if (num2 == 2)
            {
                exit(0);
            }
            else
            {
                Setpos(0,30);
                printf("다시 입력해주세요.       ");
                Sleep(1000);
                choice();
                scanf("%d", &num);
            }
        }
        else if (num == 3)
        {
            exit(0);
        }
        else
        {
            Setpos(0,30);
            printf("다시 입력해주세요.        ");
            Sleep(1000);
            choice();
            scanf("%d", &num);
        }
    }

    return 0;
}