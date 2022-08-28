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
int letter_etimelimit[4] ={2022, 8, 28, 21}, letter_stimelimit[4] ={2022, 8, 28, 21}, letter_ntime[4]; //유효기간(년, 월, 일, 시) 입력

int main(){
    system("chcp 949");
    system("cls");
    int i, j, k;
    int letter_mainc = 4; //문단수 입력
    char  *letter_main[4][8] = { { //1문단
    " 근 2주간 잘 지내셨나이까?",
    "이 2주라는 시간은 해와 달이 14번 뜨고 질 시간이고",
    "뜨겁던 그 여름날이 식는 시간이며",
    "본격적인 2학기 준비를 위한 시간이였죠",
    "뭐.. 전 방학이 언제였냐는듯 다시 익숙해 있지만서도요!",
    "아! 맞아요 저번에 못 고쳤던 버그가 이거에요!",
    "왼쪽에 테두리 못 단거!",
    "그럼 본격적으로 시작해볼께요"
    },{                              //2문단
    " 방학이 끝났어요! 이제 다시 교복을 갈아입고, 수업을 졸면서도 듣고",
    "하교를 하고 다시 집에 오죠. 당신은 어떻게 보냈으려나요?",
    "개학을 하고 2~3주 뒤, 추석연휴가 있다는 것을 알고 전 너무 기쁜 나머지",
    "시간을 달리듯 살아왔어요! 당신도 기뻐하셨으려나요?",
    "기능사 시험은.. 간당간당한데 붙을 거 같애요! 다행히도요! 가채점 65랍니다",
    "NYPC라는 것에도 나가봤는데 2라운드 문제가 어려워요.. 100점 만점이라 한다면 겨우 14점!",
    "당신도 중간기말을 치고 코드도 아이들?로 열심히 짜고 있겠지요?? 꼭 목푤 성취해주어요!!!",
    "나도 이 아이들과 협업하며 나무를 심고 가지도 치면서 지금이라도 숲을 이루니.."
    },{                              //3문단
    " 이 나무 관리자, gardener-in-trees는 정말 신묘해요!",
    "나무를 가져와 근처의 화분에 심고, 이 화분에서 나무를 역으로 짜요!",
    "마치 종이에서 나무를 뽑아내는 거 같아요",
    "가지도 나게 하고, 치기도 하고, 어느정도 다듬어졌을때 다시 구름수목원에 데려가요!",
    "그 구름수목원은 정말이지 아름다웠어요.. 세상에나",
    "나무가 나무를 심고 수백만 나무들이 실시간으로 자라날줄이야..",
    "제가 본 가장 큰 나무는 이녹수였어요 그 나무는 나무들을 심기 위한 나무였죠..",
    "정말 꿈 속 세상 같지 않나요?"
    },{                              //4문단
    " 아 그리고 지금 배우는 원의 방정식은 정말이지 아름다웠어요",
    "너무 기뻤어요! 드디어 내가 제대로 이해하는 개념이 나와서",
    "드디어 이 수업이 단순 필기가 아니여서..",
    "여튼, 수업 동기가 조금 증가했답니다.",
    "전공도 좀 떨어지게 되었고요. 아 맞아 이론전공이 실습전공이 되기도 했어요!",
    "벌써 3줄이라니.. 시간이 참 느리네요 보낼줄 알았는데. 아 그리고 새 기능!",
    "이제 시작 열람 시간도 추가되었답니다. 짜잔! 언제 열리고 닫힐 편지일까요?",
    "언제동안 보낼 수 있고 어느때에 끊길 편지일까요?"
    } };
    char  *letter_top    = {"희미하지만 반짝이는 별인 종이님께"};
    char  *letter_bottom = {"2022.08.28 휴일이 머지 않음을 감지해 기쁜 수목초 올림"};
    char  *letter_ps     = {"추신 : 다음 기능 ----> then <- / lapping"};
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
        if(letter_stimelimit[i]<letter_ntime[i]&&letter_etimelimit[i]>letter_ntime[i])
            return 1;
        else if(letter_stimelimit[i]>letter_ntime[i]||letter_etimelimit[i]<letter_ntime[i])  
            return 0;
    }
    return 1;
}
