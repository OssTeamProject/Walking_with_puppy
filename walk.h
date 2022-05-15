#ifndef _WALK_H
#define _WALK_H

#include <stdio.h>

typedef struct {
    char day[20]; // 산책한 날짜
    char place[30]; // 산책장소
    int time; // 산책한 시간
    int weather; // 날씨(1:맑음 2:흐림 3:비 4:눈)
}Walk;

int selectMenu(); // 메뉴 선택
int createWalk(Walk *w); // 산책일지 추가
void readWalk(Walk w); // 하나의 일지 출력
int updateWalk(Walk *w); // 산책일지 수정
int deleteWalk(Walk *w); // 산책일지 삭제
void listWalk(Walk *w, int count); // 전체 등록된 산책일지의 리스트 출력
int selectDataNo(Walk *w, int count); //선택된 산책일지의 번호 출력

#endif
