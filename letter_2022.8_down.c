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
int letter_etimelimit[4] ={2022, 8, 28, 21}, letter_stimelimit[4] ={2022, 8, 28, 21}, letter_ntime[4]; //��ȿ�Ⱓ(��, ��, ��, ��) �Է�

int main(){
    system("chcp 949");
    system("cls");
    int i, j, k;
    int letter_mainc = 4; //���ܼ� �Է�
    char  *letter_main[4][8] = { { //1����
    " �� 2�ְ� �� �����̳��̱�?",
    "�� 2�ֶ�� �ð��� �ؿ� ���� 14�� �߰� �� �ð��̰�",
    "�̴߰� �� �������� �Ĵ� �ð��̸�",
    "�������� 2�б� �غ� ���� �ð��̿���",
    "��.. �� ������ �������Ĵµ� �ٽ� �ͼ��� ������������!",
    "��! �¾ƿ� ������ �� ���ƴ� ���װ� �̰ſ���!",
    "���ʿ� �׵θ� �� �ܰ�!",
    "�׷� ���������� �����غ�����"
    },{                              //2����
    " ������ �������! ���� �ٽ� ������ �����԰�, ������ ���鼭�� ���",
    "�ϱ��� �ϰ� �ٽ� ���� ����. ����� ��� ������������?",
    "������ �ϰ� 2~3�� ��, �߼����ް� �ִٴ� ���� �˰� �� �ʹ� ��� ������",
    "�ð��� �޸��� ��ƿԾ��! ��ŵ� �⻵�ϼ���������?",
    "��ɻ� ������.. ���簣���ѵ� ���� �� ���ֿ�! ����������! ��ä�� 65���ϴ�",
    "NYPC��� �Ϳ��� �����ôµ� 2���� ������ �������.. 100�� �����̶� �Ѵٸ� �ܿ� 14��!",
    "��ŵ� �߰��⸻�� ġ�� �ڵ嵵 ���̵�?�� ������ ¥�� �ְ�����?? �� ��ǧ �������־��!!!",
    "���� �� ���̵�� �����ϸ� ������ �ɰ� ������ ġ�鼭 �����̶� ���� �̷��.."
    },{                              //3����
    " �� ���� ������, gardener-in-trees�� ���� �Ź��ؿ�!",
    "������ ������ ��ó�� ȭ�п� �ɰ�, �� ȭ�п��� ������ ������ ¥��!",
    "��ġ ���̿��� ������ �̾Ƴ��� �� ���ƿ�",
    "������ ���� �ϰ�, ġ�⵵ �ϰ�, ������� �ٵ�������� �ٽ� ����������� ��������!",
    "�� ����������� �������� �Ƹ��ٿ����.. ���󿡳�",
    "������ ������ �ɰ� ���鸸 �������� �ǽð����� �ڶ����̾�..",
    "���� �� ���� ū ������ �̳������� �� ������ �������� �ɱ� ���� ��������..",
    "���� �� �� ���� ���� �ʳ���?"
    },{                              //4����
    " �� �׸��� ���� ���� ���� �������� �������� �Ƹ��ٿ����",
    "�ʹ� �⻼���! ���� ���� ����� �����ϴ� ������ ���ͼ�",
    "���� �� ������ �ܼ� �ʱⰡ �ƴϿ���..",
    "��ư, ���� ���Ⱑ ���� �����ߴ�ϴ�.",
    "������ �� �������� �Ǿ�����. �� �¾� �̷������� �ǽ������� �Ǳ⵵ �߾��!",
    "���� 3���̶��.. �ð��� �� �����׿� ������ �˾Ҵµ�. �� �׸��� �� ���!",
    "���� ���� ���� �ð��� �߰��Ǿ���ϴ�. ¥��! ���� ������ ���� �����ϱ��?",
    "�������� ���� �� �ְ� ������� ���� �����ϱ��?"
    } };
    char  *letter_top    = {"��������� ��¦�̴� ���� ���̴Բ�"};
    char  *letter_bottom = {"2022.08.28 ������ ���� ������ ������ ��� ������ �ø�"};
    char  *letter_ps     = {"�߽� : ���� ��� ----> then <- / lapping"};
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