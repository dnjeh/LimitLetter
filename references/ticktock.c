#include <stdio.h>
int l_lim[3][4] ={{2023, 1, 15, 14}, {2023, 2, 3, 3}, {2023, 1, 29, 20}};
int time_vaild() {                  //시간 검증 함수
    long long int l_vai[3];
    int bre=1, _t, _i;
    for(_i=0;_i<3;_i++) {
        l_vai[_i]=l_lim[_i][0]*365*24+l_lim[_i][2]*24+l_lim[_i][3];
        _t=l_lim[_i][1];
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
    printf("%d %d %d", l_vai[0], l_vai[1], l_vai[2]);
    if(l_vai[0]>=l_vai[2]&&l_vai[1]<=l_vai[2]) return 1;
    else return 0;
}
int main() { time_vaild(); }