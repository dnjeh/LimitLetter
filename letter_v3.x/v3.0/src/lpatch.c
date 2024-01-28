#include "../lletterc.h"

int lpatch() {
    int bre=0, scroll=0, now=0;
    draw_oletter();
    draw_lletter();
    while(!bre) {
        switch(getch()) {
        case ' ':
            bre=1;
            break;
        default:
            printf("\a");
            break;
        }
    }
    return 0;
}