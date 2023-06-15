#include "../lletterc.h"

/*********************************************************************************************************************************/
int lsearch(int _f) {
    intptr_t hFile; struct _finddatai64_t c_file; int cnt=0, con=0, i, j, k;
    //--------------------------------------------탐색문단-----------------------------------------------------                 
    if(lselect==2) strcpy(path, "*_");    //편지 검색&적재
    else if(lselect==3) strcpy(path, "*");
    if((hFile = _findfirsti64(path, &c_file))==-1L) {
        gotoxy(57, 32);
        switch(errno) {
            case ENOENT:
                printf("|      현재 동작에 맞는 파일을 찾을 수 없습니다      |"); _findclose(hFile); break;
            case EINVAL:
                printf("|             잘못된 파일 경로입니다             |"); _findclose(hFile); break;
            case ENOMEM:
                printf("|       메모리가 부족하거나 이름이 너무 깁니다       |"); _findclose(hFile); break;
            default:
                printf("|              알 수 없는 에러입니다              |"); _findclose(hFile); break;
            }
            sSleep(3);
            return 0;
        }
    else {
        strcpy(l_ind[cnt], c_file.name);
        for(cnt=1;_findnexti64(hFile, &c_file)==0;cnt++){
            strcpy(l_ind[cnt], c_file.name);
        } 
        _findclose(hFile); // _findfirsti64(), _findnexti64()에 사용된 메모리를 반환
    }
    //---------------------------------------------------------------------------------------------------
    draw_oletter();
    i=0;
    while(1) {
        con=0;
        draw_nletter();
        draw_lletter();
        for(j=(i/18)*18;j<(((i/18)+1)*18)&&j<cnt;j++) {
            if(i==cnt/18*18&&i&&i==j) {
                draw_oletter();
                draw_nletter();
            }
            if(!((j/9)%2)) {
                gotoxy(63, 14+j%9);
                printf("  %-22s", l_ind[j]);
            }
            else {
                gotoxy(87, 14+j%9);
                if(j%2) printf("| ");
                else printf(" |");
                printf("  %-22s", l_ind[j]);
            }
            if(i==j) {
                if(!((j/9)%2)) gotoxy(63, 14+j%9);
                else gotoxy(89, 14+j%9);
                printf("√");
            }
            gotoxy(85, 29);
            printf("- %02d -", j/18+1);
        }
        gotoxy(57, 34);
        if(lselect==2) printf("        [이 파일이 곧 편지라면 space bar를 눌러주세요]     ");
        else printf("       [이 파일이 곧 본문이라면 space bar를 눌러주세요]    ");
        switch(getch()) {
            case ' ':
                con=1;
                break;
            case 'd':
                if(i+1<cnt) i++;
                break;
            case 'a':
                if(i-1>=0) i--;
                break;
            default:
                break;
        }
        if(!con) continue;
        gotoxy(57, 34);
        printf("                                                          ");
        strcpy(l_tit, l_ind[i]);
        fp=fopen(l_tit, "r");           
        for(k=0;k<8;k++) l_lim[k/4][k%4]=0;   
        if(lselect==2) {                           //읽을 때         
            for(j=0;j<3;j++) {
                fgets(l_tri[j], sizeof(l_tri[j]), fp);
                removeEnter(l_tri[j], sizeof(l_tri[j]));
            }
            beforeRand(1);
            if(!_f) for(j=0;j<3;j++) eCoding(0, l_tri[j], sizeof(l_tri[j]), '\0');
            for(k=0;k<20;k++) {
                switch(k%10) {
                case 0: j=1000; case 1: case 2: case 3:
                    l_lim[k/10][0]+=(l_tri[2][k]-48)*j;
                    j/=10;
                    break;
                case 4: j=10; case 5:
                    l_lim[k/10][1]+=(l_tri[2][k]-48)*j;
                    j/=10;
                    break;
                case 6: j=10; case 7:
                    l_lim[k/10][2]+=(l_tri[2][k]-48)*j;
                    j/=10;
                    break;
                case 8: j=10; case 9:
                    l_lim[k/10][3]+=(l_tri[2][k]-48)*j;
                    j/=10;
                    break;
                default:
                    break;
                }
            }
        }
        else {
            fgets(l_tri[0], sizeof(l_tri[0]), fp);
            removeEnter(l_tri[0], sizeof(l_tri[0]));
        }
        time_land(0);
        if(lselect==2&&time_vaild()) {
            gotoxy(57, 32);                                                //단계 진입 전 안내문구
            printf("     %s에게                  ", l_tri[0]);
            gotoxy(57, 34);
            printf("      %d.%02d.%02d/%02d ~ %d.%02d.%02d/%02d, %s 가", l_lim[1][0], l_lim[1][1], l_lim[1][2], l_lim[1][3], l_lim[0][0], l_lim[0][1], l_lim[0][2], l_lim[0][3], l_tri[1]);
            gotoxy(57, 36);
            printf("         [읽기를 시작하시려면 space bar를 눌러주세요]     ");
        }
        else if(lselect==3) { //단계 진입 전 안내문구
            gotoxy(57, 33);
            printf("  %s(으)로 시작하는 본문", l_tri[0]);
            gotoxy(57, 35);
            printf("         [작성을 시작하시려면 space bar를 눌러주세요]     ");
        } 
        else {
            gotoxy(57, 35);
            printf("               [유효기간  내의 편지가 아닙니다]               ");
            fclose(fp);
            sSleep(3);
            return 0;
        }
        switch(getch()) {
            case ' ':
                cursorView(0);
                return 1;
                break;
            case 'd':
                if(i+1<cnt) i++;
                fclose(fp);
                break;
            case 'a':
                if(i-1>=0) i--;
                fclose(fp);
                break;
            default:
                break;
        }
    }
}