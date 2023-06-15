#include "../lletterc.h"

/*********************************************************************************************************************************/
int lread(int _f) {
    int i, j, k;
    if(!lsearch(_f)) return 0;
    char _t;
    fscanf(fp, "%d%c", &l_mc, &_t); //작업 전 문단 수 읽기, 그에 따른 문단 배열 생성&초기화
    char l_m[l_mc][540];
    int bre=1;
    for(i=0;i<l_mc;i++) {
        strcpy(l_m[i] , "");
    }                          
    draw_body();
    draw_main(l_mc<=40?11:10);
    beforeRand(0);
    for(i=0;i<l_mc;i++) {
        fgets(l_m[i], sizeof(l_m[i]), fp); //사전 읽고 디코딩 작업
        if(!_f) eCoding(0, l_m[i], sizeof(l_m[i]), '\n');
    }
    fclose(fp);                                                     //파일 읽기 종료
    gotoxy(44, 3);
    int kk=-1;
    printf(" %s 에게                                            ", l_tri[0]);
    for(k=0;k<l_mc/40+(l_mc%40?1:0);k++) { 
        cursorView(0);
        if(k) draw_main(k+1==(l_mc/40+(l_mc%40?1:0))?1:0);
        else if(kk!=-1) draw_main(l_mc<=40?11:10);
        gotoxy(44+1+1, 46);
        printf("%c%02d / %02d%c", !k?'[':'<', k+1, l_mc/40+(l_mc%40?1:0), (k+1==(l_mc/40+(l_mc%40?1:0)))?']':kk>=k?'>':'|');
        for(i=0;i<40&&((k*40+i)<l_mc);i++) {                              //페이지, 문단별 출력
            gotoxy(44, 5+i);
            if(l_m[k*40+i][0]=='\n'&&!l_m[k*40+i][1]&&kk<k) {
                gotoxy(44, 5+i);
                cursorView(1);
                switch(getch()) {
                    case 'd': if(kk>=k) { bre=-1; i=40; } break;
                    case 'a': if(k!=0) { k-=2; bre=-1; i=40; } break;
                    default: break;
                }
                cursorView(0);
            }
            else {
                printf("%s", l_m[k*40+i]);
                if(kk<k) sSleep(1);
            }
        }
        gotoxy(44, 5+i);
        cursorView(1);
        bre++;
        if(kk<k) kk=k;
        gotoxy(44+1+1, 46);
        printf("%c%02d / %02d%c", !k?'[':'<', k+1, l_mc/40+(l_mc%40?1:0), (k+1==(l_mc/40+(l_mc%40?1:0)))?']':kk>=k?'>':'|');
        while(bre) switch(getch()) {
            case 'd': 
                if(kk>=k&&k+1!=l_mc/40+(l_mc%40?1:0)) {
                    bre=0; break;
                }
                else {
                    printf("\a"); break;
                }
            case 'a': if(k!=0) { k-=2; bre=0;} break;
            case ' ': if(k+1==l_mc/40+(l_mc%40?1:0)) {
                bre=0; break;
            }
            else {printf("\a"); break;}
            default: printf("\a"); break;
        }
    }
    gotoxy(54, 45);
    printf("                                               %d.%02d.%02d, %s 가     ", l_lim[2][0], l_lim[2][1], l_lim[2][2], l_tri[1]);
    cursorView(0);
    sSleep(3);
    return 0;
}
