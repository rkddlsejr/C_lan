#include <stdio.h>
#include "screen.h"

int clear(char* screen, int width, int height)
{
    int w = 0; // 가로
    int h = 0; // 세로

    while (h < height)
    {
        while (w < width)
        {
            if (h == 0 || h == (height - 1))
            {
                screen[w + (h * (width + 1))] = '=';
            }
            else if (w == 0 || w == (width - 1))
            {
                screen[w + (h * (width + 1))] = '|';
            }
            else
            {
                screen[w + (h * (width + 1))] = ' ';
            }
            w += 1;
        }
        screen[w + (h * (width + 1))] = '\n';
        w = 0;
        h += 1;
    }
    screen[width + 1 + (height * (width + 1))] = '\0';

    return 0;
}

int write(const char* string, char* screen, int width, int w, int h)
{
    int index = w + (h * (width + 1)); // 인덱스 계산

    int i = 0;

    while (string[i] != '\0')
    {
        screen[index + i] = string[i];
        i += 1;
    }

    return 0;
}

int title(char* screen, int width, int height)
{
    write("/ / /",screen,width,23,5);
    write("/   / /                  W W W",screen,width,21,6);
    write("/   /   /   A            W       W",screen,width,19,7);
    write("/   /   /       \\        W         |",screen,width,17,8);
    write("/   /   /           \\    W           |",screen,width,15,9);
    write("/   /   /               \\W             |",screen,width,13,10);
    write("W   /   /    Elman War   W  \\            |",screen,width,11,11);
    write("W   W   /                W      \\          |",screen,width,9,12);
    write("W   W                W          \\        |",screen,width,11,13);
    write("W   W                W              \\      |",screen,width,9,14);
    write("W                    W                  \\    |",screen,width,7,15);
    write("W                      W                    \\  |",screen,width,5,16);
    write("W                    \\|",screen,width,30,17);
    write("W--------------------",screen,width,32,18);
    write("1. Game Start",screen,width,20,22);
    write("2. Game Story",screen,width,20,24);
    write("3. Exit",screen,width,20,26);

    return 0;
}

int enterk()
{
    char ch = ' ';
    getchar();
    printf("\n");
}

int story()
{ 
    enterk();
    printf("-----다음 문장으로 넘기려면 엔터키를 누르세요.-----");
    enterk();
    printf("옛날부터 인간과 엘프는 친구처럼 지내왔다.");
    enterk();
    printf("하지만 어느날 엘프의 왕이 죽었다는 소식이 들려온 후 엘프들은 이상해지기 시작했다.");
    enterk();
    printf("마치 우리가 알던 엘프는 온데간데 없고\n우리를 죽이려는 마음으로만 가득찬 것처럼 보였다.");
    enterk();
    printf("그들은 갑자기 우리를 공격하기 시작했다.");
    enterk();
    printf("친구처럼 지내던 엘프들이 갑자기 공격하자 사람들은 당황을 금치 못했다.");
    enterk();
    printf("대화를 시도해보려는 사람들...");
    enterk();
    printf("도망치는 사람들...");
    enterk();
    printf("맞서 싸우는 사람들..!!");
    enterk();
    printf("나의 친구들, 가족들도 그 개자식들에게 당했다.");
    enterk();
    printf("나는 반드시 엘프새끼들을 다 죽여버리고 말 것이다!!");
    enterk();

    printf("\n\n게임을 시작하시겠습니까?\n\n");
    printf("1. 예            2. 메인메뉴");

    return 0;
}