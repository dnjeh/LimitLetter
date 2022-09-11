#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
int i, j;
void letter_space(char *sentence, int space) {
    int k;
    char _sentence[999];
    strcpy(_sentence, sentence);
    for(k=0;k<999;k++) {
        if(_sentence[k] == '\0') {
			break;
        }
    }
    k=space-k;
    for(;k>0;k--) {
        printf(" ");
    }
}
int time_vaild();

int letter_limit[3][4] ={{2022, 9, 11, 21}, {2022, 9, 11, 19}, {0, 0, 0, 0}}; //유효기간 입력

int main(){
    system("mode con cols=44 lines=14");
    system("chcp 949");
    system("cls");
    int k;
    int letter_mainc = 4; //문단 수
    char  *letter_main[4][8] = { { //첫 문단
    "d",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    },{                              //둘째 문단
    "s",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    },{                              //셋째 문단
    "a",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    },{                              //넷째 문단
    "f",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    } };
    char  *command;
    char  *letter_top    = {"홍길동에게"};
    char  *letter_bottom = {"2022.09.11, 박리다매가"};
    char  *letter_ps     = {"추신 : "};
    time_t t;
    t = time(NULL);
    struct tm* monthandday;
    monthandday = localtime(&t);
    letter_limit[2][0] = monthandday->tm_year + 1900;
    letter_limit[2][1] = monthandday->tm_mon + 1;
    letter_limit[2][2] = monthandday->tm_mday;
    letter_limit[2][3] = monthandday->tm_hour;
    if(time_vaild()) {
        printf("  ________________________________________ \n");
        printf(" /_                                     _/|\n");
        printf("|  /__                               __/  |\n");
        printf("|     /__                         __/     |\n");
        printf("|        /__                   __/        |\n");
        printf("|           /__             __/           |\n");
        printf("|              /___________/              |\n");
        printf("|                                         |\n");
        printf("| %s", letter_top);
        letter_space(letter_top, 39);
        printf(" |\n");
        printf("|                                         |\n");
        printf("| ");
        letter_space(letter_bottom, 39);
        printf("%s |\n", letter_bottom);
        printf("|                                         |\n");
        printf(" ----------------------------------------- \n");
        system("pause");
        for(i=0;i<letter_mainc;i++) {
            switch(i) {
                case 0:
                    command="mode con cols=94 lines=13";
                    break;
                case 1:
                    command="mode con cols=94 lines=22";
                    break;
                case 2:
                    command="mode con cols=94 lines=31";
                    break;
                case 3:
                    command="mode con cols=94 lines=43";
                    break;
                default:
                    break;
            }
            system(command);
            system("cls");
            printf(" ____________________________________________________________________________________________ \n");
            printf("/ %s ", letter_top);
            letter_space(letter_top, 90);
            printf("/\n");
            printf("/ %90s /\n", " ");
            for(j=0;j<=i;j++) {
                for(k=0;k<8;k++) {
                    printf("/ %s ", letter_main[j][k]);
                    letter_space(letter_main[j][k], 90);
                    printf("/\n");
                }
                printf("/ %90s /\n", " ");
            }
            if(i==letter_mainc-1)  {
                printf("/");
                letter_space(letter_bottom, 90);
                printf(" %s /\n", letter_bottom);
                printf("/ %s ", letter_ps);
                letter_space(letter_ps, 90);
                printf("/\n");
            }
            else system("pause");
            printf(" -------------------------------------------------------------------------------------------- \n");
        }
    }
    else {  
        printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        printf("| _                                     _ |\n");
        printf("     _                               _     \n");
        printf("|       _                         _       |\n");
        printf("           _                   _           \n");
        printf("|             _             _             |\n");
        printf("                _ _ _ _ _ _                \n");
        printf("|                                         |\n");
        printf("                                           \n");
        printf("|      유효기간 내의 편지가 아닙니다.     |\n");
        printf("                                           \n");
        printf("|                                         |\n");
        printf(" - - - - - - - - - - - - - - - - - - - - - \n");
    }
    system("pause");
    return 0;
}

int time_vaild() {
    long long int letter_vaild[3];
    int bre=1;
    for(i=0;i<3;i++) {
        letter_vaild[i] = letter_limit[i][0]*365*24+letter_limit[i][2]*24+letter_limit[i][3];
        bre=1;
        while(bre) {
            switch(letter_limit[i][1]) {
                case 12: case 10: case 8: case 7: case 5: case 3: case 1:
                    letter_vaild[i]+=31*24;
                    break;
                case 11: case 9: case 6: case 4:
                    letter_vaild[i]+=30*24;
                    break;
                case 2:
                    if((letter_limit[i][0]%4==0&&letter_limit[i][0]%100!=0)||letter_limit[i][0]%400==0) {
                        letter_vaild[i]+=29*24;
                    }
                    else {
                        letter_vaild[i]+=28*24;
                    }
                    break;
                default:
                    bre=0;
                    break;
            }
            letter_limit[i][1]--;
        }
    }
    if(letter_vaild[0]>=letter_vaild[2]&&letter_vaild[1]<=letter_vaild[2]) return 1;
    else return 0;
}
