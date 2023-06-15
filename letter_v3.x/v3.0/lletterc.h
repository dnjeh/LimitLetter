#include <stdio.h>   //177 50 //만국공통
#include <conio.h>   //94 **  //콘솔 관련 명령어 포함
#include <io.h>               //기억상, 파일 입출력 관련
#include <time.h>    //64 20  //시간 관련
#include <windows.h>          //콘솔2
#include <string.h>           //문자열 관련된 편리한 것들!
#include <errno.h>            //파일 쓸때 같이 씀

//받아온 편지 값들
extern int l_lim[3][4]; //유효기간 입력
extern int l_mc, lselect;  //1일 시 읽기(디코딩)
extern char  *command;
extern FILE *fp, *fp2;
extern char l_tri[3][102], l_tit[102]; //처음, 마지막, 여담(추신)
extern char l_ind[101][40], path[8];
extern time_t t; 
extern struct tm* monthandday;

//기능적 함수들
void beforeRand(int _t); //사전 시드 설정 작업, 0이면 시간 포함 시드 설정, 1이면 코드로 시드설정
void gotoxy(int _x,int _y); //gotoxy함수 
void sSleep(int _s); //잠시 쉬기
void cursorView(int _t); //커서 활성화 여부 (1이 보임, 0이 안 보임)

//문자열 관련 함수들
void removeEnter(char *sentence, int siz);
void eCoding(int _t, char sentence[], int siz, char end_char); //1일시 인코딩(변환) 0일시 디코딩(읽기)

//시간 관련 함수들
void time_land(int _f);    //시간 초기화
int time_vaild();          //시간 검증 함수

//콘솔-그래픽적 함수들
void draw_main(int _f);    //기본 편지 양식 작성
void draw_nletter(); //단순 속 내용물 초기화
void draw_letter();   //메인 편지 모양 쓰기
void draw_oletter();   //열린 편지 모양 쓰기
void draw_lletter();   //종속적, 열린 편지 모양에서 세로선
void draw_body();   //화면 출력 함수

//주요 구현 함수들
int home();
int lsearch(int _f);
int lread(int _f);
int lwrite();
int ltuto();
