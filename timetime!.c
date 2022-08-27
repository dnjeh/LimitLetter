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
    int i, j, k, letter_timelimit[4] ={2022, 8, 7, 19}; //유효기간(년, 월, 일, 시) 입력
    char  *letter_main[4][8] = { { //1문단
    " 안녕하세요 종이님! 벌써 8월이에요! 여름이 무르익어갈 시점이지요",
    "종이님은 그동안 공부 열심히 하셨는지요?",
    "원하고 원하는 고등학교에 안정적으로 들어가셨으면 좋겠어요",
    "왜 지금에서야 이리 대화(아님)을 나눌려 한다면",
    "if( Teoram == :) )이 참이 되어 인사가 가능하게 되었기 때문이죠!",
    "물론 말 그대로 인사밖에 못 하겠지만,, 그래도 보내는 거 자체로 다행이라 생각해요",
    "아직 말 할 수 있는 거니깐요",
    "그리고! 제 이야기는 2문단에서 할 것이라죠!"
    },
    {                              //2문단
    " 저는 이 중요한 시기의 중요한 여름방학을..",
    "놀고있어요! 네! 놀고있어요!",
    "처음엔 수학 아주 기초적인 문제집이라고 풀려 했는데",
    "이젠 먼지만 쌓여간답니다.. 어렵더라고요...",
    "기능사 시험을 앞두고 있는데 합격했으면 좋겠어요!",
    "공부도 안하면서 바라는 것이지만서도요",
    "그래도 멘탈이 단단해진 거 같아 다행이에요",
    "아물진 않겠지만요.."
    },
    {                              //3문단
    " 왜 제가 이런 프로그램 형식으로 인사를 하는지 물으신다면",
    "장거리 SNS는 무섭기 때문이에요",
    "네! 그 뿐이랍니다",
    "이 계정으로 디스코드를 쓰다보면",
    "자꾸 그 이야기가 펼쳐져서 꼼작 못 하기도 하고요",
    "이제는 나간, 나가진 서버도 눈에 보이고요..",
    "그래도 언젠가는 아예 잊거나 마냥 이야기로 바라보겠지요?",
    "그러면 좋겠네요.."
    },
    {                              //4문단
    " 벌써 쓸 수 있는 란이 얼마 안 남았네요!",
    "이걸로 보내는 편지는 최대 32문장을 담을 수 있어요",
    "그리고 혹시 모를 유출을 위해 시간제한이 있답니다",
    "왜 유출을 염려하는지 물어보신다면",
    "그것 또한 다른 이야기 때문이랍니다",
    "물ㄹㄹㄹㄹㄹㄹㄹㄹㄹㄹㄹㄹㄹㄹㄹ론 못 믿는건 아니에요! 믿어주세요",
    "못 믿었으면 올해초부터라도 무얼 못 보냈을태니.",
    "그럼, 행복히 사시길 바라요!"
    }
    };
    char  *letter_top = {"한창 못 본 종이님에게"};
    char  *letter_bottom = {"2022년 8월 상반기, 어느정도 안정된 수목초 올림"};
    char  *letter_ps = {"이 프로그램은 이번이 처음이라 버그가 있어요! 다음엔 수정할거에요"};
    struct tm* monthandday;
    monthandday = localtime(&t);

    int nowyear = monthandday->tm_year + 1900;
    int nowmonth = monthandday->tm_mon + 1;
    int nowday = monthandday->tm_mday;
    int nowhour = monthandday->tm_hour;
    if(letter_timelimit[0]>=nowyear&&letter_timelimit[1]>=nowmonth&&letter_timelimit[2]>=nowday&&letter_timelimit[3]>=nowhour)
        for(i=0;i<4;i++) {
            system("cls");
            printf(" ____________________________________________________________________________________________ \n");
            printf("/ %s ", letter_top);
            letter_space(letter_top);
            printf("\n");
            printf("/ %90s \n", " ");
            for(j=0;j<=i;j++) {
                for(k=0;k<8;k++) {
                    printf("/ %s ", letter_main[j][k]);
                    letter_space(letter_main[j][k]);
                    printf("\n");
                }
                printf("/ %90s \n", " ");
            }
            if(i==3)  {
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