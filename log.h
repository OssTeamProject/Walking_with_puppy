#include <stdio.h>
#include "walk.h"


int loadData(Walk *w); // ����� ��å���� ����Ʈ �ҷ�����
void saveData(Walk *w, int count); // ��å���� ����Ʈ ����
void searchPlace(Walk *w, int count); // ��å��� �˻�
void searchTime(Walk *w, int count); // ��å�� �ð� �˻�
void searchWeather(Walk *w, int count); // ���� �˻�