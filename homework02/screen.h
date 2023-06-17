#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

void textcolor(int color);
void clear(char* screen, int width, int height);
void border();
void Setpos(int x, int y);
void delay(char* string);
void RemoveCursor();
void choice();
void title();
void rule();
void enterk();
void gamest();
void item();
void sword_lv();
void sword1();
void sword2();
void sword3();
void sword4();
void sword5();
void sword6();
void sword7();
void sword8();
void enforce_1();
void enforce_2();
void enforce_3();
void enforce_4();
void enforce_5();
void enforce_6();
void enforce_7();
void enforce_8();
void end_screen();

#endif