#include "lletterb.h" //177 50 //94 ** //64 20 //⚙️

int con=0, l_mc;
int i, j, k, lselect=2, cnt=0;  //1일 시 읽기(디코딩)
char  *command;
FILE *fp, *fp2; intptr_t hFile; struct _finddatai64_t c_file;
char l_tri[3][102], l_tit[102]; //처음, 마지막, 여담(추신)
char l_ind[101][40]={'\0',}, path[8] = "*.let";
int home(); int lsearch(int _f); int lread(int _f); int lwrite(); int ltuto();

int main(){
    system("mode con cols=177 lines=50");        //사전 설정 문단
    system("chcp 65001");
    system("cls");
    t=time(NULL);
    timeland(0);
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
        printf("|  ⚙[?]                                                  v2.0b|");
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
        if(lselect==2/*&&time_vaild()*/) {
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
    int bre=1;
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
    int kk=-1;
    printf(" %s 에게                                            ", l_tri[0]);
    for(k=0;k<l_mc/40+(l_mc%40?1:0);k++) { 
        CursorView(0);
        if(k) drawmain(k+1==(l_mc/40+(l_mc%40?1:0))?1:0);
        else if(kk!=-1) drawmain(l_mc<=40?11:10);
        gotoxy(44+1+1, 46);
        printf("%c%02d / %02d%c", !k?'[':'<', k+1, l_mc/40+(l_mc%40?1:0), (k+1==(l_mc/40+(l_mc%40?1:0)))?']':kk>=k?'>':'|');
        for(i=0;i<40&&((k*40+i)<l_mc);i++) {                              //페이지, 문단별 출력
            gotoxy(44, 5+i);
            if(l_m[k*40+i][0]=='\n'&&!l_m[k*40+i][1]&&kk<k) {
                gotoxy(44, 5+i);
                CursorView(1);
                switch(getch()) {
                    case 'd': if(kk>=k) { bre=-1; i=40; } break;
                    case 'a': if(k!=0) { k-=2; bre=-1; i=40; } break;
                    default: break;
                }
                CursorView(0);
            }
            else {
                printf("%s", l_m[k*40+i]);
                if(kk<k) SSleep(1);
            }
        }
        gotoxy(44, 5+i);
        CursorView(1);
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
    char *l_sexp[5]={"파일의 이름으로서 보여지는 편지의 이름입니다. (f / <)", 
                     "본문의 길이입니다.", 
                     "편지를 열람 가능한 기간을 결정하는 시각 입니다. (f / w/s)",  
                     "보내는 이, 당신을 가르키는 문자열입니다. (f / <)", 
                     "받는 이를 가르키는 문자열입니다. (f / <)"};
    int bre=1, wl_sel=0, wl_act=0, bre2=0;   
    drawoletter();
    timeland(1);
    while(bre) {
        bre2=1;
        for(i=0;i<5;i++) {
            gotoxy(l_goto[i][0]-2, l_goto[i][1]);
            printf("%c %s %c", wl_sel==i?(wl_sel==1?'X':wl_act?'<':'>'):' ', l_stit[i], ':');
            switch(i) { 
                case 0: printf(" %-40s", l_tit); break;
                case 1: printf(" %d line%c", l_mc, l_mc==1?'\0':'s'); break;
                case 2: printf(" %4d.%02d.%02d/%02d - %4d.%02d.%02d/%02d", l_lim[0][0], l_lim[0][1], l_lim[0][2], l_lim[0][3], l_lim[1][0], l_lim[1][1], l_lim[1][2], l_lim[1][3]); break;
                case 3: printf(" %-40s", l_tri[0]);  break;
                case 4: printf(" %-35s", l_tri[1]);  break;
            }
        }
        gotoxy(57, 32); printf(" -> %-57s","");
        gotoxy(57, 32); printf(" -> %s",l_sexp[wl_sel]);
        gotoxy(63, 22); printf("└ ✉-");
        gotoxy(57, 34);                                                //단계 진입 전 안내문구
        printf("     %s에게                  ", l_tri[0]);
        gotoxy(57, 35);
        printf("      %d.%02d.%02d/%02d ~ %d.%02d.%02d/%02d, %s 가", l_lim[1][0], l_lim[1][1], l_lim[1][2], l_lim[1][3], l_lim[0][0], l_lim[0][1], l_lim[0][2], l_lim[0][3], l_tri[1]);
        gotoxy(57, 37);
        printf("         [작성을 완료하시려면 space bar를 눌러주세요]     ");
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
                case '\b':
                    if(i) printf("\b \b");
                    if(i) i--;
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
            case 'f': 
                if(wl_sel!=1) wl_act++;
                if(wl_sel==2&&wl_act>8) wl_act=0;
                if(wl_sel!=2&&wl_act>1) wl_act=0; 
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
                if((wl_act-1)%4==0&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>9999) l_lim[(wl_act-1)/4][(wl_act-1)%4]=0;
                if((wl_act-1)%4==1&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>12) l_lim[(wl_act-1)/4][(wl_act-1)%4]=1;
                if((wl_act-1)%4==2&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>31) l_lim[(wl_act-1)/4][(wl_act-1)%4]=1;
                if((wl_act-1)%4==3&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>23) l_lim[(wl_act-1)/4][(wl_act-1)%4]=0;
                break;
            case 's':
                if(wl_sel==2&&wl_act) l_lim[(wl_act-1)/4][(wl_act-1)%4]--;
                if((wl_act-1)%4==0&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=9999;
                if((wl_act-1)%4==1&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<=0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=12;
                if((wl_act-1)%4==2&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<=0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=31;
                if((wl_act-1)%4==3&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=23;
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
    l_tri[2][0]=l_lim[0][0]/1000+48;l_tri[2][1]=l_lim[0][0]/100%10+48;l_tri[2][2]=l_lim[0][0]/10%10+48;l_tri[2][3]=l_lim[0][0]%10+48;
    l_tri[2][4]=l_lim[0][1]/10+48;l_tri[2][5]=l_lim[0][1]%10+48;l_tri[2][6]=l_lim[0][2]/10+48;l_tri[2][7]=l_lim[0][2]%10+48;l_tri[2][8]=l_lim[0][3]/10+48;l_tri[2][9]=l_lim[0][3]%10+48;
    l_tri[2][10]=l_lim[1][0]/1000+48;l_tri[2][11]=l_lim[1][0]/100%10+48;l_tri[2][12]=l_lim[1][0]/10%10+48;l_tri[2][13]=l_lim[1][0]%10+48;
    l_tri[2][14]=l_lim[1][1]/10+48;l_tri[2][15]=l_lim[1][1]%10+48;l_tri[2][16]=l_lim[1][2]/10+48;l_tri[2][17]=l_lim[1][2]%10+48;l_tri[2][18]=l_lim[1][3]/10+48;l_tri[2][19]=l_lim[1][3]%10+48; l_tri[2][20]='\0';
    beforerand(1);
    for(i=0;i<3;i++) eCoding(1, l_tri[i], sizeof(l_tri[i]), '\0');                     //문단 인코딩 작업
    beforerand(0);
    for(i=0;i<l_mc;i++) {                //본문 인코딩 작업
        eCoding(1, l_m[i], sizeof(l_m[i])-1, '\n');
    }
    for(i=0;l_tit[i]!='\0';i++); //글자수 세기
    if(i<=99) {
        l_tit[i]='_';
        l_tit[i+1]='\0';
    }
    fp2=fopen(l_tit, "w");                       //변환된 편지이름으로 출력
    for(i=0;i<3;i++) fprintf(fp2, "%s\n", l_tri[i]);
    fprintf(fp2, "%d\n", l_mc);
    for(i=0;i<l_mc;i++) {  //변환된 본문 출력
        fprintf(fp, "%s", l_m[i]);
    }
    drawnletter();
    gotoxy(57, 35);
    printf("                  편지 작성이 완료되었습니다!              ");
    fclose(fp2);
    SSleep(3);
    return 0;
}
/*********************************************************************************************************************************/
int ltuto() {
    drawbody();
    drawletter();
    for(int _i=13;_i<18;_i++) {
        gotoxy(56,14+_i);
        printf("|                                                              |");
    }
    gotoxy(57, 32-4);                                                //단계 진입 전 안내문구
    printf("     사용자 에게                  ");
    gotoxy(57, 34-4);
    printf("                                2023.03.12/4, 튜토리얼 이");
    gotoxy(57, 36-4);
    printf("       [튜토리얼을 시작하시려면 space bar를 눌러주세요]   ");
    int bre=1;
    while(bre) switch(getch()) {
        case ' ':
            CursorView(0);
            bre=0;
            break;
        default:
            CursorView(0);
            return 1;
            break;
    }
    int l_mc=50;
    char l_m[50][540]={"안녕하세요, 사용자님! 저는 이 LimitLetter의 튜토리얼이에요!\n",
                       "현재, 이 프로그램의 개발자가 많이 논 나머지, 이 프로그램은 2.0b에 머물러 있어요..\n",
                       "네, beta의 약자로서의 b랍니다.\n",
                       "결국 일을 저질러 버렸지만, 이해해달라는 소리가 들리는 거 같지 않나요?\n",
                       "아무튼, 이 프로그램은 기본적으로 편지 입출력 및 암호화 프로그램이에요.\n",
                       "지금은 읽기 모드를 모방하여 튜토리얼중이란 뜻이죠!\n",
                       "일단, 가장 기본적인 조작법! 이 뒤에 커서가 깜박일 거에요, 그 때에 아무 키나 눌러보\n",
                       "\n",
                       "잘 하셨어요! 대충 커서가 깜박일 때면 아무 키나 누르시면 될 거에요!\n",
                       "갑작스럽긴 하지만, 한번 시나 읇어볼께요!\n",
                       "산산히 부서진 이름이여\n",
                       "허공중에 헤어진 이름이여\n",
                       "불러도 대답 없는 이름이여\n",
                       "부르다가 내가 죽을 이름이여\n",
                       "\n",
                       "심중에 남아있는 말 한마디는\n",
                       "끝끝내 마저 하지 못하였구나.\n",
                       "사랑하던 그 사람이여\n",
                       "사랑하던 그 사람이여\n",
                       "\n",
                       "붉은 해는 서산 마루에 걸리었다.\n",
                       "사슴의 무리도 슬피 운다.\n",
                       "떨어져 나가 앉은 산 위에서\n",
                       "나는 그대의 이름을 부르노라\n",
                       "\n",
                       "설움에 겹도록 부르노라.\n",
                       "설움에 겹도록 부르노라.\n",
                       "부르던 소리는 비껴가지만\n",
                       "하늘과 땅 사이가 너무 넓구나.\n",
                       "\n",
                       "선 채로 이 자리에 돌이 되어도\n",
                       "부르다가 내가 죽을 이름이여\n",
                       "사랑하던 그 사람이여\n",
                       "사랑하던 그 사람이여.\n",
                       "\n",
                       "헤헤ㅡ 갑자기 왜 부르냐고요?\n",
                       "40줄을 넘겨서 다음 페이지로 이동하기 위해서지요!\n",
                       "3,\n",
                       "1!\n",
                       "지금이에요! 페이지를 넘어갈 땐 d를 입력해주셔야 되어요! 꼭!\n",
                       "잘하셨어요! 방금 막 만들어진 페이지 넘기기를 익히셨네요!\n",
                       "이제, 저는 슬픈 소식 몇 가지 다시 전하고 끝내야해요.\n",
                       "바로, 이 버전이 베타라는 소식이죠.\n",
                       "이게 왜 슬픈 소식이라면, 설정과 색 배경, 패치노트는 적용 안 되었기 때문이에요.\n",
                       "또, 튜토리얼도 읽는 것만 가능하죠. 이 얼마나 반쪽짜리 튜토리얼 인가요?\n",
                       "또, 나가기 기능과 서식 도 못 지정해요! 특히 나가기는 끔직해요ㅠㅜㅠㅜ\n",
                       "작성 시엔, a/d 로 항목 이동과, w/s 로 시간 조절, f로 항목 들어가기, <로 항목 나가기가\n",
                       "아마.. 될거에요. 그렇게 되어있긴 하지만, 충격적인 사실은\n",
                       "프로그램 내 한글 사용이 안되요! 이건 너무 잔인해요..\n",
                       "윽, 50줄이에요. 가야할 시간이에요. a / d로 읽은 페이지 간 이동이 가능해요!.!\n",};       
    drawmain(l_mc<=40?11:10);
    gotoxy(44, 3);
    printf(" 사용자 에게                  ");
    int kk=-1;
    for(k=0;k<l_mc/40+(l_mc%40?1:0);k++) { 
        CursorView(0);
        if(k) drawmain(k+1==(l_mc/40+(l_mc%40?1:0))?1:0);
        else if(kk!=-1) drawmain(l_mc<=40?11:10);
        gotoxy(44+1+1, 46);
        printf("%c%02d / %02d%c", !k?'[':'<', k+1, l_mc/40+(l_mc%40?1:0), (k+1==(l_mc/40+(l_mc%40?1:0)))?']':kk>=k?'>':'|');
        for(i=0;i<40&&((k*40+i)<l_mc);i++) {                              //페이지, 문단별 출력
            gotoxy(44, 5+i);
            if(l_m[k*40+i][0]=='\n'&&!l_m[k*40+i][1]&&kk<k) {
                gotoxy(44, 5+i);
                CursorView(1);
                switch(getch()) {
                    case 'd': if(kk>=k) { bre=-1; i=40; } break;
                    case 'a': if(k!=0) { k-=2; bre=-1; i=40; } break;
                    default: break;
                }
                CursorView(0);
            }
            else {
                printf("%s", l_m[k*40+i]);
                if(kk<k) SSleep(1);
            }
        }
        gotoxy(44, 5+i);
        CursorView(1);
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
            case 'a': if(k!=0) k-=2; bre=0; break;
            case ' ': if(k+1==l_mc/40+(l_mc%40?1:0)) {
                bre=0; break;
            }
            else {printf("\a"); break;}
            default: printf("\a"); break;
        }
    }
    gotoxy(54, 45);
    printf("                                            2023.03.12/4, 튜토리얼 이");
    CursorView(0);
    bre=1;
    while(bre) switch(getch()) {
        case ' ': bre=0; break;
        default: printf("\a"); break;
    }
    return 0;
}