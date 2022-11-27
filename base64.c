#include <stdio.h>
int main() {
    int siz, i, j, a; 
    scanf("%d %d", &siz, &a);
    char sentence[siz], sentence2[siz/3*4];
    for(i=0;i<siz;i++) {
        sentence[i]='\0';
        sentence2[i]='\0';
    }
    for(;getchar()!='\n';);
    if(a) fgets(sentence, siz+1, stdin);
    else fgets(sentence2, siz/3*4+1, stdin);
    for(i=0;i<siz/3*4+1&&!a;i++) {
        sentence2[i]-=65;
    } 
    if(a) {
        for(i=0, j=0;sentence[i]&&i<siz;i++) {
            switch(i%3) {
                case 0:
                    sentence2[j]=sentence[i]>>2;
                    sentence2[j+1]+=(sentence[i]%4)<<4;
                    j++;
                    break;
                case 1:
                    sentence2[j]+=sentence[i]/16;
                    sentence2[j+1]+=(sentence[i]%16)<<2;
                    j++;
                    break;
                case 2:
                    sentence2[j]+=sentence[i]/64;
                    sentence2[j+1]+=sentence[i]%64;
                    j+=2;
                    break;
                default:
                    break;
            }
        }
    }
    else {
        for(j=0, i=0;sentence2[j]&&j<(siz/3*4);j++) {
            switch(j%4) {
                case 0:
                    sentence[i]=(sentence2[j]%64)<<2;
                    i++;
                    break;
                case 1:
                    sentence[i-1]+=(sentence2[j]%64)/16;
                    sentence[i]=(sentence2[j]%16)<<4;
                    i++;
                    break;
                case 2:
                    sentence[i-1]+=(sentence2[j]%64)/4;
                    sentence[i]=(sentence2[j]%4)<<6;
                    i++;
                    break;
                case 3:
                    sentence[i-1]+=(sentence2[j])%64;
                    break;
                default:
                    break;
            }
        }
    }
    for(i=0;i<siz/3*4+1;i++) {
        sentence2[i]+=65;
    } 
    if(a) {
        for(i=0;i<siz/3*4;i++) {
            printf("%c", sentence2[i]);
        }
    }
    else {
        for(i=0;i<siz;i++) {
            printf("%c", sentence[i]);
        }
    }
}