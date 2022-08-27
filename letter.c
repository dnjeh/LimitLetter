#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
void letter_space(char *sentence) {
    char _sentence[999];
    strcpy(_sentence, sentence);
    int ii, jj = 0;
    for(ii=0;ii<999;ii++) {
        if(_sentence[ii] == '(' || _sentence[ii] == ')' || _sentence[ii] == '!' || _sentence[ii] == '=' || _sentence[ii] == ':' || _sentence[ii] == '.' || _sentence[ii] == '\"' || _sentence[ii] == ' ' || _sentence[ii] == '\'' || _sentence[ii] == '\n' || (_sentence[ii] < '{' && _sentence[ii] > '`') || (_sentence[ii] < '[' && _sentence[ii] > '@') || (_sentence[ii] < ':' && _sentence[ii] > '/'))
	    	jj++;
	    else if(_sentence[ii] == '\0')
			ii=999;
        else
            //printf("\n현재 ii는 %c, jj는 %d!", _sentence[ii], jj);
	    	jj++;
            jj++;
            ii+=3;
    }
    for(ii=0;ii<(90-jj);ii++)
        printf(" ");
}
int main(){
    system("chcp 65001");
    system("cls");
    time_t t;
    t = time(NULL);
    int i, j, k;
    int letter_etimelimit[4] ={2022, 8, 15, 23}, letter_stimelimit[4] ={2022, 8, 9, 0}; //유효기간(년, 월, 일, 시) 입력
    int letter_mainc = 3; //문단수 입력
    char  *letter_main[4][8] = { { //1문단
    " 안영하시나이까? 저는 완운고전문학 학사",
    "김옥균박영효홍영식서광범급진갷라고 하옵니다",
    "다름이 아니오라 고대 문헌 탐색중 한 단어가 발췌되었습니다",
    "\'마왕은한국인\' 이라 하는 문학이랍니다",
    "관련 문학 탐색 요청이 지속적으로 들어와 탐색하던 도중",
    "배생숭 완운고전요약 전문가님의 요약 정리본의",
    "잘린 부분을 보아 급히 수록했습니다",
    "네, \'마왕은한국인\'관련해서 요청하고 싶은 것이 있습니다."
    },
    {                              //2문단
    " 현재 탐색 과정 도중에 배생숭 완운고전요약전문가님의 기록이",
    "시시각각 발견되고 있사옵니다.",
    "\'마왕은한국인\'이란 문학과 그 문학의 요약본을 보내시고,",
    "또 그 후속작인 \'고자시대\'를 원조 작가님인 박픈지 황제님의 말을 들으며",
    "깔끔하게 정리하시되 저",
    "김옥균박영효홍영식서광범급진갷는 감탄을 금치 못했습니다.",
    "이에 문의하고자 하옵나니다",
    "\'마왕은한국인\'의 요약본이라도 보내주실수 있으시나이까?"
    },
    {                              //3문단
    " 원래는 요약본을 먼저 싣고 원본을 찾고자 하였으나,",
    "그 원본은 첫 ACJE서버에 유물처럼 남아있다 하여",
    "탐색하는데 시간이 많이 걸릴 뿐 더러",
    "그 서버는 중간에 테러를 당한 기록이 있어",
    "확실히 있을지도 모르는 상태랍니다",
    "이에, 요약본이라도 먼저 제대로 싣고자 이 편지를 보내옵나이다",
    "원본은 그 때도 이미 읽어버리셨기에 이렇게 아뢰옵나이다",
    "부디 지금은 사라졌을수 있는 요약본을 보내오주옵소서.."
    },
    {                              //4문단
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
    }
    };
    char  *letter_top = {"배생숭 완운고전요약 전문가님께"};
    char  *letter_bottom = {"2022년 8월 15일, 원본도 찾고자 하는 수목초 올림"};
    char  *letter_ps = {"당신이 행복히 지내면 그무엇이 좋으리까"};
    struct tm* monthandday;
    monthandday = localtime(&t);

    int nowyear = monthandday->tm_year + 1900;
    int nowmonth = monthandday->tm_mon + 1;
    int nowday = monthandday->tm_mday;
    int nowhour = monthandday->tm_hour;
    if(letter_etimelimit[0]>=nowyear&&letter_etimelimit[1]>=nowmonth&&letter_etimelimit[2]>=nowday&&(letter_etimelimit[2]>nowday||letter_etimelimit[3]>=nowhour)&&letter_stimelimit[0]<=nowyear&&letter_stimelimit[1]<=nowmonth&&letter_stimelimit[2]<=nowday&&letter_stimelimit[3]<=nowhour)
        for(i=0;i<letter_mainc;i++) {
            system("cls");
            printf(" ____________________________________________________________________________________________ \n");
            printf("/ %s ", letter_top);
            letter_space(letter_top);
            printf("\n");
            printf("/ %90s \n", " ");
            for(j=0;j<=i;j++) {
                for(k=0;k<8;k++) {
                    printf("/ %s ", letter_main[j][k]);
                    //letter_space(letter_main[j][k]);
                    printf("\n");
                }
                printf("/ %90s \n", " ");
            }
            if(i==letter_mainc-1)  {
                printf("/");
                letter_space(letter_bottom);
                printf(" %s \n", letter_bottom);
                printf("/");
                printf(" 추신 : %s \n", letter_ps);
            }
            else system("pause");
            printf(" -------------------------------------------------------------------------------------------- \n");
        }
    else  
        printf(":/\n");
    system("pause");
    return 0;
}