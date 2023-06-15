#include "../lletterc.h"

/*********************************************************************************************************************************/
int lwrite() {
    int i, j, k;
    char _t[5], lw_tt;
    if(!lsearch(0)) return 0;
    fclose(fp);
    fp=fopen(l_tit, "r");
    for(l_mc=0;!feof(fp);l_mc++) {
        fscanf(fp, "%*[^\n]");
        fscanf(fp, "%*c");
    }
    char l_m[l_mc][540];
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
    draw_oletter();
    time_land(1);
    while(bre) {
        bre2=1;
        for(i=0;i<5;i++) {
            gotoxy(l_goto[i][0]-2, l_goto[i][1]);
            printf("%c %s %c", wl_sel==i?(wl_sel==1?'X':wl_act?'<':'>'):' ', l_stit[i], ':');
            switch(i) { 
                case 0: printf(" %-40s", l_tit); break;
                case 1: printf(" %d line%c", l_mc, l_mc==1?'\0':'s'); break;
                case 2: printf(" %4d.%02d.%02d/%02d - %4d.%02d.%02d/%02d", l_lim[1][0], l_lim[1][1], l_lim[1][2], l_lim[1][3], l_lim[0][0], l_lim[0][1], l_lim[0][2], l_lim[0][3]); break;
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
            cursorView(1);
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
                if(wl_act!=4) {
                    wl_act+=12;
                    wl_act%=8;
                } else wl_act=8;
                if(wl_sel==2&&wl_act) l_lim[(wl_act-1)/4][(wl_act-1)%4]++;
                if((wl_act-1)%4==0&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>9999) l_lim[(wl_act-1)/4][(wl_act-1)%4]=0;
                if((wl_act-1)%4==1&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>12) l_lim[(wl_act-1)/4][(wl_act-1)%4]=1;
                if((wl_act-1)%4==2&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>31) l_lim[(wl_act-1)/4][(wl_act-1)%4]=1;
                if((wl_act-1)%4==3&&l_lim[(wl_act-1)/4][(wl_act-1)%4]>23) l_lim[(wl_act-1)/4][(wl_act-1)%4]=0;
                wl_act+=12;
                wl_act%=8;
                break;
            case 's':
                if(wl_act!=4) {
                    wl_act+=12;
                    wl_act%=8;
                } else wl_act=8;
                if(wl_sel==2&&wl_act) l_lim[(wl_act-1)/4][(wl_act-1)%4]--;
                if((wl_act-1)%4==0&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=9999;
                if((wl_act-1)%4==1&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<=0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=12;
                if((wl_act-1)%4==2&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<=0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=31;
                if((wl_act-1)%4==3&&l_lim[(wl_act-1)/4][(wl_act-1)%4]<0) l_lim[(wl_act-1)/4][(wl_act-1)%4]=23;
                wl_act+=12;
                wl_act%=8;
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
        cursorView(0);
    }
    l_tri[2][0]=l_lim[0][0]/1000+48;l_tri[2][1]=l_lim[0][0]/100%10+48;l_tri[2][2]=l_lim[0][0]/10%10+48;l_tri[2][3]=l_lim[0][0]%10+48;
    l_tri[2][4]=l_lim[0][1]/10+48;l_tri[2][5]=l_lim[0][1]%10+48;l_tri[2][6]=l_lim[0][2]/10+48;l_tri[2][7]=l_lim[0][2]%10+48;l_tri[2][8]=l_lim[0][3]/10+48;l_tri[2][9]=l_lim[0][3]%10+48;
    l_tri[2][10]=l_lim[1][0]/1000+48;l_tri[2][11]=l_lim[1][0]/100%10+48;l_tri[2][12]=l_lim[1][0]/10%10+48;l_tri[2][13]=l_lim[1][0]%10+48;
    l_tri[2][14]=l_lim[1][1]/10+48;l_tri[2][15]=l_lim[1][1]%10+48;l_tri[2][16]=l_lim[1][2]/10+48;l_tri[2][17]=l_lim[1][2]%10+48;l_tri[2][18]=l_lim[1][3]/10+48;l_tri[2][19]=l_lim[1][3]%10+48; l_tri[2][20]='\0';
    beforeRand(1);
    for(i=0;i<3;i++) eCoding(1, l_tri[i], sizeof(l_tri[i]), '\0');                     //문단 인코딩 작업
    beforeRand(0);
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
    draw_nletter();
    gotoxy(57, 35);
    printf("                  편지 작성이 완료되었습니다!              ");
    fclose(fp2);
    sSleep(3);
    return 0;
}