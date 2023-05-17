#include <stdio.h>
#include "screen.h"

int title()
{  
    char map[1800];
    char name[9] = "Elman War";
    char st[13] = "1. Game Start";
    char r[13] = "2. Game Story";
    char e[7] = "3. Exit";

    for(int h = 0; h<30; h++)
    {
        for (int w = 0; w<60; w++)
        {
            if(h==0||h==29)
            {map[w] = '=';}
            else if(w==0||w==57 || h<18 && h>7 && w==52)
            {map[w] = '|';}
            else if(h == 11&&w >= 24 && w < 33)
            {map[w] = name[w - 24];}
            else if(h == 22 && w>=20 && w<33)
            {map[w] = st[w-20];}
            else if(h == 24 && w>=20 && w<33)
            {map[w] = r[w-20];}
            else if(h == 26 && w>=20 && w<27)
            {map[w] = e[w-20];}
            else if(h==5 && w==25 || h==5 && w==23 || h==5 && w==27 || h==6 && w==27 || h==6 && w==21
                    || h==7 && w==27 || h==8 && w==25 || h==7 && w==19 || h==9 && w==23 || h==8 && w==17 || h==10 && w==21
                    || h==9 && w==15 || h==11 && w==19 || h==10 && w==13 || h==12 && w==17 || h==11 && w==15 || h==10 && w==17
                    || h==9 && w==19 || h==8 && w==21 || h==7 && w==23 || h==6 && w==25)
            {map[w]='/';}
            else if(h==11 && w==11 || h==13 && w==15 || h==12 && w==13 || h==12 && w==9 
                    || h==14 && w==13 || h==13 && w==11 || h==14 && w==9 || h==15 && w==7
                    || h==16 && w==5 || h==7 && w==52 || h==6 && w==50 || h==6 && w==48 || h==6 && w==46 || h==7 && w==44 
                    || h==8 && w==42 || h==9 && w==40 || h==10 && w==38 || h==11 && w==36 || h==12 && w==34 || h==13 && w==32
                    || h==14 && w==30 || h==15 && w==28 || h==16 && w==28 || h==17 && w==30 || h==18 && w==32)
            {map[w]='W';}
            else if(h==18 && w>32 && w<=52)
            {map[w]='-';}
            else if(h==17 && w==51 || h==16 && w==49 || h==15 && w==47 || h==14 && w==45 || h==13 && w==43
                    || h==12 && w==41 || h==11 && w==39 || h==10 && w==37 || h==9 && w==35 || h==8 && w==33)
            {map[w]='\\';}
            else if(h==7&&w==32)
            {map[w]='A';}
            else
            {map[w]=' ';}
        }
        map[58] = '\n';
        map[59] = '\0';
        printf("%s", map);
    }

    return 0;
}

int enterk()
{
    char ch = ' ';
    getchar();
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

    printf("\n\n게임을 시작하시겠습니까?\n");
    printf("1. 예            2. 메인메뉴");
    
    return 0;
}

int start()
{
    char map[1800];

    for(int h = 0; h<30; h++)
    {
        for (int w = 0; w<60; w++)
        {
            if(h==0||h==29)
            {map[w] = '=';}
            else if(w==0||w==57)
            {map[w] = '|';}
            else
            {map[w]=' ';}
        }
        map[58] = '\n';
        map[59] = '\0';
        printf("%s", map);
    }
}