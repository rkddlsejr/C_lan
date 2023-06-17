#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

void textcolor(int color); // 글씨 색 조절 
void clear(char* screen, int width, int height); // 테두리 안쪽 비워주는 버퍼
void border(); // 테두리 크기조절과 출력
void Setpos(int x, int y); // 글씨 출력 좌표 설정
void delay(char* string); // 출력 딜레이 이용해서 애니메이션 효과
void RemoveCursor(); // 애니메이션 출력 때 커서 깜빡임 없애기
void choice(); // 선택 문장 출력
void title(); // 타이틀 출력
void rule(); // 게임 규칙 출력
void enterk();
void gamest(); // 게임 상황 함수
void item(); // 아이템 목록 출력
void sword_lv(); // 검 강화 레벨에 따른 출력들
void sword1(); // 검 모양 출력
void sword2();
void sword3();
void sword4();
void sword5();
void sword6();
void sword7();
void sword8();
void enforce_1(); // 검 강화 함수
void enforce_2();
void enforce_3();
void enforce_4();
void enforce_5();
void enforce_6();
void enforce_7();
void enforce_8();
void end_screen(); // 엔딩 무지개검 3번 깜빡인 후 게임 종료

#endif