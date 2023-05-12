#include <stdio.h>
#include "screen.h"

int title()
{
    char screen[1000];

    int h = 0;
    
    while (h<20)
    {
        int w = 0;
        while (w<40)
        {
            if(h==0||h==19)
            {screen[w]='-';}
            else if(w==0||w==37)
            {screen[w]='|';}
            else if(h==5&&w==8)
            {screen[w]='S';}
            else if(h==5&&w==9)
            {screen[w]='t';}
            else if(h==5&&w==10)
            {screen[w]='e';}
            else if(h==5&&w==11)
            {screen[w]='e';}
            else if(h==5&&w==12)
            {screen[w]='l';}
            else if(h==5&&w==13)
            {screen[w]='i';}
            else if(h==5&&w==14)
            {screen[w]='n';}
            else if(h==5&&w==15)
            {screen[w]='g';}
            else if(h==5&&w==18)
            {screen[w]='P';}
            else if(h==5&&w==19)
            {screen[w]='r';}
            else if(h==5&&w==20)
            {screen[w]='o';}
            else if(h==5&&w==21)
            {screen[w]='f';}
            else if(h==5&&w==22)
            {screen[w]='e';}
            else if(h==5&&w==23)
            {screen[w]='s';}
            else if(h==5&&w==24)
            {screen[w]='s';}
            else if(h==5&&w==25)
            {screen[w]='o';}
            else if(h==5&&w==26)
            {screen[w]='r';}
            else if(h==5&&w==27)
            {screen[w]='s';}
            else if(h==5&&w==28)
            {screen[w]='\'';}
            else if(h==5&&w==29)
            {screen[w]='s';}
            else if(h==6&&w==15)
            {screen[w]='W';}
            else if(h==6&&w==16)
            {screen[w]='a';}
            else if(h==6&&w==17)
            {screen[w]='l';}
            else if(h==6&&w==18)
            {screen[w]='l';}
            else if(h==6&&w==19)
            {screen[w]='e';}
            else if(h==6&&w==20)
            {screen[w]='t';}
            else if(h==12&&w==5)
            {screen[w]='1';}
            else if(h==12&&w==6)
            {screen[w]='.';}
            else if(h==12&&w==9)
            {screen[w]='G';}
            else if(h==12&&w==10)
            {screen[w]='a';}
            else if(h==12&&w==11)
            {screen[w]='m';}
            else if(h==12&&w==12)
            {screen[w]='e';}
            else if(h==12&&w==14)
            {screen[w]='S';}
            else if(h==12&&w==15)
            {screen[w]='t';}
            else if(h==12&&w==16)
            {screen[w]='a';}
            else if(h==12&&w==17)
            {screen[w]='r';}
            else if(h==12&&w==18)
            {screen[w]='t';}
            else if(h==14&&w==5)
            {screen[w]='2';}
            else if(h==14&&w==6)
            {screen[w]='.';}
            else if(h==14&&w==9)
            {screen[w]='G';}
            else if(h==14&&w==10)
            {screen[w]='u';}
            else if(h==14&&w==11)
            {screen[w]='i';}
            else if(h==14&&w==12)
            {screen[w]='d';}
            else if(h==14&&w==13)
            {screen[w]='e';}
            else if(h==16&&w==5)
            {screen[w]='3';}
            else if(h==16&&w==6)
            {screen[w]='.';}
            else if(h==16&&w==9)
            {screen[w]='E';}
            else if(h==16&&w==10)
            {screen[w]='x';}
            else if(h==16&&w==11)
            {screen[w]='i';}
            else if(h==16&&w==12)
            {screen[w]='t';}
            else
            {screen[w]=' ';}
            w+=1;
        }
        screen[38]='\n';
        screen[39]='\0';
        printf("%s",screen);
        h+=1;
    }

    return 0;
}

int Start()
{
    char screen[1000];

    int h = 0;
    
    while (h<20)
    {
        int w = 0;
        while (w<40)
        {
            if(h==0||h==19)
            {screen[w]='-';}
            else if(w==0||w==37)
            {screen[w]='|';}
            else
            {screen[w]=' ';}
            w+=1;
        }
        screen[38]='\n';
        screen[39]='\0';
        printf("%s",screen);
        h+=1;
    }

    return 0;
}

int Guide()
{
    char screen[1000];

    int h = 0;
    
    while (h<20)
    {
        int w = 0;
        while (w<40)
        {
            if(h==0||h==19)
            {screen[w]='-';}
            else if(w==0||w==37)
            {screen[w]='|';}
            else if(h==5&&w==5)
            {screen[w]='I';}
            else if(h==5&&w==7)
            {screen[w]='w';}
            else if(h==5&&w==8)
            {screen[w]='i';}
            else if(h==5&&w==9)
            {screen[w]='l';}
            else if(h==5&&w==10)
            {screen[w]='l';}
            else if(h==5&&w==12)
            {screen[w]='s';}
            else if(h==5&&w==13)
            {screen[w]='t';}
            else if(h==5&&w==14)
            {screen[w]='e';}
            else if(h==5&&w==15)
            {screen[w]='a';}
            else if(h==5&&w==16)
            {screen[w]='l';}
            else if(h==5&&w==17)
            {screen[w]='m';}
            else if(h==5&&w==18)
            {screen[w]='y';}
            else if(h==5&&w==20)
            {screen[w]='p';}
            else if(h==5&&w==21)
            {screen[w]='r';}
            else if(h==5&&w==22)
            {screen[w]='o';}
            else if(h==5&&w==23)
            {screen[w]='f';}
            else if(h==5&&w==24)
            {screen[w]='e';}
            else if(h==5&&w==25)
            {screen[w]='s';}
            else if(h==5&&w==26)
            {screen[w]='s';}
            else if(h==5&&w==27)
            {screen[w]='o';}
            else if(h==5&&w==28)
            {screen[w]='r';}
            else if(h==5&&w==29)
            {screen[w]='s';}
            else if(h==5&&w==30)
            {screen[w]='\'';}
            else if(h==5&&w==31)
            {screen[w]='s';}
            else if(h==6&&w==6)
            {screen[w]='w';}
            else if(h==6&&w==7)
            {screen[w]='a';}
            else if(h==6&&w==8)
            {screen[w]='l';}
            else if(h==6&&w==9)
            {screen[w]='l';}
            else if(h==6&&w==10)
            {screen[w]='e';}
            else if(h==6&&w==11)
            {screen[w]='t';}
            else if(h==6&&w==13)
            {screen[w]='a';}
            else if(h==6&&w==14)
            {screen[w]='n';}
            else if(h==6&&w==15)
            {screen[w]='d';}
            else if(h==6&&w==17)
            {screen[w]='b';}
            else if(h==6&&w==18)
            {screen[w]='u';}
            else if(h==6&&w==19)
            {screen[w]='y';}
            else if(h==6&&w==21)
            {screen[w]='a';}
            else if(h==6&&w==23)
            {screen[w]='c';}
            else if(h==6&&w==24)
            {screen[w]='o';}
            else if(h==6&&w==25)
            {screen[w]='m';}
            else if(h==6&&w==26)
            {screen[w]='p';}
            else if(h==6&&w==27)
            {screen[w]='u';}
            else if(h==6&&w==28)
            {screen[w]='t';}
            else if(h==6&&w==29)
            {screen[w]='e';}
            else if(h==6&&w==30)
            {screen[w]='r';}
            else if(h==6&&w==31)
            {screen[w]='.';}
            else if(h==7&&w==11)
            {screen[w]='S';}
            else if(h==7&&w==12)
            {screen[w]='t';}
            else if(h==7&&w==13)
            {screen[w]='e';}
            else if(h==7&&w==14)
            {screen[w]='a';}
            else if(h==7&&w==15)
            {screen[w]='l';}
            else if(h==7&&w==17)
            {screen[w]='t';}
            else if(h==7&&w==18)
            {screen[w]='h';}
            else if(h==7&&w==19)
            {screen[w]='e';}
            else if(h==7&&w==21)
            {screen[w]='m';}
            else if(h==7&&w==22)
            {screen[w]='o';}
            else if(h==7&&w==23)
            {screen[w]='n';}
            else if(h==7&&w==24)
            {screen[w]='e';}
            else if(h==7&&w==25)
            {screen[w]='y';}
            else if(h==8&&w==5)
            {screen[w]='w';}
            else if(h==8&&w==6)
            {screen[w]='i';}
            else if(h==8&&w==7)
            {screen[w]='t';}
            else if(h==8&&w==8)
            {screen[w]='h';}
            else if(h==8&&w==9)
            {screen[w]='o';}
            else if(h==8&&w==10)
            {screen[w]='u';}
            else if(h==8&&w==11)
            {screen[w]='t';}
            else if(h==8&&w==13)
            {screen[w]='t';}
            else if(h==8&&w==14)
            {screen[w]='h';}
            else if(h==8&&w==15)
            {screen[w]='e';}
            else if(h==8&&w==17)
            {screen[w]='p';}
            else if(h==8&&w==18)
            {screen[w]='r';}
            else if(h==8&&w==19)
            {screen[w]='o';}
            else if(h==8&&w==20)
            {screen[w]='f';}
            else if(h==8&&w==21)
            {screen[w]='f';}
            else if(h==8&&w==22)
            {screen[w]='o';}
            else if(h==8&&w==23)
            {screen[w]='r';}
            else if(h==8&&w==24)
            {screen[w]='s';}
            else if(h==8&&w==26)
            {screen[w]='k';}
            else if(h==8&&w==27)
            {screen[w]='n';}
            else if(h==8&&w==28)
            {screen[w]='o';}
            else if(h==8&&w==29)
            {screen[w]='w';}
            else if(h==8&&w==30)
            {screen[w]='i';}
            else if(h==8&&w==31)
            {screen[w]='n';}
            else if(h==8&&w==32)
            {screen[w]='g';}
            else if(h==8&&w==33)
            {screen[w]='.';}
            else if(h==12&&w==5)           
            {screen[w]='1';}
            else if(h==12&&w==6)
            {screen[w]='.';}
            else if(h==12&&w==9)
            {screen[w]='B';}
            else if(h==12&&w==10)
            {screen[w]='a';}
            else if(h==12&&w==11)
            {screen[w]='c';}
            else if(h==12&&w==12)
            {screen[w]='k';}
            else if(h==12&&w==14)
            {screen[w]='t';}
            else if(h==12&&w==15)
            {screen[w]='o';}
            else if(h==12&&w==17)
            {screen[w]='t';}
            else if(h==12&&w==18)
            {screen[w]='i';}
            else if(h==12&&w==19)
            {screen[w]='t';}
            else if(h==12&&w==20)
            {screen[w]='l';}
            else if(h==12&&w==21)
            {screen[w]='e';}
            else if(h==14&&w==5)
            {screen[w]='2';}
            else if(h==14&&w==6)
            {screen[w]='.';}
            else if(h==14&&w==9)
            {screen[w]='A';}
            else if(h==14&&w==10)
            {screen[w]='g';}
            else if(h==14&&w==11)
            {screen[w]='a';}
            else if(h==14&&w==12)
            {screen[w]='i';}
            else if(h==14&&w==13)
            {screen[w]='n';}
            else
            {screen[w]=' ';}
            w+=1;
        }
        screen[38]='\n';
        screen[39]='\0';
        printf("%s",screen);
        h+=1;
    }

    return 0;
}