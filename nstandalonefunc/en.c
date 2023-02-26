#include <stdio.h>   //177 50
#include <conio.h>   //94 **
#include <io.h>
#include <time.h>    //64 20
#include <windows.h>
#include <string.h>
#include <errno.h>
int l_lim[3][4] ={0,}; //Enter validity period
void beforerand(int _t) {  //Preseed operation, 0 to seed with time, 1 to seed with code
    if(!_t) srand(l_lim[0][0]+l_lim[0][1]+l_lim[0][2]+l_lim[0][3]+l_lim[1][0]+l_lim[1][1]+l_lim[1][2]+l_lim[1][3]+'a'+'u'+'t'+'u'+'m'+'n');
    else srand('w'+'i'+'n'+'t'+'e'+'r');
}
void gotoxy(int _x,int _y) { //gotoxy funcfion
    COORD pos={_x, _y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void SSleep(int _s) { //sleep a litte
    clock_t start_clk = clock();  // get start time
    _s--;  // It continuously calls the clock function to calculate the elapsed time.
    while(1) if((clock() - start_clk)/CLOCKS_PER_SEC>_s) break;  
}
void CursorView(int _t) { //Cursor active (1 visible, 0 invisible)
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Cursor thickness (1 to 100)
    cursorInfo.bVisible = _t?TRUE:FALSE; //Cursor Visible TRUE (visible) FALSE (hidden)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void RemoveEnter(char *sentence, int siz) {
    int _i;
    for(_i=0;sentence[_i]!='\0'&&_i<siz;_i++) {
        if(sentence[_i]=='\n') sentence[_i]='\0';
    }
}
void eCoding(int _t, char sentence[], int siz, char end_char) { //Time 1 Encoding (Conversion) Time 0 Decoding (Reading)
    int _i;
    if(_t) for(_i=0;sentence[_i]!=end_char&&_i<siz;_i++) {
        sentence[_i]=sentence[_i]+rand()%3;
    }
    else for(_i=0;sentence[_i]!=end_char&&_i<siz;_i++) {
        sentence[_i]=sentence[_i]-rand()%3;
    }
}
void drawmain() {    //Fill out the basic letter form
    int _i;
    for(_i=0;_i<46;_i++) {
        gotoxy(42, 1+_i);
        switch(_i) {
            case 0: case 45: printf(" ____________________________________________________________________________________________ "); break;
            default:  printf("| %90s |", " "); break;
        }
    }
}
int time_vaild() {                  //time validation function
    long long int l_vai[3];
    int bre=1, _t, _i;
    for(_i=0;_i<3;_i++) {
        l_vai[_i]=l_lim[_i][0]*365*24+l_lim[_i][2]*24+l_lim[_i][3];
        _t=l_lim[_i][1]-1;
        bre=1;
        while(bre) {
            switch(_t) {
                case 12: case 10: case 8: case 7: case 5: case 3: case 1:
                    l_vai[_i]+=31*24;
                    break;
                case 11: case 9: case 6: case 4:
                    l_vai[_i]+=30*24;
                    break;
                case 2:
                    if((l_lim[_i][0]%4==0&&l_lim[_i][0]%100!=0)||l_lim[_i][0]%400==0) {
                        l_vai[_i]+=29*24;
                    }
                    else {
                        l_vai[_i]+=28*24;
                    }
                    break;
                default:
                    bre=0;
                    break;
            }
            _t--;
        }
    }
    if(l_vai[0]>=l_vai[2]&&l_vai[1]<=l_vai[2]) return 1;
    else return 0;
}
void drawnletter() {
    int _i;
    for(_i=13;_i<18;_i++) {
        gotoxy(56,19+_i);
        printf("|                                                              |");
    }
}
void drawbody() {   //screen output function
    int _snowx, _snowy;
    gotoxy(0, 0);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
    gotoxy(0, 0);
    beforerand(1);
    for(_snowy=0;_snowy<50;_snowy++) {
        for(_snowx=0;_snowx<177;_snowx++) {
            gotoxy(_snowx, _snowy);
            if(!(rand()%25)) {
                printf("*");
            }
        }
    }
} //177 50 //94 ** //64 20
int main(){
    system("mode con cols=177 lines=50");        //preset paragraph
    system("chcp 65001");
    system("cls");
    int i, j, k, lselect=1, cnt=0;  //1Reading (decoding) at a time
    int bre=0, bre2=0, con=0;
    char l_tri[3][61], l_tit[61]; //First, last, digression (PS)
    char l_mc[3], l_ind[100][40]={'\0',}, path[8] = "*.let";
    char  *command;
    FILE *fp, *fp2; time_t t=time(NULL); intptr_t hFile;
    struct tm* monthandday; struct _finddatai64_t c_file;
    monthandday = localtime(&t);
    l_lim[2][0] = monthandday->tm_year + 1900;
    l_lim[2][1] = monthandday->tm_mon + 1;
    l_lim[2][2] = monthandday->tm_mday;
    l_lim[2][3] = monthandday->tm_hour;

    //-----------------------------------------Main ---------------------------------------------------
    home:
    CursorView(0);                               
    while(!bre2) {
        drawbody();
        drawletter();
        while(!bre) {                //main
            gotoxy(56, 32);
            printf("|                 open           txttoletter               |");
            gotoxy(113, 33);
            printf("v1.4+");
            if(lselect) gotoxy(71, 32);
            else gotoxy(90, 32);
            printf("√");
            switch(getch()) {
                case 'd': case 'a':
                    if(lselect==0) lselect=1;
                    else lselect=0;
                    break;
                case ' ':
                    bre=1;
                    break;
                default:
                    break;
            }
        }
        bre=0;                            

    //--------------------------------------------search-----------------------------------------------------                 
        if(lselect) strcpy(path, "*_");    //search letter&
        else strcpy(path, "*");
        if((hFile = _findfirsti64(path, &c_file))==-1L) {
            gotoxy(57, 32);
            switch(errno) {
                case ENOENT:
                    printf("Could not find file for current behavior"); break;
                case EINVAL:
                    printf("Letter format file not found (Did you change it randomly?)\n"); _findclose(hFile); break;
                case ENOMEM:
                    printf("File name is too long\n"); _findclose(hFile); break;
                default:
                    printf("This is an unknown error.\n"); _findclose(hFile); break;
            }
            SSleep(3);
            goto home;
        }
        else {
            cnt=0;
            strcpy(l_ind[cnt], c_file.name);
            for(cnt=1;_findnexti64(hFile, &c_file)==0;cnt++){
                strcpy(l_ind[cnt], c_file.name);
            } 
            _findclose(hFile); // Returns the memory used by _findfirsti64(), _findnexti64()
        }

        //---------------------------------------------------------------------------------------------------
        drawoletter();
        i=0;
        while(!bre) {
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
            printf("        [If this would the letter, press space bar]     ");
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
            fp=fopen(l_tit, "r");                       //read letter
            for(j=0;j<3;j++) {
                fgets(l_tri[j], sizeof(l_tri[j]), fp);
                RemoveEnter(l_tri[j], sizeof(l_tri[j]));
            }
            if(lselect) {                                            //decoding when reads it
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
                gotoxy(57, 32);                                                //Guidance before entering the stage
                printf("     %s에게                  ", l_tri[0]);
                gotoxy(57, 33);
                printf("      %d.%02d.%02d/%02d ~ %d.%02d.%02d/%02d, %s 가", l_lim[1][0], l_lim[1][1], l_lim[1][2], l_lim[1][3], l_lim[0][0], l_lim[0][1], l_lim[0][2], l_lim[0][3], l_tri[1]);
                gotoxy(57, 35);
                if(lselect) printf("         [Press the space bar to start reading]     ");
                else printf("         [Press the space bar to start change]     ");
                switch(getch()) {
                    case ' ':
                        bre2=bre=1;
                        break;
                    case 'd':
                        if(i+1<cnt) i++;
                    case 'a':
                        if(i-1>=0) i--;
                    default:
                        break;
                }
            }
            else {
                gotoxy(57, 35);
                printf(" [The letter is not within the validity period]");
                fclose(fp);
                SSleep(3);
                goto home;
            }
        }
    }

    //---------------------------------------------------------------------------------------------------
    bre2=bre=0;                                               //Read number of paragraphs before operation, create & initialize paragraph array accordingly
    CursorView(0);
    fgets(l_mc, sizeof(l_mc), fp);
    l_mc[0]-=48;
    char l_m[l_mc[0]][8][540];
    for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {
        strcpy(l_m[i][j] , "");
    }
    if(lselect) {                                                  //Output codes when reading                              
        drawbody();
        drawmain();
        beforerand(0);
        for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {
            fgets(l_m[i][j], sizeof(l_m[i][j]), fp); //Pre-read and decode operations
            eCoding(0, l_m[i][j], sizeof(l_m[i][j]), '\n');
        }
        fclose(fp);                                                     //file read end
        gotoxy(44, 3);
        printf(" to %s                                             ", l_tri[0]);
        for(k=0;k<(int)l_mc[0]/4+((int)l_mc[0]%4?1:0);k++) { 
            for(i=0;i<4&&((k*4+i)<(int)l_mc[0]);i++) {                              //Output per page and paragraph
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
        printf("                                                         %d.%02d.%02d, from %s     ", l_lim[2][0], l_lim[2][1], l_lim[2][2], l_tri[1]);
        CursorView(0);
    }

    //---------------------------------------------------------------------------------------------------

    else {                                   //When converting files (encoding)
        printf("0");
        for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {
            fgets(l_m[i][j], sizeof(l_m[i][j]), fp); 
        }
        fclose(fp);                                 //Read everything and close
        beforerand(1);
        for(i=0;i<3;i++) eCoding(1, l_tri[i], sizeof(l_tri[i]), '\0');                     //Paragraph Encoding
        beforerand(0);
        for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {                //body encoding task
            eCoding(1, l_m[i][j], sizeof(l_m[i][j])-1, '\n');
        }
        for(i=0;l_tit[i]!='\0';i++); //character count
        if(i<=59) {
            l_tit[i]='_';
            l_tit[i+1]='\0';
        }
        fp2=fopen(l_tit, "w");                       //Output as converted letter name
        for(i=0;i<3;i++) fprintf(fp2, "%s\n", l_tri[i]);
        fprintf(fp2, "%c\n", l_mc[0]+48);
        for(i=0;i<(int)l_mc[0];i++) for(j=0;j<8;j++) {  //Converted text output
            fprintf(fp, "%s", l_m[i][j]);
        }
        drawnletter();
        gotoxy(57, 35);
        printf("              Conversion to letter completed!          ");
        fclose(fp2);
    }
    SSleep(3);
    goto home;
}   