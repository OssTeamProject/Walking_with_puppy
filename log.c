#include <stdio.h>
#include <string.h>
#include "walk.h"
#include "log.h"



int loadData(Walk *w) {
    int count = 0, i = 0;
    FILE *fp;
    char line[100];
    if((fp = fopen("walk.txt", "rt")) == NULL) {
        printf("\n=> 파일 없음\n");
        return 0;
    };
    for(i=0 ; i<100 ; i++){
        if(feof(fp)) break;
        fscanf(fp, "%s %d %d %[^\n]s", w[i].day, &w[i].time, &w[i].weather, w[i].place);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}

void saveData(Walk *w, int count) {
    FILE *fp;
    fp = fopen("walk.txt", "wt");
    for(int i=0 ; i<count-1 ; i++) {
        if(w[i].time == -1) continue;
        fprintf(fp, "%s %d %d %s\n", w[i].day, w[i].time, w[i].weather, w[i].place);
    }
    fprintf(fp, "%s %d %d %s", w[count-1].day, w[count-1].time, w[count-1].weather, w[count-1].place);
    fclose(fp);
    printf("=> 저장됨!\n");
}

void searchPlace(Walk *w, int count) {
    int scnt = 0;
    char search[20];

    printf("검색할 장소? \n");
    getchar();
    scanf("%[^\n]s", search);

    printf("\n================================\n");
    for(int i=0 ; i<count ; i++) {
        if(w[i].time == -1) continue;
        if(strstr(w[i].place, search)) {
            printf("(%d)", i+1);
            readWalk(w[i]);
            scnt++;
            printf("================================\n");
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchWeather(Walk *w, int count) {
    int scnt = 0;
    int type;
    
    printf("검색할 날씨? (1:맑음 2:흐림 3:비 4:눈)\n");
    scanf("%d", &type);

    printf("\n================================\n");
    for(int i=0 ; i<count ; i++) {
        if(w[i].time == -1) continue;
        if(type == w[i].weather) {
            printf("(%d)", i+1);
            readWalk(w[i]);
            scnt++;
            printf("================================\n");
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
