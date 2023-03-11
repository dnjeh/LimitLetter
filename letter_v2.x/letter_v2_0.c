#include "lletterb.h" //177 50 //94 ** //64 20 //⚙️

int con=0, l_mc;
int i, j, k, lselect=2, cnt=0;  //1일 시 읽기(디코딩)
char  *command;
FILE *fp, *fp2; intptr_t hFile; struct _finddatai64_t c_file;
char l_tri[3][101], l_tit[101]; //처음, 마지막, 여담(추신)
char l_ind[100][40]={'\0',}, path[8] = "*.let";
int home(); int lsearch(int _f); int lread(int _f); int lwrite();

int main(){
    system("mode con cols=177 lines=50");        //사전 설정 문단
    system("chcp 65001");
    system("cls");
    t=time(NULL);
    timeland(0);
    while(1) {
        switch(home()) {
        case 2:
            lread(0);
            break;
        case 3:
            lwrite();
            break;
        default:
            break;
        }
    }
}   
/*********************************************************************************************************************************/
int home() {
    int l_goto[5][2]={{59, 32}, {62, 32}, {71, 32}, {92, 32}, {111, 33}};
    CursorView(0);  
    timeland(0);       
    drawbody();
    drawletter();
    int bre=1;
    while(bre){
        gotoxy(56, 32);
        printf("|                 편지 열기            편지 작성               |");
        gotoxy(56, 33);
        printf("|  ⚙[?]                                                  v2.0 |");
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
/*********************************************************************************************************************************/
int lsearch(int _f) {
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
            SSleep(3);
            return 0;
        }
    else {
        cnt=0;
        strcpy(l_ind[cnt], c_file.name);
        for(cnt=1;_findnexti64(hFile, &c_file)==0;cnt++){
            strcpy(l_ind[cnt], c_file.name);
        } 
        _findclose(hFile); // _findfirsti64(), _findnexti64()에 사용된 메모리를 반환
    }
    //---------------------------------------------------------------------------------------------------
    drawoletter();
    i=0;
    while(1) {
        con=0;
        drawnletter();
        drawlletter();
        for(j=(i/18)*18;j<(((i/18)+1)*18)&&j<cnt;j++) {
            if(i==cnt/18*18&&i&&i==j) {
                drawoletter();
                drawnletter();
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
                RemoveEnter(l_tri[j], sizeof(l_tri[j]));
            }
            beforerand(1);
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
            RemoveEnter(l_tri[0], sizeof(l_tri[0]));
        }
        timeland(0);
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
            printf("               [유효기간 내 의 편지가 아닙니다]               ");
            fclose(fp);
            SSleep(3);
            return 0;
        }
        switch(getch()) {
                case ' ':
                    CursorView(0);
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
/*********************************************************************************************************************************/
int lread(int _f) {
    if(!lsearch(_f)) return 0;
    char _t;
    fscanf(fp, "%d%c", &l_mc, &_t); //작업 전 문단 수 읽기, 그에 따른 문단 배열 생성&초기화
    char l_m[l_mc][540];
    for(i=0;i<l_mc;i++) {
        strcpy(l_m[i] , "");
    }                          
    drawbody();
    drawmain(l_mc<=40?11:10);
    beforerand(0);
    for(i=0;i<l_mc;i++) {
        fgets(l_m[i], sizeof(l_m[i]), fp); //사전 읽고 디코딩 작업
        if(!_f) eCoding(0, l_m[i], sizeof(l_m[i]), '\n');
    }
    fclose(fp);                                                     //파일 읽기 종료
    gotoxy(44, 3);
    printf(" %s 에게                                            ", l_tri[0]);
    for(k=0;k<l_mc/40+(l_mc%40?1:0);k++) { 
        CursorView(0);
        if(k) drawmain(k+1==(l_mc/40+(l_mc%40?1:0))?1:0);
        gotoxy(44+1+1, 46);
        printf("|%02d / %02d|", k+1, l_mc/40+(l_mc%40?1:0));
        for(i=0;i<40&&((k*40+i)<l_mc);i++) {                              //페이지, 문단별 출력
            gotoxy(44, 5+i);
            if(l_m[i][0]=='\n'&&!l_m[i][1]) {
                gotoxy(44, 5+i);
                CursorView(1);
                getch();
                CursorView(0);
            }
            else {
                printf("%s", l_m[k*40+i]);
                SSleep(1);
            }
        }
        gotoxy(44, 5+i);
        CursorView(1);
        getch();
    }
    gotoxy(54, 45);
    printf("                                               %d.%02d.%02d, %s 가     ", l_lim[2][0], l_lim[2][1], l_lim[2][2], l_tri[1]);
    CursorView(0);
    SSleep(3);
    return 0;
}
/*********************************************************************************************************************************/
int lwrite() {
    char _t[5], lw_tt;
    if(!lsearch(0)) return 0;
    fclose(fp);
    fp=fopen(l_tit, "r");
    for(l_mc=0;fgets(_t, sizeof(_t), fp)!=NULL;l_mc++);
    char l_m[--l_mc][540];
    fclose(fp);
    fp=fopen(l_tit, "r");
    for(i=0;i<l_mc;i++) {
        fgets(l_m[i], sizeof(l_m[i]), fp); 
    }
    fclose(fp);                                 //일단 다 읽어놓고 닫기
    int l_goto[5][2] = {{62, 14}, {62, 16}, {62, 18}, {62, 20}, {70, 22}};
    char *l_stit[5]={"편지의 이름", "편지의 길이", "유효 시각", "보내는 이", "받는 이"};
    char *l_sexp[5]={"파일의 이름으로서 보여지는 편지의 이름입니다.", 
                     "본문의 길이입니다.", 
                     "편지를 열람 가능한 기간을 결정하는 시각 입니다.",  
                     "보내는 이, 당신을 가르키는 문자열입니다.", 
                     "받는 이를 가르키는 문자열입니다."};
    int bre=1, wl_sel=0, wl_act=0, bre2=0;   
    drawoletter();
    timeland(1);
    while(bre) {
        bre2=1;
        for(i=0;i<5;i++) {
            gotoxy(l_goto[i][0]-2, l_goto[i][1]);
            printf("%c %s %c", wl_sel==i?(wl_sel==1?'X':wl_act?'<':'>'):' ', l_stit[i], ':');
            switch(i) { 
                case 0: printf(" %s", l_tit); break;
                case 1: printf(" %d line%c", l_mc, l_mc==1?'\0':'s'); break;
                case 2: printf(" %4d.%02d.%02d/%02d - %4d.%02d.%02d/%02d", l_lim[0][0], l_lim[0][1], l_lim[0][2], l_lim[0][3], l_lim[1][0], l_lim[1][1], l_lim[1][2], l_lim[1][3]); break;
                case 3: printf(" %s", l_tri[0]);  break;
                case 4: printf(" %s", l_tri[1]);  break;
            }
        }
        gotoxy(57, 33); printf(" /> %-65s",l_sexp[wl_sel]);
        gotoxy(64, 22); printf("-✉-");
        if(wl_act) {
            CursorView(1);
            if(wl_sel==2) {
                switch(wl_act) {
                    case 1: gotoxy(62+12, 18); break;
                    case 2: gotoxy(62+12+5, 18); break;
                    case 3: gotoxy(62+12+8, 18); break;
                    case 4: gotoxy(62+12+11, 18); break;
                    case 5: gotoxy(62+12+16, 18); break;
                    case 6: gotoxy(62+12+16+5, 18); break;
                    case 7: gotoxy(62+12+16+8, 18); break;
                    case 8: gotoxy(62+12+16+11, 18); break;
                }
            }
        }
        if((!wl_sel||wl_sel==3||wl_sel==4)&&wl_act) {
            i=0;
            gotoxy(l_goto[wl_sel][0]+(!wl_sel?14:wl_sel==3?12:10), l_goto[wl_sel][1]);
            while(bre2&&i<=100) {
                switch(lw_tt=_getch()) {
                case '<':
                    bre2=0;
                    wl_act=0;
                    continue;
                    break;
                default:
                    if(!wl_sel) {
                        l_tit[i++]=lw_tt;
                    }
                    else {
                        l_tri[wl_sel-3][i++]=lw_tt;
                    }
                    printf("%c", lw_tt);
                    break;
                }
            }
            if(!wl_sel) {
                l_tit[i]='\0';
            }
            else {
                l_tri[wl_sel-3][i]='\0';
            }
        }
        if(bre2)
        switch(getch()) {
            case 'e': 
                if(wl_sel!=1) wl_act++;
                if(wl_sel==2&&wl_act>8) wl_act=0;
                if(wl_sel!=2&&wl_act>1) wl_act=0; 
                break;
            case 'q':
                if(wl_sel!=1) wl_act--;
                if(wl_sel==2&&wl_act<0) wl_act=8;
                if(wl_sel!=2&&wl_act<0) wl_act=1;
                break;
            case 'd': 
                wl_sel++;
                if(wl_sel>4) wl_sel=0;
                wl_act=0;
                break;
            case 'a':
                wl_sel--;
                if(wl_sel<0) wl_sel=4;
                wl_act=0;
                break;
            case 'w': 
                if(wl_sel==2&&wl_act) l_lim[(wl_act-1)/4][(wl_act-1)%4]++;
                break;
            case 's':
                if(wl_sel==2&&wl_act) l_lim[(wl_act-1)/4][(wl_act-1)%4]--;
                break;
            case ' ':
                bre=0;
                break;
            default:
                break;
        }
        if(wl_act&&!wl_sel) {
            strcpy(l_tit, "");
        }
        else if(wl_act&&wl_sel==3) {
            strcpy(l_tri[0], "");
        }
        else if(wl_act&&wl_sel==4) {
            strcpy(l_tri[1], "");
        }
        CursorView(0);
    }
    beforerand(1);
    for(i=0;i<3;i++) eCoding(1, l_tri[i], sizeof(l_tri[i]), '\0');                     //문단 인코딩 작업
    beforerand(0);
    for(i=0;i<l_mc;i++) {                //본문 인코딩 작업
        eCoding(1, l_m[i], sizeof(l_m[i])-1, '\n');
    }
    for(i=0;l_tit[i]!='\0';i++); //글자수 세기
    if(i<=59) {
        l_tit[i]='_';
        l_tit[i+1]='\0';
    }
    fp2=fopen(l_tit, "w");                       //변환된 편지이름으로 출력
    for(i=0;i<2;i++) fprintf(fp2, "%s\n", l_tri[i]);
    for(i=0;i<8;i++) fprintf(fp2, !i%4?"%04d":"%02d", l_lim[i/4][i%4]); 
    fprintf(fp2, "\n%d\n", l_mc);
    for(i=0;i<l_mc;i++) {  //변환된 본문 출력
        fprintf(fp, "%s", l_m[i]);
    }
    drawnletter();
    gotoxy(57, 35);
    printf("                 편지로 변환이 완료되었습니다!             ");
    fclose(fp2);
    SSleep(3);
    return 0;
}
/*********************************************************************************************************************************/