#include <stdio.h>
#include <string.h>
#include "walk.h"

void listWalk(Walk *w, int count) {
    printf("\n================================\n");
    for(int i=0 ; i<count ; i++) {
        if(w[i].time == -1) continue;
        printf("(%d)\n", i+1);
        readWalk(w[i]);
        printf("================================\n");
    }
}

int selectDataNo(Walk *w, int count) {
    int no;
    listWalk(w, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

int createWalk(Walk *w) {
    printf("산책한 날짜는? (월/일)\n");
    getchar();
    scanf("%[^\n]s", w->day);
    printf("산책한 장소는?\n");
    getchar();
    scanf("%[^\n]s", w->place);
    printf("산책한 시간은? (분)\n");
    scanf("%d", &w->time);
    printf("날씨는? (1:맑음 2:흐림 3:비 4:눈)\n");
    scanf("%d", &w->weather);
    
    return 1;
}

void readWalk(Walk w) {
    printf("\n날짜 - %s\n장소 - %s\n산책시간 - %d분\n날씨 - ", w.day, w.place, w.time);
    if(w.weather == 1) printf("맑음");
    else if(w.weather == 2) printf("흐림");
    else if(w.weather == 3) printf("비");
    else if(w.weather == 4) printf("눈");
    printf("\n");
}

int updateWalk(Walk *w) {
    printf("새 산책한 날짜는? (월/일)\n");
    getchar();
    scanf("%[^\n]s", w->day);
    printf("새 산책한 장소는?\n");
    getchar();
    scanf("%[^\n]s", w->place);
    printf("새 산책한 시간은? (분)\n");
    scanf("%d", &w->time);
    printf("새 날씨는? (1:맑음 2:흐림 3:비 4:눈)\n");
    scanf("%d", &w->weather);
    
    return 1;
}

int deleteWalk(Walk *w) {
    w->time = -1;
    return 1;
}
