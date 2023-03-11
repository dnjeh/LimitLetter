#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <windows.h>
void gotoxy(int _x,int _y) { //gotoxy함수 
    COORD pos={_x, _y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main() {

int x=0, y=0;
while(1) {
    switch(_getch()) {
        case 'a': x--; break;
        case 'd': x++; break;
        case 's': y++; break;
        case 'w': y--; break;
        case ' ':
            printf("%d/%d", x, y);
            break;
        default: break;
    }
    gotoxy(x, y);
}

}