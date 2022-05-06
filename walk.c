#include <stdio.h>
#include <string.h>
#include "walk.h"

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
