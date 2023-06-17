#include "screen.h"

int money = 500000;
int slv = 1;
int sell_m = 0;

void textcolor(int color) // 글씨 색 조절 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clear(char* screen, int width, int height) // 테두리 안쪽 비워주는 버퍼
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
}

void border() // 테두리 크기조절과 출력
{
    int width = 77;
    int height = 30;
    char screen[78 * 30 + 1];
    system("cls");
    clear(screen, width, height);
    printf("%s",screen);
}

void Setpos(int x, int y) // 글씨 출력 좌표 설정
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void delay(char* string) // 출력 딜레이 이용해서 애니메이션 효과
{
    for (char* p = string; *p != '\0'; p++)
    {
        putchar(*p);
        fflush(stdout);
        Sleep(1);
    }
    putchar('\n');
}

void enterk() // 엔터키 입력받기
{
    char ch = ' ';
    getchar();
}

void RemoveCursor() // 애니메이션 출력 때 커서 깜빡임 없애기
{
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    cursor.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void choice() // 선택 문장 출력
{
    Setpos(0,30);
    printf("숫자를 입력해주세요. : ");
}

void title() // 타이틀 출력
{
    border();
    RemoveCursor();
    textcolor(4);
    Setpos(7,1);
    delay("______");
    Setpos(22,1);
    delay("_");
    Setpos(32,1);
    delay("_");
    Setpos(7,2);
    delay("| ___ \\");
    Setpos(21,2);
    delay("(_)");
    Setpos(31,2);
    delay("| |");
    Setpos(7,3);
    delay("| |_/ /  __ _  _  _ __  | |__    ___  __      __ ");
    textcolor(14);
    Setpos(7,4);
    delay("|    /  / _` || || '_ \\ | '_ \\  / _ \\ \\ \\ /\\ / /");
    Setpos(7,5);
    delay("| |\\ \\ | (_| || || | | || |_) || (_) | \\ V  V / ");
    textcolor(10);
    Setpos(7,6);
    delay("\\_| \\_| \\__,_||_||_| |_||_.__/  \\___/   \\_/\\_/ ");
    textcolor(9);
    Setpos(30,7);
    delay("_____");
    Setpos(64,7);
    delay("_");
    Setpos(29,8);
    delay("/  ___|");
    textcolor(1);
    Setpos(63,8);
    delay("| |");
    Setpos(29,9);
    delay("\\ `--. __      __  ___   _ __   __| |");
    Setpos(30,10);
    delay("`--. \\\\ \\ /\\ / / / _ \\ | '__| / _` |");
    textcolor(13);
    Setpos(29,11);
    delay("/\\__/ / \\ V  V / | (_) || |   | (_| |");
    Setpos(29,12);
    delay("\\____/   \\_/\\_/   \\___/ |_|    \\__,_|");
    textcolor(7);
    Setpos(26,13);
    delay("____________________");
    Setpos(26,14);
    delay("\\");
    Setpos(45,14);
    delay("/");
    Setpos(27,15);
    delay("\\");
    Setpos(44,15);
    delay("/");
    Setpos(28,16);
    delay("\\______________/");
    Setpos(32,17);
    delay("_|");
    Setpos(36,17);
    delay("|_");
    Setpos(31,18);
    delay("/________\\");
    textcolor(15);
    Setpos(1,19);
    printf("---------------------------------------------------------------------------");
    Setpos(31,22);
    printf("1. 게임 시작");
    Setpos(31,24);
    printf("2. 게임 설명");
    Setpos(31,26);
    printf("3. 게임 종료");
    choice();
}

void rule() // 게임 규칙 출력
{
    border();
    Setpos(19,5);
    printf("=====================================");
    Setpos(19,6);
    printf("|엔터키를 누르면 다음 줄이 나옵니다.|");
    Setpos(19,7);
    printf("=====================================");
    enterk();
    Setpos(3,10);
    printf("당신은 대장장이입니다. 검을 강화해서 부자가 되어보세요!");
    enterk();
    Setpos(3,12);
    printf("스페이스 바를 검을 강화할 수 있습니다.");
    enterk();
    Setpos(3,14);
    printf("검의 등급이 높을 수록 많은 돈을 받을 수 있습니다.");
    enterk();
    Setpos(3,16);
    printf("무지개검을 만들면 게임이 끝나게 됩니다.");
    Setpos(1,19);
    printf("---------------------------------------------------------------------------");
    Setpos(31,23);
    printf("1. 게임 시작");
    Setpos(31,25);
    printf("2. 게임 종료");
    choice();
}

void gamest() // 게임 상황 함수
{
    int gamestate = 0;
    while(1)
    {
        border();
        sword_lv();
        Setpos(2,3);
        printf("돈 : %d원",money);
        Setpos(1,19);
        printf("---------------------------------------------------------------------------");
        Setpos(5,24);
        printf("1. 강화하기        2. 판매하기       3. 아이템      4. 게임종료");
        choice();
        scanf("%d", &gamestate);
        if (gamestate==1)
        {
            switch(slv)
            {
                case 1:
                    enforce_1();
                    break;
                case 2:
                    enforce_2();
                    break;
                case 3:
                    enforce_3();
                    break;
                case 4:
                    enforce_4();
                    break;
                case 5:
                    enforce_5();
                    break;
                case 6:
                    enforce_6();
                    break;
                case 7:
                    enforce_7();
                    break;
                case 8:
                    enforce_8();
                    break;
                case 9:
                    end_screen();
                    break;
            }
        }
        else if (gamestate==2)
        {
            money = money + sell_m;
            slv = 1;
            gamest();
        }
        else if (gamestate==3)
        {
            item();
            int itemstate = 0;
            choice();
            scanf("%d", &itemstate);
            switch(itemstate)
            {
                case 1:
                    if (money >= 50000)
                    {
                        slv = 3;
                        money = money - 50000;
                        sword_lv();
                        gamest();
                    }
                    else if (money < 50000)
                    {
                        Setpos(0,30);
                        printf("돈이 부족합니다.        ");
                        Sleep(1000);
                        gamest();
                    }
                    break;
                case 2:
                    if (money >= 500000)
                    {
                        slv = 5;
                        money = money - 500000;
                        sword_lv();
                        gamest();
                    }
                    else if (money < 500000)
                    {
                        Setpos(0,30);
                        printf("돈이 부족합니다.        ");
                        Sleep(1000);
                        gamest();
                    }
                    break;
                case 3:
                    if (money >= 1000000)
                    {
                        slv = 6;
                        money = money - 1000000;
                        sword_lv();
                        gamest();
                    }
                    else if (money < 1000000)
                    {
                        Setpos(0,30);
                        printf("돈이 부족합니다.        ");
                        Sleep(1000);
                        gamest();
                    }
                    break;
                case 4:
                    if (money >= 10000000)
                    {
                        slv = 8;
                        money = money - 10000000;
                        sword_lv();
                        gamest();
                    }
                    else if (money < 10000000)
                    {
                        Setpos(0,30);
                        printf("돈이 부족합니다.        ");
                        Sleep(1000);
                        gamest();
                    }
                    break;
                default:
                    Setpos(0,30);
                    printf("다시 입력해주세요.        ");
                    Sleep(1000);
                    choice();
                    scanf("%d", &gamestate);
                    break;
            }
        }
        else
        {
            Setpos(0,30);
            printf("다시 입력해주세요.       ");
            Sleep(1000);
        }
    }
}

void item() // 아이템 목록
{
    Setpos(1,19);
    printf("---------------------------------------------------------------------------");
    Setpos(5,24);
    printf("1. 3lv로 패스 : 50000원     2. 5lv로 패스 : 500000원              ");
    Setpos(5,26);
    printf("3. 6lv로 패스 : 1000000원     4. 8lv로 패스 : 10000000원             ");
}

void sword_lv() // 검 강화 레벨에 따른 출력들
{
    switch(slv)
    {
        case 1:
            Setpos(2,5);
            printf("강화 확률 : 90%%");
            sword1();
            break;
        case 2:
            Setpos(2,5);
            printf("강화 확률 : 80%%");
            sword2();
            break;
        case 3:
            Setpos(2,5);
            printf("강화 확률 : 70%%");
            sword3();
            break;
        case 4:
            Setpos(2,5);
            printf("강화 확률 : 60%%");
            sword4();
            break;
        case 5:
            Setpos(2,5);
            printf("강화 확률 : 50%%");
            sword5();
            break;
        case 6:
            sword6();
            Setpos(2,5);
            printf("강화 확률 : 40%%");
            break;
        case 7:
            sword7();
            Setpos(2,5);
            printf("강화 확률 : 30%%");
            break;
        case 8:
            sword8();
            Setpos(2,5);
            printf("강화 확률 : 20%%");
            break;
        case 9:
            end_screen();
            Sleep(2000);
            exit(0);
            break;
    }
}

void enforce_1() // 검 강화 함수
{
    int random[101]; // 랜덤 범위

    int i = 1;

    srand((unsigned int)time(NULL)); // 랜덤값 설정

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 91)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                        ");
        Sleep(1000);
        choice();
        sword1();
        slv = 1;
        gamest();
    }
}

void enforce_2()
{
    int random[101];

    int i = 1;

    srand((unsigned int)time(NULL));

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 81)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                        ");
        Sleep(1000);
        choice();
        sword1();
        slv = 1;
        gamest();
    }
}

void enforce_3()
{
    int random[101];
    
    int i = 1;

    srand((unsigned int)time(NULL));

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 71)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                        ");
        Sleep(1000);
        choice();
        sword1();
        slv = 1;
        gamest();
    }
}

void enforce_4()
{
    int random[101];

    int i = 1;

    srand((unsigned int)time(NULL));

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 61)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                        ");
        Sleep(1000);
        choice();
        sword1();
        slv = 1;
        gamest();
    }
}

void enforce_5()
{
    int random[101];
    
    int i = 1;

    srand((unsigned int)time(NULL));

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 51)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                         ");
        Sleep(1000);
        sword1();
        slv = 1;
        gamest();
    }
}

void enforce_6()
{
    int random[101];

    int i = 1;

    srand((unsigned int)time(NULL));

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 41)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                         ");
        Sleep(1000);
        choice();
        sword1();
        slv = 1;
        gamest();
    }
}

void enforce_7()
{
    int random[101];



    int i = 1;

    srand((unsigned int)time(NULL));

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 31)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                         ");
        Sleep(1000);
        choice();
        sword1();
        slv = 1;
        gamest();
    }
}

void enforce_8()
{
    int random[101];

    int i = 1;

    srand((unsigned int)time(NULL));

    for (i; i < 5; i++) // 4번 돌아가고 나온 값을 i에 저장
    {
        random[i] = rand() % 100 + 1;
    }
    
    if (random[i-1] > 0 && random[i-1] < 21)
    {
        Setpos(0,30);
        printf("강화 성공!!                        ");
        Sleep(1000);
        choice();
        sword2();
        slv++;
        gamest();
    }
    else
    {
        Setpos(0,30);
        printf("강화 실패...                        ");
        Sleep(1000);
        choice();
        sword1();
        slv = 1;
        gamest();
    }
}

void sword1() // 검 모양 출력
{
    sell_m = 1000;
    Setpos(2,7);
    printf("판매금액 : %d원",sell_m);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
}

void sword2()
{
    sell_m = 10000;
    Setpos(2,7);
    printf("판매금액 : %d원",sell_m);
    textcolor(4);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
    textcolor(15);
}

void sword3()
{
    sell_m = 50000;
    Setpos(2,7);
    printf("판매금액 : %d원", sell_m);
    textcolor(12);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
    textcolor(15);
}

void sword4()
{
    sell_m = 100000;
    Setpos(2,7);
    printf("판매금액 : %d원",sell_m);
    textcolor(14);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
    textcolor(15);
}

void sword5()
{
    sell_m = 500000;
    Setpos(2,7);
    printf("판매금액 : %d원", sell_m);
    textcolor(10);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
    textcolor(15);
}

void sword6()
{
    sell_m = 1000000;
    Setpos(2,7);
    printf("판매금액 : %d원", sell_m);
    textcolor(9);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
    textcolor(15);
}

void sword7()
{
    sell_m = 2000000;
    Setpos(2,7);
    printf("판매금액 : %d원", sell_m);
    textcolor(1);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
    textcolor(15);
}

void sword8()
{
    sell_m = 5000000;
    Setpos(2,7);
    printf("판매금액 : %d원",sell_m);
    textcolor(13);
    Setpos(35,2);
    printf("@$");
    Setpos(34,3);
    printf("@,@");
    Setpos(33,4);
    printf("@;#,");
    Setpos(32,5);
    printf("@=@-$");
    Setpos(31,6);
    printf("@=#~@#");
    Setpos(30,7);
    printf("@$@ -=*");
    Setpos(28,8);
    printf("@@@@$@#");
    Setpos(28,9);
    printf("@#@@ #@");
    Setpos(25,10);
    printf("#=@#@@;#@");
    Setpos(25,11);
    printf("#$~@@##@=#");
    Setpos(25,12);
    printf(",#@-@!#@#");
    Setpos(25,13);
    printf("$@@#-#");
    Setpos(25,14);
    printf("@**@$");
    Setpos(25,15);
    printf("#$$!");
    textcolor(15);
}

void end_screen() // 엔딩 무지개검 3번 깜빡인 후 게임 종료
{
    for(int i = 0; i < 3; i++)
    {
        system("cls");
        border();   
        textcolor(4);
        Setpos(35,4);
        delay("@$");
        Setpos(34,5);
        delay("@,@");
        textcolor(12);
        Setpos(33,6);
        delay("@;#,");
        Setpos(32,7);
        delay("@=@-$");
        textcolor(14);
        Setpos(31,8);
        delay("@=#~@#");
        Setpos(30,9);
        delay("@$@ -=*");
        textcolor(10);
        Setpos(28,10);
        delay("@@@@$@#");
        Setpos(28,11);
        delay("@#@@ #@");
        textcolor(9);
        Setpos(25,12);
        delay("#=@#@@;#@");
        Setpos(25,13);
        delay("#$~@@##@=#");
        textcolor(1);
        Setpos(25,14);
        delay(",#@-@!#@#");
        Setpos(25,15);
        delay("$@@#-#");
        textcolor(13);
        Setpos(25,16);
        delay("@**@$");
        Setpos(25,17);
        delay("#$$!");
        textcolor(15);
    }
    
    
    
}
