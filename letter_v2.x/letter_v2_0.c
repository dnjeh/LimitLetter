#include "lletterb.h" //177 50 //94 ** //64 20 //⚙️

int con=0;
int i, j, k, lselect=2, cnt=0;  //1일 시 읽기(디코딩)
char  *command;
FILE *fp, *fp2; intptr_t hFile; struct _finddatai64_t c_file;
char l_tri[3][61], l_tit[101]; //처음, 마지막, 여담(추신)
char l_mc[3], l_ind[100][40]={'\0',}, path[8] = "*.let";
int l_goto[5][2]={{59, 32}, {62, 32}, {71, 32}, {92, 32}, {111, 33}};
int home(); int lsearch(); int lread(); int lwrite();

int main(){
    system("mode con cols=177 lines=50");        //사전 설정 문단
    system("chcp 65001");
    system("cls");
    t=time(NULL);
    timeland();
    while(1) {
        switch(home()) {
        case 2:
            lread();
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
    CursorView(0);  
    timeland();       
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
int lsearch() {
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
        printf("        [이 파일이 곧 편지라면 space bar를 눌러주세요]     ");
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
        fp=fopen(l_tit, "r");                       //편지 읽기 
        for(j=0;j<3;j++) {
            fgets(l_tri[j], sizeof(l_tri[j]), fp);
            RemoveEnter(l_tri[j], sizeof(l_tri[j]));
        }
        if(lselect==2) {                                            //읽기 시 디코딩
            beforerand(1);
            for(j=0;j<3;j++) eCoding(0, l_tri[j], sizeof(l_tri[j]), '\0');
        }
        for(k=0;k<8;k++) {
            l_lim[k/4][k%4]=0;
        }
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
        if(time_vaild()) {
            gotoxy(57, 32);                                                //단계 진입 전 안내문구
            printf("     %s에게                  ", l_tri[0]);
            gotoxy(57, 33);
            printf("      %d.%02d.%02d/%02d ~ %d.%02d.%02d/%02d, %s 가", l_lim[1][0], l_lim[1][1], l_lim[1][2], l_lim[1][3], l_lim[0][0], l_lim[0][1], l_lim[0][2], l_lim[0][3], l_tri[1]);
            gotoxy(57, 35);
            if(lselect==1) printf("         [읽기를 시작하시려면 space bar를 눌러주세요]     ");
            else printf("         [작성을 시작하시려면 space bar를 눌러주세요]     ");
            switch(getch()) {
                case ' ':
                    CursorView(0);
                    fgets(l_mc, sizeof(l_mc), fp);
                    l_mc[0]-=48; //작업 전 문단 수 읽기, 그에 따른 문단 배열 생성&초기화
                    return 1;
                    break;
                case 'd':
                    if(i+1<cnt) i++;
                case 'a':
                    if(i-1>=0) i--;
                    fclose(fp);
                default:
                    break;
            }
        }
        else {
            gotoxy(57, 35);
            printf("               [유효기간 내의 편지가 아닙니다]");
            fclose(fp);
            SSleep(3);
            return 0;
        }
    }
}
/*********************************************************************************************************************************/
int lread() {
    if(!lsearch()) return 0;
    char l_m[l_mc[0]][8][540];
    for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {
        strcpy(l_m[i][j] , "");
    }                          
    drawbody();
    drawmain();
    beforerand(0);
    for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {
        fgets(l_m[i][j], sizeof(l_m[i][j]), fp); //사전 읽고 디코딩 작업
        eCoding(0, l_m[i][j], sizeof(l_m[i][j]), '\n');
    }
    fclose(fp);                                                     //파일 읽기 종료
    gotoxy(44, 3);
    printf(" %s 에게                                            ", l_tri[0]);
    for(k=0;k<(int)l_mc[0]/4+((int)l_mc[0]%4?1:0);k++) { 
        for(i=0;i<4&&((k*4+i)<(int)l_mc[0]);i++) {                              //페이지, 문단별 출력
            CursorView(0);
            gotoxy(44+40, 45);
            printf(" %02d / %02d", k*4+i+1, l_mc[0]);
            for(j=0;j<8;j++) {
                gotoxy(44, 5+i*9+j);
                printf("%s", l_m[k*4+i][j]);
                SSleep(1);
            }
            gotoxy(44, 6+i*9+j);
            CursorView(1);
            getch();
        }
        CursorView(0);
        if(k+1<(int)l_mc[0]/4+((int)l_mc[0]%4?1:0)) drawmain();
    }
    gotoxy(44, 42);
    printf("                                                         %d.%02d.%02d, %s 가     ", l_lim[2][0], l_lim[2][1], l_lim[2][2], l_tri[1]);
    CursorView(0);
    SSleep(3);
    return 0;
}
/*********************************************************************************************************************************/
int lwrite() {
    if(!lsearch()) return 0;
    char l_m[l_mc[0]][8][540];
    for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {
        fgets(l_m[i][j], sizeof(l_m[i][j]), fp); 
    }
    fclose(fp);                                 //일단 다 읽어놓고 닫기
    beforerand(1);
    for(i=0;i<3;i++) eCoding(1, l_tri[i], sizeof(l_tri[i]), '\0');                     //문단 인코딩 작업
    beforerand(0);
    for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {                //본문 인코딩 작업
        eCoding(1, l_m[i][j], sizeof(l_m[i][j])-1, '\n');
    }
    for(i=0;l_tit[i]!='\0';i++); //글자수 세기
    if(i<=59) {
        l_tit[i]='_';
        l_tit[i+1]='\0';
    }
    fp2=fopen(l_tit, "w");                       //변환된 편지이름으로 출력
    for(i=0;i<3;i++) fprintf(fp2, "%s\n", l_tri[i]);
    fprintf(fp2, "%c\n", l_mc[0]+48);
    for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {  //변환된 본문 출력
        fprintf(fp, "%s", l_m[i][j]);
    }
    drawnletter();
    gotoxy(57, 35);
    printf("                 편지로 변환이 완료되었습니다!             ");
    fclose(fp2);
    SSleep(3);
    return 0;
}
/*********************************************************************************************************************************/