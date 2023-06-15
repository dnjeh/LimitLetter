#include "lletterc.h" //177 50 //94 ** //64 20 //⚙️

int main(){
    int i, j, k;
    system("mode con cols=177 lines=50");        //사전 설정 문단
    system("chcp 65001");
    system("cls");
    t=time(NULL);
    time_land(0);
    if(access("tutoend!",0)==-1) {
        ltuto();
        FILE* fp=fopen("tutoend!", "w");
        fprintf(fp, "Hello, limitletter!");
        fclose(fp);
    }
    while(1) {
        switch(home()) {
        case 1:
            ltuto();
            break;
        case 2:
            lread(0);
            break;
        case 3:
            lwrite();
            break;
        default:
            printf("\a");
            break;
        }
    }
}   
/*********************************************************************************************************************************/
int home() {
    int l_goto[5][2]={{59, 32}, {62, 32}, {71, 32}, {92, 32}, {109, 33}};
    cursorView(0);  
    time_land(0);       
    draw_body();
    draw_letter();
    int bre=1;
    while(bre){
        gotoxy(56, 32);
        printf("|                 편지 열기            편지 작성               |");
        gotoxy(56, 33);
        printf("|  ⚙[?]                                                v3.0p1 |");
        gotoxy(l_goto[lselect][0], l_goto[lselect][1]);
        printf(lselect<2?"v":"√");
        switch(getch()) {
            case 'd': 
                lselect++;
                if(lselect>4) lselect=0;
                break;
            case 'a':
                lselect--;
                if(lselect<0) lselect=4;
                break;
            case ' ':
                bre=0;
                break;
            default:
                break;
        }
    }                     
    return lselect;
}
