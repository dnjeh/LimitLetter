#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
void letter_space(char *sentence) {
    char _sentence[999];
    strcpy(_sentence, sentence);
    int i= 0;
    for(i=0;i<999;i++) {
        if(_sentence[i] == '\0') {
			break;
        }
    }
    i=90-i;
    for(;i>0;i--) {
        printf(" ");
    }
}
int time_vaild();
int letter_etimelimit[4] ={2022, 9, 3, 23}, letter_stimelimit[4] ={2022, 9, 3, 21}, letter_ntime[4]; //ï¿½ï¿½È¿ï¿½â°£(ï¿½ï¿½, ï¿½ï¿½, ï¿½ï¿½, ï¿½ï¿½) ï¿½Ô·ï¿½

int main(){
    system("chcp 949");
    system("cls");
    int i, j, k;
    int letter_mainc = 1; //ï¿½ï¿½ï¿½Ü¼ï¿½ ï¿½Ô·ï¿½
    char  *letter_main[4][8] = { { //1ï¿½ï¿½ï¿½ï¿½
    " ¿À´ÃÀÌ ´ç½ÅÀÇ »ýÀÏÀÌ¶ó´Â ¼Ò¹®À» µé¾úÀ¸³ª,",
    "°³ÀÎÀûÀÎ »çÁ¤À¸·Î ÀÌ·± ÇüÅÂ·Î ¼±¹°À» º¸³»°íÀÚ ÇÏ´Ï",
    "ÀÌ·Î ÀÎÇØ ¼±¹°ÄÚµå¸¦ º¸³»°íÀÚ ÇÔ",
    "SQ2APYVSY9",
    "*ÁÖÀÇ* ÇØ´ç ¸Þ¼¼Áö´Â Áö±ÝÀ¸·ÎºÎÅÍ 3½Ã°£µ¿¾È¸¸ À¯È¿ÇÔ",
    "",
    "",
    ""
    },{                              //2ï¿½ï¿½ï¿½ï¿½
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    },{                              //3ï¿½ï¿½ï¿½ï¿½
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    },{                              //4ï¿½ï¿½ï¿½ï¿½
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    } };
    char  *letter_top    = {"ÇÑ ¶§ ÀºÁö¶ó°í ºÒ¸®¾ú´ø ºÐ²²"};
    char  *letter_bottom = {"2022³â 9¿ù 3ÀÏ, ÇÑ ¶§ ÃÊ¶÷ÀÌ¶ó°í ºÒ·È´ø ÀÚ°¡"};
    char  *letter_ps     = {"Ãß½Å : »ýÀÏ ÃàÇÏµå·Á¿ä, Áñ°Å¿î »ýÀÏÀÌ¿´±æ.."};
    time_t t;
    t = time(NULL);
    struct tm* monthandday;
    monthandday = localtime(&t);
    letter_ntime[0] = monthandday->tm_year + 1900;
    letter_ntime[1] = monthandday->tm_mon + 1;
    letter_ntime[2] = monthandday->tm_mday;
    letter_ntime[3] = monthandday->tm_hour;
    if(time_vaild())
        for(i=0;i<letter_mainc;i++) {
            system("cls");
            printf(" ____________________________________________________________________________________________ \n");
            printf("/ %s ", letter_top);
            letter_space(letter_top);
            printf("/\n");
            printf("/ %90s /\n", " ");
            for(j=0;j<=i;j++) {
                for(k=0;k<8;k++) {
                    printf("/ %s ", letter_main[j][k]);
                    letter_space(letter_main[j][k]);
                    printf("/\n");
                }
                printf("/ %90s /\n", " ");
            }
            if(i==letter_mainc-1)  {
                printf("/");
                letter_space(letter_bottom);
                printf(" %s /\n", letter_bottom);
                printf("/ %s ", letter_ps);
                letter_space(letter_ps);
                printf("/\n");
            }
            else system("pause");
            printf(" -------------------------------------------------------------------------------------------- \n");
        }
    else  
        printf(":/\n");
    system("pause");
    return 0;
}

int time_vaild() {
    for(int i=0;i<4;i++) {
        if(letter_stimelimit[i]<=letter_ntime[i]&&letter_etimelimit[i]>letter_ntime[i])
            return 1;
        else if(letter_stimelimit[i]>letter_ntime[i]||letter_etimelimit[i]<letter_ntime[i])  
            return 0;
    }
    return 1;
}
