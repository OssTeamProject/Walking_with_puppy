#include <stdio.h>
#include "walk.h"


int loadData(Walk *w); // 저장된 산책일지 리스트 불러오기
void saveData(Walk *w, int count); // 산책일지 리스트 저장
void searchPlace(Walk *w, int count); // 산책장소 검색
void searchTime(Walk *w, int count); // 산책한 시간 검색
void searchWeather(Walk *w, int count); // 날씨 검색
