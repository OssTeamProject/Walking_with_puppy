#include <stdio.h>
#include <string.h>
#include "walk.h"

int main(void){
    Walk list[100];
    int index = 0;
    int count = 0, menu;

    count = loadData(list);
    index = count;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0) {
                listWalk(list, index);
            }
        }
        else if (menu == 2){
            count += createWalk(&list[index++]);
            
        }
        else if (menu == 3){
            int no = selectDataNo(list, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateWalk(&list[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(list, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 : 1)");
            scanf("%d", &deleteok);
            if(deleteok == 1) {
                if(deleteWalk(&list[no-1])) {
                    count--;
                    printf("=> 삭제됨!\n");
                }
            }
        }
        
    }
    printf("종료됨!\n");
    return 0;
}